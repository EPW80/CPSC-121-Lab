#include "rectangle.h"

int Rectangle::Area() {
  int area;
  area = length_ * width_;
  return area;
}
int Rectangle::Perimeter() {
  int perimeter;
  perimeter = 2 * (length_ + width_);
  return perimeter;
}

Rectangle LargestRectangleByArea(Rectangle &rectangle1, Rectangle &rectangle2) {
  int area1, area2;
  area1 = rectangle1.Area();
  area2 = rectangle2.Area();
  if (area1 > area2)
    return rectangle1;
  else
    return rectangle2;
}
