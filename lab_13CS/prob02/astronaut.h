#include <string>

#include "cpputils/graphics/image.h"

// These header guards are necessary to keep your class from being defined
// multiple times when it is included from multiple files.
#ifndef ASTRONAUT_H
#define ASTRONAUT_H

// ========================= YOUR CODE HERE =========================
// Define the Astronaut class here. Refer to the README for instructions.
// ===================================================================
class Astronaut {
 public:
  Astronaut(std::string name, graphics::Color color)
      : name_(name), color_(color) {}
  const std::string GetName() const {
    return name_;
  }
  const graphics::Color GetColor() const {
    return color_;
  }
  const std::string GetIconFilename() const {
    return "astronaut.bmp";
  }

 private:
  std::string name_;
  graphics::Color color_;
};

#endif  // ASTRONAUT_H
