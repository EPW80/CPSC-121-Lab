#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "gtest_ext.h"

using ::testing::HasSubstr;

TEST(UserInput, AskHourlyWageAndHoursWorked) {
  std::string user_input = "25\n62\n";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask for the hourly wage and hours worked.";
}

TEST(UserInput, NegativeHourlyWage) {
	std::string user_input = "-10\n10\n";
	ASSERT_EXECTHAT("main", user_input, AnyOf(HasSubstr("invalid"), HasSubstr("Invalid")))
	<< "      Your program should inform the user that -10 is an invalid hourly wage.";
}

TEST(UserInput, NegativeHoursWorked) {
	std::string user_input = "13\n-5\n";
	ASSERT_EXECTHAT("main", user_input, AnyOf(HasSubstr("invalid"), HasSubstr("Invalid")))
	<< "      Your program should inform the user that -5 is an invalid hours worked.";
}

TEST(Salary, FourtyhrsOrLess) {
  std::string user_input = "25\n10\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("250.00"))
    << "      Your program should display $250.00, the salary for 40 hours or less of work.";  
}

TEST(Salary, FourtyhrsEdge) {
  std::string user_input = "25\n40\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("1000.00"))
    << "      Your program should display $1000.00, the salary for 40 hours or less of work.";  
}

TEST(Salary, SixtyFivehrsOrLess) {
  std::string user_input = "30\n50\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("1650.00"))
    << "      Your program should display $1650.00, the salary for over 40 hours, but less than or equal to 65 hours of work.";  
}

TEST(Salary, SixtyFivehrsOrLessEdge1) {
  std::string user_input = "30\n41\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("1245.00"))
    << "      Your program should display $1245.00, the salary for over 40 hours, but less than or equal to 65 hours of work.";  
}

TEST(Salary, SixtyFivehrsOrLessEdge2) {
  std::string user_input = "30\n65\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("2325.00"))
    << "      Your program should display $2325.00, the salary for over 40 hours, but less than or equal to 65 hours of work.";  
}

TEST(Salary, OverSixtyFiveHrs) {
  std::string user_input = "30\n70\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("2625.00"))
    << "      Your program should display $2625.00, the salary for over 65 hours of work.";  
}

TEST(Salary, OverSixtyFiveHrsEdge) {
  std::string user_input = "30\n66\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("2385.00"))
    << "      Your program should display $2385.00, the salary for over 65 hours of work.";  
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);    
    ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
    return RUN_ALL_TESTS();
}
