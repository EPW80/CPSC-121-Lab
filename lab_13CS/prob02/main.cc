#include <iostream>
#include <limits>
#include <map>

#include "astronaut.h"
#include "cpputils/graphics/image.h"
#include "crewmate.h"
#include "impostor.h"

const graphics::Color black(0, 0, 0);
const graphics::Color white(255, 255, 255);
// Colors for astronauts.
const graphics::Color red(255, 0, 0);
const graphics::Color orange(255, 125, 0);
const graphics::Color yellow(255, 255, 0);
const graphics::Color green(0, 255, 0);
const graphics::Color teal(0, 255, 255);
const graphics::Color blue(0, 0, 255);
const graphics::Color purple(125, 0, 255);
const graphics::Color pink(255, 0, 255);
// Colors in .bmp files that can be replaced to color astronauts.
const graphics::Color kMainColor(199, 17, 16);
const graphics::Color kShadowColor(119, 10, 10);
// Constants for drawing.
const int kAstronautSize = 55;
const int kFontSize = 16;
const int kBuffer = kFontSize * 3;
const int kImageWidth = kAstronautSize * 5;
// Constants relating to play.
const int kMaxPlayers = 10;
const int kMaxImpostors = 3;
// Draws an icon on the |image| with top left corner at (x, y), using the
// color and state of the Astronaut.
void DrawAstronautIcon(const Astronaut& astronaut, int x, int y,
                       graphics::Image& image) {
  graphics::Image icon;
  icon.Load(astronaut.GetIconFilename());
  graphics::Color color1 = astronaut.GetColor();
  graphics::Color color2(color1.Red() / 2, color1.Green() / 2,
                         color1.Blue() / 2);
  for (int i = 0; i < icon.GetWidth(); i++) {
    for (int j = 0; j < icon.GetHeight(); j++) {
      graphics::Color previous = icon.GetColor(i, j);
      if (previous == kMainColor) {
        image.SetColor(x + i, y + j, color1);
      } else if (previous == kShadowColor) {
        image.SetColor(x + i, y + j, color2);
      } else {
        image.SetColor(x + i, y + j, previous);
      }
    }
  }
}

// Draws a Crewmate astronaut on the |image| at (x, y). Includes name and
// completed task count.
void DrawAstronaut(const Crewmate& crewmate, int x, int y,
                   graphics::Image& image) {
  DrawAstronautIcon(crewmate, x, y, image);
  image.DrawText(x, y - kFontSize, crewmate.GetName(), kFontSize, black);
  image.DrawText(x, y - 2 * kFontSize,
                 std::to_string(crewmate.GetTaskCount()) + " tasks", kFontSize,
                 black);
  image.Show();
}

// Draws an Impostor astronaut on the |image| at (x, y). Includes name in
// red because it's an impostor.
void DrawAstronaut(const Impostor& impostor, int x, int y,
                   graphics::Image& image) {
  DrawAstronautIcon(impostor, x, y, image);
  image.DrawText(x, y - kFontSize, impostor.GetName(), kFontSize, red);
  image.Show();
}

int main() {
  // Create a map from strings to graphics::Color.
  std::map<std::string, graphics::Color> colors;
  colors["red"] = red;
  colors["orange"] = orange;
  colors["yellow"] = yellow;
  colors["green"] = green;
  colors["teal"] = teal;
  colors["blue"] = blue;
  colors["purple"] = purple;
  colors["pink"] = pink;
  colors["black"] = black;
  colors["white"] = white;

  std::map<std::string, Impostor> impostors;
  std::map<std::string, Crewmate> crewmates;

  int impostor_count;
  std::cout << "How many Impostors? (1, 2 or 3): ";
  std::cin >> impostor_count;
  if (impostor_count > kMaxImpostors || impostor_count < 1) {
    std::cout << "Invalid. Using 1 impostor." << std::endl;
    impostor_count = 1;
  }
  for (int i = 0; i < impostor_count; i++) {
    std::string name;
    std::string color;
    std::cout << "Enter impostor name: ";
    std::cin >> name;
    std::cout << "Enter color, valid colors are red, orange, yellow, green, "
                 "teal, blue, pink, purple, white, or black: ";
    std::cin >> color;

    Impostor impostor(name, colors[color]);
    impostors[name] = impostor;
  }

  int crewmate_count;
  int max_crewmates = kMaxPlayers - impostor_count;
  std::cout << "How many Crewmates? (between 1 and " << max_crewmates << "): ";
  std::cin >> crewmate_count;
  if (crewmate_count > max_crewmates || crewmate_count < 1) {
    std::cout << "Invalid. Using 1 crewmate." << std::endl;
    crewmate_count = 1;
  }
  for (int i = 0; i < crewmate_count; i++) {
    std::string name;
    std::string color;
    std::cout << "Enter crewmate name: ";
    std::cin >> name;
    std::cout << "Enter color, valid colors are red, orange, yellow, green, "
                 "teal, blue, pink, or purple: ";
    std::cin >> color;

    Crewmate crewmate(name, colors[color]);
    crewmates[name] = crewmate;
  }

  int target_task_count;
  std::cout << "How many total tasks must be done by the crewmates to win? ";
  std::cin >> target_task_count;

  int max_count =
      crewmate_count > impostor_count ? crewmate_count : impostor_count;
  int image_height = max_count * kAstronautSize + (max_count + 1) * kBuffer;
  graphics::Image image(kImageWidth, image_height);

  // Now interact with Astronauts in a loop until the game ends.
  while (true) {
    image.DrawRectangle(0, 0, kImageWidth, image_height, white);
    int count = 0;
    for (auto impostor : impostors) {
      DrawAstronaut(impostor.second, kAstronautSize * 3,
                    count * kAstronautSize + (count + 1) * kBuffer, image);
      count++;
    }
    count = 0;
    int dead_count = 0;
    int task_count = 0;
    for (auto crewmate : crewmates) {
      DrawAstronaut(crewmate.second, kAstronautSize,
                    count * kAstronautSize + (count + 1) * kBuffer, image);
      count++;
      if (!crewmate.second.GetIsAlive()) {
        dead_count++;
      }
      task_count += crewmate.second.GetTaskCount();
    }
    if (dead_count == crewmates.size()) {
      std::cout << "All crewmates are dead. Impostors win." << std::endl;
      image.ShowUntilClosed();
      break;
    } else if (task_count >= target_task_count) {
      std::cout << "Crewmates have completed " << task_count
                << " tasks, and win." << std::endl;
      image.ShowUntilClosed();
      break;
    }
    std::string name;
    std::cout << "Which astronaut do you want to use (or \"quit\" to quit)? ";
    std::cin >> name;
    if (name == "quit") {
      break;
    }
    if (impostors.find(name) != impostors.end()) {
      std::string target_name;
      std::cout << "Who do you want to kill? ";
      std::cin >> target_name;
      if (crewmates.find(target_name) != crewmates.end()) {
        if (crewmates[target_name].GetIsAlive()) {
          impostors[name].Kill(crewmates[target_name]);
        } else {
          std::cout << target_name << " is not alive." << std::endl;
        }
      } else {
        std::cout << "No crewmate found named " << target_name << std::endl;
      }
    } else if (crewmates.find(name) != crewmates.end()) {
      std::string task;
      std::cout << "What task do you want to do? ";
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::getline(std::cin, task);
      crewmates[name].DoTask(task);
    } else {
      std::cout << name << " not found." << std::endl;
    }
  }

  return 0;
}
