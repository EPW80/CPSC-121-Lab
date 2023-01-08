#include "robotclicklistener.h"

#include <iostream>
#include <memory>
#include <string>

const graphics::Color white(graphics::Color(255, 255, 255));
const double kAnimationRatio = 8;
const int kAnimationMs = 60;

using std::cin;
using std::cout;
using std::string;

void RobotClickListener::Start() {
  string filename1;
  string filename2;
  cout << "Enter a filename for the robot icon: ";
  cin >> filename1;
  cout << "Enter another filename for the robot icon: ";
  cin >> filename2;
  robot_ = std::make_unique<Robot>(filename1, filename2);

  image.Initialize(size, size);
  image.AddMouseEventListener(*this);
  image.AddAnimationEventListener(*this);

  robot_->SetPosition(last_x_, last_y_);
  robot_->Draw(image);
  image.ShowUntilClosed("Robot friend", kAnimationMs);
}

void RobotClickListener::OnMouseEvent(const graphics::MouseEvent& event) {
  // When the mouse moves or drags, update the mouse coordinates.
  if (event.GetMouseAction() == graphics::MouseAction::kMoved ||
      event.GetMouseAction() == graphics::MouseAction::kDragged) {
    last_x_ = event.GetX();
    last_y_ = event.GetY();
  }
}

void RobotClickListener::OnAnimationStep() {
  // Erase the image.
  // Maybe not the most efficient solution but works fine on this scale.
  image.DrawRectangle(0, 0, image.GetWidth(), image.GetHeight(), white);
  // Find the next robot point.
  int x = (last_x_ + robot_->GetX() * (kAnimationRatio - 1)) / kAnimationRatio;
  int y = (last_y_ + robot_->GetY() * (kAnimationRatio - 1)) / kAnimationRatio;
  // Move the robot.
  robot_->SetPosition(x, y);
  // Draw the robot.
  robot_->Draw(image);
  // Ensure the image is updated.
  image.Flush();
}
