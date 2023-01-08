#include <string>

#include "cpputils/graphics/image.h"

class Bubble {
 public:
  // Member functions of the Bubble class.
  // These member functions are called "setters" or "setter functions"
  // because they SET the member variables to the given input.
  void SetX(int x);
  void SetY(int y);
  void SetSize(int size);
  void SetColor(std::string color);

  // These member functions are called "getters" or "getter functions"
  // because they GET, or return, the member variables to the given input.
  graphics::Color GetColor();
  int GetX();
  int GetY();
  int GetSize();
  std::string ToString();

 private:
  // Member variables of the Bubble class.
  int x_ = 0;
  int y_ = 0;
  int size_ = 0;
  graphics::Color color_;
};
