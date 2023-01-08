#include <gmock/gmock-matchers.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>

#include "../../bank.h"
#include "../cppaudit/gtest_ext.h"

using ::testing::HasSubstr;
using ::testing::Not;

TEST(Bank, PublicMethodPresent) {
  Bank bank("Fullerton Bank");
  bank.GetBankName();
  bank.GetAccounts();
  bank.DisplayBalances();
  bank.CreateAccount("Tuffy", 50.2);
  bank.TotalAccounts();
}

TEST(CarClass, AccessorFunctions) {
  Bank my_bank("CSUF Bank");
  ASSERT_EQ(my_bank.GetBankName(), "CSUF Bank")
      << "The Bank constructor should set the bank name";
  ASSERT_TRUE(my_bank.GetAccounts().size() == 0)
      << "The accounts map should be empty when a new bank is instantiated.";
}

TEST(Bank, CreateAccount) {
  Bank bank("Fullerton Bank");
  int jc_acct_id = bank.CreateAccount("JC", 2020.20);
  ASSERT_TRUE(bank.GetAccounts().size() == 1)
      << "The accounts map should be size 1 after CreateAccount is called "
         "once.";
  int paul_acct_id = bank.CreateAccount("Paul", 1000.50);
  ASSERT_TRUE(bank.GetAccounts().size() == 2)
      << "The accounts map should be size 2 after CreateAccount is called "
         "twice.";
}

TEST(Bank, CreateAccountStoresAccountsInAccountsMap) {
  Bank bank("Fullerton Bank");
  int jc_acct_id = bank.CreateAccount("JC", 2020.20);
  int paul_acct_id = bank.CreateAccount("Paul", 1000.50);
  Account jc_acct = bank.GetAccounts().at(jc_acct_id);
  ASSERT_EQ(jc_acct.GetAccountHolder(), "JC")
      << "CreateAccount should store an Account object with the given name";
  ASSERT_EQ(jc_acct.GetBalance(), 2020.20)
      << "CreateAccount should store an Account object with the given balance";
  Account paul_acct = bank.GetAccounts().at(paul_acct_id);
  ASSERT_EQ(paul_acct.GetAccountHolder(), "Paul")
      << "CreateAccount should store an Account object with the given name";
  ASSERT_EQ(paul_acct.GetBalance(), 1000.50)
      << "CreateAccount should store an Account object with the given balance";
}

TEST(Bank, TotalAccounts) {
  Bank bank("Fullerton Bank");
  bank.CreateAccount("JC", 2020.20);
  bank.CreateAccount("Paul", 1000.50);
  bank.CreateAccount("Bob", 500.23);
  ASSERT_EQ(bank.TotalAccounts(), 3)
      << "TotalAccounts should be 3 after calling CreateAccount 3 times";
}

TEST(Bank, DisplayBalances){SIMULATE_SIO(
    "",
    {
      Bank bank("Fullerton Bank");
      bank.CreateAccount("JC", 2020.22);
      bank.CreateAccount("Paul", 1000.55);
      bank.DisplayBalances();
    },
    {
      ASSERT_THAT(your_output, HasSubstr("JC"))
          << "The member function should print the account holder's name";
      ASSERT_THAT(your_output, HasSubstr("Paul"))
          << "The member function should print the account holder's name";
      ASSERT_THAT(your_output, HasSubstr("2020.22"))
          << "The member function should print the account balance";
      ASSERT_THAT(your_output, HasSubstr("1000.55"))
          << "The member function should print the account balance";
    })}

TEST(Bank, DeactivateAccount){SIMULATE_SIO(
    "",
    {
      Bank bank("Fullerton Bank");
      int acct_to_delete = bank.CreateAccount("JC", 2020.22);
      bank.CreateAccount("Paul", 1000.55);
      bank.DeactivateAccount(acct_to_delete);
      bank.DisplayBalances();
    },
    {
      ASSERT_THAT(your_output, Not(HasSubstr("JC")))
          << "The member function should not print a deactivated account "
             "holder's name";
      ASSERT_THAT(your_output, HasSubstr("Paul"))
          << "The member function should print the account holder's name";
      ASSERT_THAT(your_output, Not(HasSubstr("2020.22")))
          << "The member function should not print a deactivated account's "
             "balance";
      ASSERT_THAT(your_output, HasSubstr("1000.55"))
          << "The member function should print the account balance";
    })}

TEST(Driver, OutputShouldPrintAllActiveBankAccounts) {
  ASSERT_EXECTHAT("main", "", HasSubstr("Frank"))
      << "Main should print out the name of each active account.";
  ASSERT_EXECTHAT("main", "", HasSubstr("Oreo"))
      << "Main should print out the name of each active account.";
  ASSERT_EXECTHAT("main", "", HasSubstr("140.12"))
      << "Main should print out the balances of each active account.";
  ASSERT_EXECTHAT("main", "", HasSubstr("1234.56"))
      << "Main should print out the balances of each active account.";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
