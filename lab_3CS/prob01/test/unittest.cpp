#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "gtest_ext.h"

using ::testing::HasSubstr;

TEST(UserInput, AskMilitaryTime) {
  std::string user_input = "1433\n";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask for the military time.";
}

TEST(MilitaryToRegularTime, BeforeNoon) {
  std::string user_input = "845";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("8:45 am"))
      << "      Your program should convert the military time to "
      << "regular time. In this case, 8:45 am.";
}

TEST(MilitaryToRegularTime, BeforeNoonMinLessThanTen) {
  std::string user_input = "705";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("7:05 am"))
      << "      Your program should convert the military time to "
      << "regular time. In this case, 7:05 am.";
}

TEST(MilitaryToRegularTime, AfterNoon) {
  std::string user_input = "1334";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("1:34 pm"))
      << "      Your program should convert the military time to "
      << "regular time. In this case, 1:34 pm.";
}

TEST(MilitaryToRegularTime, AfterNoonMinLessThanTen) {
  std::string user_input = "1804";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("6:04 pm"))
      << "      Your program should convert the military time to "
      << "regular time. In this case, 6:04 pm.";
}

TEST(Driver, FunctionCall) {
  std::string user_input = "1823\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("6:23 pm"))
      << "      Your program should convert the military time to "
      << "regular time. In this case, 6:23pm.";
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
    return RUN_ALL_TESTS();
}
