#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "gtest_ext.h"

using ::testing::MatchesRegex;
using ::testing::HasSubstr;

TEST(UserInput, AskCreditScore) {
  std::string user_input = "800\n";
  ASSERT_EXECEXIT("main", user_input, 3) << "      Your program should ask for the customer's credit score.";
}

TEST(CreditCardApproval, Ineligible) {
  std::string user_input = "500\n";
  ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"(.*(((i|I)neligible)|cannot|not|can't).*)"))
    << "      Your program should tell the customer that they are ineligible for a Tuffy credit card because their credit score is below 580.";  
}

TEST(CreditCardApproval, IneligibleEdge1) {
  std::string user_input = "0\n";
  ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"(.*(((i|I)neligible)|cannot|not|can't).*)"))
    << "      Your program should tell the customer that they are ineligible for a Tuffy credit card because their credit score is below 580.";  
}

TEST(CreditCardApproval, IneligibleEdge2) {
  std::string user_input = "579\n";
  ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"(.*(((i|I)neligible)|cannot|not|can't).*)"))
    << "      Your program should tell the customer that they are ineligible for a Tuffy credit card because their credit score is below 580.";  
}

TEST(CreditCardApproval, Silver) {
  std::string user_input = "600\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("Silver"))
    << "      Your program should tell the customer that they are eligible for the Silver Tuffy credit card.";  
}

TEST(CreditCardApproval, SilverEdge1) {
  std::string user_input = "580\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("Silver"))
    << "      Your program should tell the customer that they are eligible for the Silver Tuffy credit card.";  
}

TEST(CreditCardApproval, SilverEdge2) {
  std::string user_input = "669\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("Silver"))
    << "      Your program should tell the customer that they are eligible for the Silver Tuffy credit card.";  
}

TEST(CreditCardApproval, Gold) {
  std::string user_input = "680\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("Gold"))
    << "      Your program should tell the customer that they are eligible for the Gold Tuffy credit card.";  
}

TEST(CreditCardApproval, GoldEdge1) {
  std::string user_input = "670\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("Gold"))
    << "      Your program should tell the customer that they are eligible for the Gold Tuffy credit card.";  
}

TEST(CreditCardApproval, GoldEdge2) {
  std::string user_input = "799\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("Gold"))
    << "      Your program should tell the customer that they are eligible for the Gold Tuffy credit card.";  
}

TEST(CreditCardApproval, Platinum) {
  std::string user_input = "820\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("Platinum"))
    << "      Your program should tell the customer that they are eligible for the Platinum Tuffy credit card.";  
}

TEST(CreditCardApproval, PlatinumEdge1) {
  std::string user_input = "800\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("Platinum"))
    << "      Your program should tell the customer that they are eligible for the Platinum Tuffy credit card.";  
}

TEST(CreditCardApproval, PlatinumEdge2) {
  std::string user_input = "850\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("Platinum"))
    << "      Your program should tell the customer that they are eligible for the Platinum Tuffy credit card.";  
}

TEST(CreditCardApproval, InvalidNegative) {
  std::string user_input = "-100\n";
  ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"(.*((i|I)nvalid).*)"))
    << "      Your program should tell the customer that a negative credit score is invalid.";  
}

TEST(CreditCardApproval, InvalidNegativeEdge) {
  std::string user_input = "-1\n";
  ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"(.*((i|I)nvalid).*)"))
    << "      Your program should tell the customer that a negative credit score is invalid.";  
}

TEST(CreditCardApproval, InvalidOver) {
  std::string user_input = "1000\n";
  ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"(.*((i|I)nvalid).*)"))
    << "      Your program should tell the customer that credit scores above 850 are invalid.";  
}

TEST(CreditCardApproval, InvalidOverEdge) {
  std::string user_input = "851\n";
  ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"(.*((i|I)nvalid).*)"))
    << "      Your program should tell the customer that credit scores above 850 are invalid.";  
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
