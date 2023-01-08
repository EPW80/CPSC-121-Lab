#include <string>

#include "cpputils/graphics/image.h"

class Robot {
 public:
  Robot(std::string filename1, std::string filename2);
  void SetPosition(int x, int y);
  int GetX();
  int GetY();
  void Draw(graphics::Image& image);

 private:
  void DrawIconOnImage(graphics::Image& icon, graphics::Image& image);
  std::string filename1_;
  std::string filename2_;
  graphics::Image icon1_;
  graphics::Image icon2_;
  graphics::Color color_;
  int x_ = 0;
  int y_ = 0;
  int mod_ = 0;
};
