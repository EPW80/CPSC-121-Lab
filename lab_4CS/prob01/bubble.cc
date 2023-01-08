#include "bubble.h"

#include <map>
#include <string>

void Bubble::SetX(int x) { x_ = x; }

void Bubble::SetY(int y) { y_ = y; }

void Bubble::SetSize(int size) { size_ = size; }

graphics::Color Bubble::GetColor() { return color_; }

int Bubble::GetX() { return x_; }

int Bubble::GetY() { return y_; }

int Bubble::GetSize() { return size_; }

void Bubble::SetColor(std::string color) {
  const int kMaxChannel = 255;
  const int kHalfChannel = 125;

  // Create a map from strings to graphics::Color.
  std::map<std::string, graphics::Color> colors;
  colors["red"] = graphics::Color(kMaxChannel, 0, 0);
  colors["orange"] = graphics::Color(kMaxChannel, kHalfChannel, 0);
  colors["yellow"] = graphics::Color(kMaxChannel, kMaxChannel, 0);
  colors["green"] = graphics::Color(0, kMaxChannel, 0);
  colors["teal"] = graphics::Color(0, kMaxChannel, kMaxChannel);
  colors["blue"] = graphics::Color(0, 0, kMaxChannel);
  colors["purple"] = graphics::Color(kHalfChannel, 0, kMaxChannel);

  if (colors.find(color) == colors.end()) {
    // Invalid color was passed in. Default to black.
    std::cout << "Invalid color: " << color << ". Defaulting to black."
              << std::endl;
    color_ = graphics::Color(0, 0, 0);
  } else {
    color_ = colors[color];
  }
}

std::string Bubble::ToString() {
  return "Bubble at (" + std::to_string(x_) + ", " + std::to_string(y_) +
         ") with size " + std::to_string(size_);
}
