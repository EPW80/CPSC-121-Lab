class Rectangle {
public:
  // Setter functions of the Rectangle class.
  void SetLength(unsigned int length) { length_ = length; }
  void SetWidth(unsigned int width) { width_ = width; }

  // Getter functions of the Rectangle class.
  unsigned int GetLength() { return length_; }
  unsigned int GetWidth() { return width_; }

  // Other member functions of the Rectangle class.
  int Area();
  int Perimeter();

private:
  // Member variables of the Rectangle class.
  unsigned int length_;
  unsigned int width_;
};

Rectangle LargestRectangleByArea(Rectangle &Rectangle1, Rectangle &Rectangle2);
