#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../cppaudit/gtest_ext.h"
#include "../../cpputils/graphics/test/image_test_utils.h"
#include "../../cpputils/graphics/image.h"
#include "../../robot.h"

using ::testing::HasSubstr;


// Test loading the same image twice

const graphics::Color kRed = graphics::Color(255, 0, 0);
const graphics::Color kBlue = graphics::Color(0, 0, 255);
const graphics::Color kGreen = graphics::Color(0, 255, 0);
const graphics::Color kWhite = graphics::Color(255, 255, 255);


void GenerateIcon(int width, int height, const graphics::Color& color,
  std::string filename) {
  graphics::Image image(width, height);
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      image.SetColor(i, j, color);
    }
  }
  image.SaveImageBmp(filename);
}

TEST(RobotTest, GetsAndSetsPosition) {
  Robot robot("file1.bmp", "file2.bmp");
  robot.SetPosition(5, 10);
  ASSERT_EQ(robot.GetX(), 5) << "    Robot::GetX() should return the value "
      "passed in the first parameter of Robot::SetPosition.";
  ASSERT_EQ(robot.GetY(), 10) << "    Robot::GetY() should return the value "
      "passed in the second parameter of Robot::SetPosition.";

  robot.SetPosition(42, 0);
  ASSERT_EQ(robot.GetX(), 42) << "    Robot::GetX() should return the value "
      "passed in the first parameter of Robot::SetPosition.";
  ASSERT_EQ(robot.GetY(), 0) << "    Robot::GetY() should return the value "
      "passed in the second parameter of Robot::SetPosition.";
}

TEST(RobotTest, Draws1x1IconAtTopLeft) {
  GenerateIcon(1, 1, kRed, "tools/output/icon.bmp");
  Robot robot("tools/output/icon.bmp", "tools/output/icon.bmp");
  robot.SetPosition(0, 0);

  // A 1 px icon centered at (0, 0) is just a pixel at (0, 0).
  graphics::Image image(2, 2);
  robot.Draw(image);
  ASSERT_EQ(image.GetColor(0, 0), kRed) << "   The robot should draw the icon "
      "at position (0, 0) when SetPosition was called with (0, 0) and the icon "
      "is 1x1 pixels.";
  EXPECT_EQ(image.GetColor(1, 0), kWhite) << "   The robot should not duplicate the icon.";
  EXPECT_EQ(image.GetColor(0, 1), kWhite) << "   The robot should not duplicate the icon.";
  EXPECT_EQ(image.GetColor(1, 1), kWhite) << "   The robot should not duplicate the icon.";
}

TEST(RobotTest, Draws1x1IconAtBottomRight) {
  GenerateIcon(1, 1, kRed, "tools/output/icon.bmp");
  Robot robot("tools/output/icon.bmp", "tools/output/icon.bmp");
  robot.SetPosition(1, 1);

  // A 1 px icon centered at (1, 1) is just a pixel at (1, 1).
  graphics::Image image(2, 2);
  robot.Draw(image);
  EXPECT_EQ(image.GetColor(1, 1), kRed) << "   The robot should draw the icon "
      "at position (1, 1) when SetPosition was called with (1, 1) and the icon "
      "is 1x1 pixels.";
  EXPECT_EQ(image.GetColor(1, 0), kWhite) << "   The robot should not duplicate the icon.";
  EXPECT_EQ(image.GetColor(0, 1), kWhite) << "   The robot should not duplicate the icon.";
  EXPECT_EQ(image.GetColor(0, 0), kWhite) << "   The robot should not duplicate the icon.";
}

TEST(RobotTest, AlternatesIcons) {
  GenerateIcon(1, 1, kRed, "tools/output/red.bmp");
  GenerateIcon(1, 1, kBlue, "tools/output/blue.bmp");
  Robot robot("tools/output/red.bmp", "tools/output/blue.bmp");
  robot.SetPosition(1, 0);
  graphics::Image image(2, 2);

  robot.Draw(image);
  ASSERT_EQ(image.GetColor(1, 0), kRed) << "   The robot should draw the icon "
      "from the constructor's first std::string parameter the first time Draw is "
      "called.";
  robot.Draw(image);
  ASSERT_EQ(image.GetColor(1, 0), kBlue) << "   The robot should draw the icon "
      "from the constructor's second std::string parameter the second time Draw is "
      "called.";
  robot.Draw(image);
  EXPECT_EQ(image.GetColor(1, 0), kRed) << "   The robot should draw the icon "
      "from the constructor's first std::string parameter the third time Draw is "
      "called.";
  robot.Draw(image);
  EXPECT_EQ(image.GetColor(1, 0), kBlue) << "   The robot should draw the icon "
      "from the constructor's second std::string parameter the fourth time Draw is "
          "called.";

  // Moving it shouldn't affect which is shown next.
  robot.SetPosition(0, 1);
  robot.Draw(image);
  EXPECT_EQ(image.GetColor(0, 1), kRed) << "   The robot should draw the icon "
      "from the constructor's first std::string parameter the fifth time Draw is "
      "called.";
  robot.Draw(image);
  EXPECT_EQ(image.GetColor(0, 1), kBlue) << "   The robot should draw the icon "
      "from the constructor's second std::string parameter the sixth time Draw is "
      "called.";
}

