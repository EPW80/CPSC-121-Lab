#include <iostream>
#include <memory>
#include <string>

#include "../cpputils/graphics/image.h"
#include "../robot.h"

using std::cin;
using std::cout;
using std::string;

const int size = 500;

class RobotClickListener : public graphics::MouseEventListener,
                           public graphics::AnimationEventListener {
 public:
  // Tear down.
  ~RobotClickListener() {
    image.RemoveMouseEventListener(*this);
    image.RemoveAnimationEventListener(*this);
  }

  // Set up
  void Start();

  void OnMouseEvent(const graphics::MouseEvent& event) override;

  void OnAnimationStep() override;

 private:
  std::unique_ptr<Robot> robot_;
  graphics::Image image;
  int last_x_ = size / 2;
  int last_y_ = size / 2;
};
