#include <iomanip>
#include <iostream>
#include "bubble.h"
int main() {
  Bubble bubble1;
  Bubble bubble2;
  double radius1, radius2;
  std::cout << "Please enter the radius of the first bubble: ";
  std::cin >> radius1;
  bubble1.SetRadius(radius1);
  std::cout << "Please enter the radius of the second bubble: ";
  std::cin >> radius2;
  bubble2.SetRadius(radius2);
  Bubble combined = CombineBubbles(bubble1, bubble2);
  double volume;
  volume = combined.CalculateVolume();
  std::cout
      << "The bubbles have now combined and created a bubble with the volume "
         "of: "
      << std::fixed << std::setprecision(2) << volume << std::endl;
  return 0;
}
