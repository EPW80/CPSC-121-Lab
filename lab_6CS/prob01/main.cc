#include "robotutils/robotclicklistener.h"

//
// You do not need to edit this file.
//

// Helper function to create robot*.bmp. Feel free to make your own
// icons and use this for inspiration.
/*
void CreateRobotIcon() {
  graphics::Image image(31, 31);
  // Arms
  image.DrawLine(0, 10, 10, 15, 109, 131, 161, 6);
  image.DrawLine(30, 10, 10, 15, 109, 131, 161, 6);
  // Legs
  image.DrawLine(10, 15, 10, 30, 109, 131, 161, 6);
  image.DrawLine(20, 15, 20, 30, 109, 131, 161, 6);
  // Body
  image.DrawRectangle(5, 0, 20, 22, 130, 151, 179);
  // Eyes
  image.DrawCircle(10, 8, 2, 255, 255, 255);
  image.DrawCircle(20, 8, 2, 255, 255, 255);
  image.DrawCircle(9, 8, 2, 62, 66, 71);
  image.DrawCircle(19, 8, 2, 62, 66, 71);
  image.SaveImageBmp("robot.bmp");
}
*/

int main() {
  RobotClickListener listener;
  listener.Start();
  return 0;
}
