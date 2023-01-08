#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../cppaudit/gtest_ext.h"

using ::testing::HasSubstr;

TEST(Driver, OutputShouldHaveSecretKeyFromReadMe) {
  ASSERT_EXECTHAT("main", "", HasSubstr("TUFFY121L")) << "Missing secret key. Make sure to read the README with your lab partner!";  
}


TEST(Driver, OutputShouldHaveLabPartnerName) {
  ASSERT_EXECTHAT("main", "", HasSubstr("name:")) << "Missing lab partner names.";  
}

TEST(Driver, OutputShouldHaveLabPartnerEmail) {
  ASSERT_EXECTHAT("main", "", HasSubstr("Email:")) << "Missing lab partner emails.";  
}

TEST(Driver, OutputShouldHaveLabPartnerGitHub) {
  ASSERT_EXECTHAT("main", "", HasSubstr("GitHub:")) << "Missing lab partner GitHub users.";  
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
