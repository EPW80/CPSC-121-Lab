#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "gtest_ext.h"

using ::testing::HasSubstr;
using ::testing::MatchesRegex;
using ::testing::Not;

TEST(UserInput, AskHeight) {
  std::string user_input = "60\n";
  ASSERT_EXECEXIT("main", user_input, 3) << "      Your program should ask for the passenger's height.";
}

TEST(Height, TallEnough) {
  std::string user_input = "72\n";
  ASSERT_EXECTHAT("main", user_input, Not(MatchesRegex(R"(.*(can't|not).*)")))
    << "      The passenger's height is above the minimum height so your program should tell the passenger that they can ride.";  
}

TEST(Height, TallEnoughEdge) {
  std::string user_input = "55\n";
  ASSERT_EXECTHAT("main", user_input, Not(MatchesRegex(R"(.*(can't|not).*)")))
    << "      The passenger's height is above the minimum height so your program should tell the passenger that they can ride.";  
}

TEST(Height, NotTallEnough) {
  std::string user_input = "30\n";
  ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"(.*(can't|not).*)"))
    << "      The passenger's height is below the minimum height so your program should tell the passenger that they cannot ride.";  
}

TEST(Height, NotTallEnoughEdge) {
  std::string user_input = "54\n";
  ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"(.*(can't|not).*)"))
    << "      The passenger's height is below the minimum height so your program should tell the passenger that they cannot ride.";    
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);    
    ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
    return RUN_ALL_TESTS();
}