TEST(RobotTest, AlternatesIconsHundredsOfTimes) {
  // Ensure it is programatic by adding a very long loop.
  GenerateIcon(1, 1, kRed, "tools/output/red.bmp");
  GenerateIcon(1, 1, kBlue, "tools/output/blue.bmp");
  Robot robot("tools/output/blue.bmp", "tools/output/red.bmp");
  robot.SetPosition(1, 1);
  graphics::Image image(2, 2);
  for (int i = 0; i < 200; i++) {
    robot.Draw(image);
    ASSERT_EQ(image.GetColor(1, 1), kBlue) << "   The robot should draw the icon "
        "from the constructor's first std::string parameter every other time Draw is "
        "called, starting with the first time.";
    robot.Draw(image);
    ASSERT_EQ(image.GetColor(1, 1), kRed) << "   The robot should draw the icon "
        "from the constructor's second std::string parameter every other tmie Draw "
        "is called, starting with the second time.";
  }
}

TEST(RobotTest, Draws3x3PixelIconCentered) {
  std::string diff_image = "expected_vs_actual_Draws3x3PixelIconCentered.bmp";
  remove(diff_image.c_str());
  GenerateIcon(3, 3, kBlue, "tools/output/icon.bmp");
  Robot robot("tools/output/icon.bmp", "tools/output/icon.bmp");
  robot.SetPosition(2, 2);
  graphics::Image image(5, 5);
  robot.Draw(image);

  graphics::Image expected(5, 5);
  expected.DrawRectangle(1, 1, 3, 3, kBlue);
  bool match = ImagesMatch(&expected, &image, diff_image,
      DiffType::kTypeSideBySide);
  EXPECT_TRUE(match) << "Robot did not draw a 3x3 pixel icon centered at the "
      "position (2, 2). See " << diff_image;
}

TEST(RobotTest, IconWithMultipleColors) {
  std::string diff_image = "expected_vs_actual_IconWithMultipleColors.bmp";
  remove(diff_image.c_str());

  std::string filename = "tools/output/icon.bmp";
  graphics::Image icon(3, 1);
  icon.SetColor(0, 0, kRed);
  icon.SetColor(1, 0, kGreen);
  icon.SetColor(2, 0, kBlue);
  icon.SaveImageBmp(filename);
  Robot robot(filename, filename);
  robot.SetPosition(3, 2);

  graphics::Image image(6, 6);
  robot.Draw(image);

  graphics::Image expected(6, 6);
  expected.SetColor(2, 2, kRed);
  expected.SetColor(3, 2, kGreen);
  expected.SetColor(4, 2, kBlue);
  bool match = ImagesMatch(&expected, &image, diff_image,
      DiffType::kTypeSideBySide);
  EXPECT_TRUE(match) << "Robot did not draw a 3x1 pixel icon centered at the "
      "position (3, 2). See " << diff_image;
}

TEST(RobotTest, DrawsPartiallyOffscreenIcon) {
  std::string diff_image = "expected_vs_actual_DrawsPartiallyOffscreenIcon.bmp";
  remove(diff_image.c_str());
  GenerateIcon(3, 3, kRed, "tools/output/icon.bmp");
  Robot robot("tools/output/icon.bmp", "tools/output/icon.bmp");
  robot.SetPosition(0, 4);
  graphics::Image image(5, 5);
  robot.Draw(image);

  graphics::Image expected(5, 5);
  expected.DrawRectangle(0, 3, 2, 2, kRed);
  bool match = ImagesMatch(&expected, &image, diff_image,
      DiffType::kTypeSideBySide);
  EXPECT_TRUE(match) << "Robot did not draw a 3x3 pixel icon centered at the "
      "position (0, 4) (some pixels offscreen). See " << diff_image;
}

TEST(RobotTest, DoesNotDrawIconOffscreen) {
  std::streambuf* original = std::cin.rdbuf();
  std::istringstream stream("n\n");
  std::cin.rdbuf(stream.rdbuf());

  std::streambuf* original_out = std::cout.rdbuf();
  std::stringstream stream_out;
  std::cout.rdbuf(stream_out.rdbuf());

  GenerateIcon(1, 1, kRed, "tools/output/icon.bmp");
  Robot robot("tools/output/icon.bmp", "tools/output/icon.bmp");
  robot.SetPosition(10, 10);
  graphics::Image image(2, 2);
  robot.Draw(image);

  EXPECT_EQ(image.GetColor(0, 0), kWhite) << "   The robot should not change the image outside of the icon.";
  EXPECT_EQ(image.GetColor(1, 0), kWhite) << "   The robot should not change the image outside of the icon.";
  EXPECT_EQ(image.GetColor(0, 1), kWhite) << "   The robot should not change the image outside of the icon.";
  EXPECT_EQ(image.GetColor(0, 0), kWhite) << "   The robot should not change the image outside of the icon.";

  std::cin.rdbuf(original);
  std::cout.rdbuf(original_out);
  EXPECT_THAT(stream_out.str(), Not(HasSubstr("is out of bounds")))
      << "   The robot should not draw out of bounds of the graphics::Image passed in to Draw.";
}

TEST(RobotTest, ConstructorDoesNotDoWork) {
  // No work in the constructor, so we shouldn't see that these files fail
  // to load.
  std::streambuf* original = std::cin.rdbuf();
  std::istringstream stream("n\n");
  std::cin.rdbuf(stream.rdbuf());

  std::streambuf* original_out = std::cout.rdbuf();
  std::stringstream stream_out;
  std::cout.rdbuf(stream_out.rdbuf());

  Robot robot("file1.bmp", "file2.bmp");

  std::cin.rdbuf(original);
  std::cout.rdbuf(original_out);
  EXPECT_THAT(stream_out.str(), Not(HasSubstr("Failed to open image")))
      << "    You should not try to load an image file from the constructor. "
      "Save the filenames as member variables and load them later.";
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  bool skip = true;
  for (int i = 0; i < argc; i++)
  {
    if (std::string(argv[i]) == "--noskip")
    {
      skip = false;
    }
  }
  if (skip)
  {
    ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  }
  return RUN_ALL_TESTS();
}
