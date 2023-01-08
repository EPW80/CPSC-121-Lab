#include <iostream>

#include "rectangle.h"

int main() {
  Rectangle Rectangle1, Rectangle2;
  Rectangle Rectangle3;
  unsigned int length, width, area;
  std::cout << "====== Rectangle 1 ======" << std::endl;
  std::cout << "Please enter the length: ";
  std::cin >> length;
  Rectangle1.SetLength(length);
  std::cout << "Please enter the width: ";
  std::cin >> width;
  Rectangle1.SetWidth(width);
  std::cout << "Rectangle 1 created with length " << length << " and width "
            << width << std::endl;
  std::cout << "The area of Rectangle 1 is: " << Rectangle1.Area() << std::endl;
  std::cout << "The perimeter of Rectangle 1 is: " << Rectangle1.Perimeter()
            << "\n"
            << "\n";
  std::cout << "====== Rectangle 2 ======" << std::endl;
  std::cout << "Please enter the length: ";
  std::cin >> length;
  Rectangle2.SetLength(length);
  std::cout << "Please enter the width: ";
  std::cin >> width;
  Rectangle2.SetWidth(width);
  std::cout << "Rectangle 2 created with length " << length << " and width "
            << width << std::endl;
  std::cout << "The area of Rectangle 2 is: " << Rectangle2.Area() << std::endl;
  std::cout << "The perimeter of Rectangle 2 is: " << Rectangle2.Perimeter()
            << std::endl;
  // Find the area Rectangle with bigger Area
  Rectangle3 = LargestRectangleByArea(Rectangle1, Rectangle2);
  length = Rectangle3.GetLength();
  width = Rectangle3.GetWidth();
  area = length * width;
  std::cout << "The largest rectangle has a length of " << length
            << ", a width of " << width << ","
            << " and an area of " << area << ".";
  return 0;
}
