#include <string>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../cppaudit/gtest_ext.h"
#include "../../cpputils/graphics/test/image_test_utils.h"

using ::testing::HasSubstr;
using ::testing::MatchesRegex;

// Use UnitTestFileManager which renames any existing files
// during the test so they are not clobbered.
class BubbleImageTest : public UnitTestFileManager {
 public:
  BubbleImageTest() : UnitTestFileManager("bubble.bmp") {};

  bool FileCreated() {
    std::ifstream stream;
    stream.open(filename_);
    bool created = stream.good();
    stream.close();
    return created;
  }

  void CreateBubblesFromInput(std::string user_input) {
    ASSERT_EXECEXIT("main", user_input, 3)
        << "      Your program should ask the user how many bubbles they want to "
        << "make and then the color, size and location for each bubble. The "
        << "starter code should already do this, so if you see this message you "
        << "may have edited part of `main.cc` which you should revert.";
    EXPECT_TRUE(FileCreated()) << "Your program should save bubbles.bmp. "
        << "``main.cc`` should already do this so if you see this message you "
        << "may have made a change which you need to revert.";
  }
};

TEST_F(BubbleImageTest, ExecutesAndExits) {
  std::string user_input = "1\nblue\n10\n20\n20";
  CreateBubblesFromInput(user_input);
}

TEST_F(BubbleImageTest, CreatesSimpleBubble) {
  std::string diff_image = "expected_v_actual_CreatesSimpleBubble.bmp";
  remove(diff_image.c_str());

  std::string user_input = "blue\n30\n30\n30";
  CreateBubblesFromInput(user_input);
  graphics::Image actual;
  ASSERT_TRUE(actual.Load("bubble.bmp"));
  ASSERT_EQ(actual.GetWidth(), 500) << "Image should be 500 wide. Do not change kImageSize.";
  ASSERT_EQ(actual.GetWidth(), 500) << "Image should be 500 wide. Do not change kImageSize.";
  graphics::Image expected(500, 500);
  expected.DrawCircle(30, 30, 30, graphics::Color(0, 0, 255));

  bool match = ImagesMatch(&expected, &actual, diff_image,
      DiffType::kTypeSideBySide);
  EXPECT_TRUE(match) << "bubbles.bmp is not quite right for size 30, "
      << "x = 30 and y = 30. See " << diff_image;
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
