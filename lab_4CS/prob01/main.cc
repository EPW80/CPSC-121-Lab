#include <iostream>

#include "bubble.h"
#include "cpputils/graphics/image.h"

int main() {
  // Prompts the user for input to create the Bubble image.
  std::cout << "Tell me about your bubble.\n"
            << "Valid x, y and size are between 0 and 500.\n"
            << "Valid colors are red, orange, yellow, green, "
            << "teal, blue, and purple." << std::endl;

  std::string color;
  std::cout << "What color? ";
  std::cin >> color;

  int size;
  std::cout << "What size? ";
  std::cin >> size;

  int x;
  std::cout << "What x? ";
  std::cin >> x;

  int y;
  std::cout << "What y? ";
  std::cin >> y;

  // ========================== YOUR CODE HERE =============================
  // TODO: Instantiate a `Bubble` object into a variable called `my_bubble`.
  // Then, use the member functions to set color, size, and x, y coordinates
  // based on the user provided input retrieved above.

  Bubble my_bubble;
  my_bubble.SetX(x);
  my_bubble.SetY(y);
  my_bubble.SetSize(int(size));
  my_bubble.SetColor(std::string(color));
  // =======================================================================

  // Don't delete this!
  // This prints out your bubble to the terminal and also
  // draws it into an image you can view in "bubble.bmp".
  const int kImageSize = 500;
  graphics::Image image(kImageSize, kImageSize);
  if (image.DrawCircle(my_bubble.GetX(), my_bubble.GetY(), my_bubble.GetSize(),
                       my_bubble.GetColor()) &&
      image.SaveImageBmp("bubble.bmp")) {
    std::cout << my_bubble.ToString() << std::endl;
    std::cout << "Your bubble was saved to bubble.bmp" << std::endl;
  }
  return 0;
}
