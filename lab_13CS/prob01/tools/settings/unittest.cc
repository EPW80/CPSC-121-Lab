#include <gmock/gmock-matchers.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <memory>
#include <string>

#include "../../star.h"
#include "../cppaudit/gtest_ext.h"

using ::testing::HasSubstr;
using ::testing::Not;

TEST(StarTest, ConstructorPrintsStarName) {
  std::streambuf* original = std::cin.rdbuf();
  std::istringstream stream("n\n");
  std::cin.rdbuf(stream.rdbuf());

  std::streambuf* original_out = std::cout.rdbuf();
  std::stringstream stream_out;
  std::cout.rdbuf(stream_out.rdbuf());

  Star star("Bellatrix", 5.75);

  std::cin.rdbuf(original);
  std::cout.rdbuf(original_out);
  EXPECT_THAT(stream_out.str(), HasSubstr("Bellatrix was born"))
      << "    Star constructor should print out \"<star name> was born\" for "
         "the name given.";
}

TEST(StarTest, GetName) {
  Star star("Sun", 1);
  EXPECT_EQ(star.GetName(), "Sun") << "    GetName function should return the "
                                      "string passed in to the constructor.";
}

TEST(StarTest, DestructorPrintsVolumeRatio) {
  Star* star = new Star("Sun", 1);

  std::streambuf* original = std::cin.rdbuf();
  std::istringstream stream("n\n");
  std::cin.rdbuf(stream.rdbuf());

  std::streambuf* original_out = std::cout.rdbuf();
  std::stringstream stream_out;
  std::cout.rdbuf(stream_out.rdbuf());

  delete star;

  std::cin.rdbuf(original);
  std::cout.rdbuf(original_out);
  EXPECT_THAT(stream_out.str(), HasSubstr("Sun"))
      << "    Star destructor should print out the star's name.";
  EXPECT_THAT(stream_out.str(), HasSubstr("1.00 times"))
      << "    Star destructor should print out the relative volume of the "
         "star, "
         "for a star with solar radius 1 we should see 1.00. Use "
         "std::setprecision and std::fixed to format your output.";
}

TEST(StarTest, DestructorPrintsVolumeRatioWithFloatingPoints) {
  Star* star = new Star("Bellatrix", 5.75);

  std::streambuf* original = std::cin.rdbuf();
  std::istringstream stream("n\n");
  std::cin.rdbuf(stream.rdbuf());

  std::streambuf* original_out = std::cout.rdbuf();
  std::stringstream stream_out;
  std::cout.rdbuf(stream_out.rdbuf());

  delete star;

  std::cin.rdbuf(original);
  std::cout.rdbuf(original_out);
  EXPECT_THAT(stream_out.str(), HasSubstr("Bellatrix"))
      << "    Star destructor should print out the star's name.";
  EXPECT_THAT(stream_out.str(), HasSubstr("33.06 times"))
      << "    Star destructor should print out the relative volume of the "
         "star, "
         "for a star with solar radius 5.75 we should see 33.06. Use "
         "std::setprecision and std::fixed to format your output.";
}

TEST(MainTest, ExecutesAndExits) {
  std::string user_input = "0\n";
  ASSERT_EXECEXIT("main", user_input, 3)
      << "      Your program should ask for the number of stars, and return "
         "immediately if 0 is entered.";
}

TEST(MainTest, ExecutesWithOneStar) {
  std::string user_input = "1\nVega\n2.362";
  ASSERT_EXECEXIT("main", user_input, 3)
      << "      Your program should ask for the number of stars, and for each "
         "star ask for the name and solar radius.";
}

TEST(MainTest, ExecutesWithThreeStars) {
  std::string user_input = "3\nBetelgeuse\n887\nVega\n2.362\nRigel\n78.9\n";
  ASSERT_EXECEXIT("main", user_input, 3)
      << "      Your program should ask for the number of stars, and for each "
         "star ask for the name and solar radius.";
}

TEST(MainTest, StarGoesOutOfScope) {
  std::string user_input = "1\nBetelgeuse\n887\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input,
                    testing::MatchesRegex(".*Betelgeuse was born.*Created star "
                                          "Betelgeuse.*786769.00 times.*"))
        << "    Your program should ask the user for the number of stars, and "
           "then "
           "use a loop ask the user for each star's name and size, then create "
           "a "
           "Star object and print its name within the loop body.";
  })
}

TEST(MainTest, StarsGoOutOfScope) {
  std::string user_input =
      "4\nVega\n2.362\nRigel\n78.9\nSun\n1\nBetelgeuse\n887\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input,
                    testing::MatchesRegex(
                        ".*Vega was born.*Created star Vega.*5.5[78]+ times"
                        ".*Rigel was born.*Created star Rigel.*6225.21 times"
                        ".*Sun was born.*Created star Sun.*1.00 times.*"
                        ".*Betelgeuse was born.*Created star "
                        "Betelgeuse.*786769.00 times.*"))
        << "    Your program should ask the user for the number of stars, and "
           "then "
           "use a loop ask the user for each star's name and size, then create "
           "a "
           "Star object and print its name within the loop body.";
  })
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
