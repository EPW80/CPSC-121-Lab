#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <vector>
#include "cppaudit/gtest_ext.h"
#include "../calculate_avg.h"

using ::testing::HasSubstr;

TEST(CalculateAverage, NoElement) {
  std::vector<double> unittest_vector(0);
  ASSERT_DURATION_LE(3, {
    ASSERT_DOUBLE_EQ(CalculateAverage(unittest_vector), 0);
  })
}

TEST(CalculateAverage, OneElement) {
  std::vector<double> unittest_vector(1);
  unittest_vector[0] = 1.5;
  ASSERT_DURATION_LE(3, {
    ASSERT_DOUBLE_EQ(CalculateAverage(unittest_vector), 1.5);
  })
}

TEST(CalculateAverage, MultipleElement) {
  std::vector<double> unittest_vector(3);
  unittest_vector[0] = 1.5;
  unittest_vector[1] = 2.5;
  unittest_vector[2] = 4.0;
    ASSERT_DURATION_LE(3, {
    ASSERT_DOUBLE_EQ(CalculateAverage(unittest_vector), 2.6666666666666665);
  })
}

TEST(CalculateAverage, MultipleElement2) {
  std::vector<double> unittest_vector(5);
  unittest_vector[0] = 1.5;
  unittest_vector[1] = 2.5;
  unittest_vector[2] = 4.0;
  unittest_vector[3] = 3.0;
  unittest_vector[4] = 3.5;
  ASSERT_DURATION_LE(3, {
    ASSERT_DOUBLE_EQ(CalculateAverage(unittest_vector), 2.9);
  })
}

TEST(UserInput, AskInput) {
  std::string user_input = "3\n3\n2\n4\n";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask for the number of students, in this case 3, and then the GPA for each student.";
}

TEST(Driver, NoClass) {
  std::string user_input = "0\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("no students"))
    << "      Your program should show an error message when the user inputs a class with no students.";
}

TEST(Driver, ClassAverage) {
  std::string user_input = "5\n3.8\n2.5\n4.0\n1.9\n3.6\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("3.16"))
    << "      Your program should display the correct average, 3.16.";
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
