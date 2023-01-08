#include <gmock/gmock-matchers.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <memory>
#include <string>

#include "../../customer.h"
#include "../cppaudit/gtest_ext.h"

using ::testing::HasSubstr;
using ::testing::Not;

TEST(Customer, ConstructorPresent) {
  std::string name = "JC";
  int product_count = 50;
  Customer cust(name, product_count, nullptr);
}

TEST(Customer, GetterFunctionsPresent) {
  std::string name = "JC";
  int product_count = 50;
  Customer cust(name, product_count, nullptr);
  cust.GetName();
  cust.GetProductCount();
  cust.GetNextCustomer();
}

TEST(Customer, RecursiveFunctionsPresent) {
  std::string name = "JC";
  int product_count = 50;
  Customer cust(name, product_count, nullptr);
  cust.FirstAlphabeticalCustomerInLine();
  cust.TotalCustomersInLine();
  cust.TotalProductsInLine();
}

TEST(Customer, NonDefaultConstructorSetsMembers) {
  std::string name = "JC";
  int product_count = 50;
  std::shared_ptr<Customer> jc =
      std::make_shared<Customer>(name, product_count, nullptr);
  ASSERT_EQ(jc->GetName(), "JC")
      << "The non-default Customer constructor should set the customer's name";
  ASSERT_EQ(jc->GetProductCount(), 50)
      << "The non-default Customer constructor should set the customer's "
         "product count";
  name = "Paul";
  product_count = 2;
  std::shared_ptr<Customer> paul =
      std::make_shared<Customer>(name, product_count, jc);
  ASSERT_EQ(paul->GetName(), "Paul")
      << "The non-default Customer constructor should set the customer's name";
  ASSERT_EQ(paul->GetProductCount(), 2)
      << "The non-default Customer constructor should set the customer's "
         "product count";
  ASSERT_EQ(paul->GetNextCustomer(), jc)
      << "The non-default Customer constructor should set the customer's "
         "product count";
}

TEST(Customer, FirstAlphabeticalCustomerInLine) {
  std::shared_ptr<Customer> e = std::make_shared<Customer>("E", 5, nullptr);
  std::shared_ptr<Customer> d = std::make_shared<Customer>("D", 8, e);
  std::shared_ptr<Customer> c = std::make_shared<Customer>("C", 2, d);
  std::shared_ptr<Customer> b = std::make_shared<Customer>("B", 15, c);
  std::shared_ptr<Customer> a = std::make_shared<Customer>("A", 4, b);
  ASSERT_EQ(a->FirstAlphabeticalCustomerInLine(), "A")
      << "FirstAlphabeticalCustomerInLine should return the customer in "
         "line whose name comes first alphabetically (hint: you can compare "
         "strings with the `<` or `>` operators)";
}

TEST(Customer, FirstAlphabeticalCustomerInMiddleOfLine) {
  std::shared_ptr<Customer> cust4 =
      std::make_shared<Customer>("Elmo", 5, nullptr);
  std::shared_ptr<Customer> cust3 =
      std::make_shared<Customer>("Aaron", 8, cust4);
  std::shared_ptr<Customer> cust2 =
      std::make_shared<Customer>("Damian", 2, cust3);
  std::shared_ptr<Customer> cust1 =
      std::make_shared<Customer>("Belle", 15, cust2);
  ASSERT_EQ(cust1->FirstAlphabeticalCustomerInLine(), "Aaron")
      << "FirstAlphabeticalCustomerInLine should return the customer in "
         "line whose name comes first alphabetically (hint: you can compare "
         "strings with the `<` or `>` operators)";
}

TEST(Customer, TotalCustomersInLine) {
  std::shared_ptr<Customer> cust4 =
      std::make_shared<Customer>("Elmo", 5, nullptr);
  std::shared_ptr<Customer> cust3 =
      std::make_shared<Customer>("Aaron", 8, cust4);
  std::shared_ptr<Customer> cust2 =
      std::make_shared<Customer>("Damian", 2, cust3);
  std::shared_ptr<Customer> cust1 =
      std::make_shared<Customer>("Belle", 15, cust2);
  ASSERT_EQ(cust1->TotalCustomersInLine(), 4)
      << "TotalCustomersInLine should return the total number of customers in "
         "line beginning at the customer who's being asked.";
  ASSERT_EQ(cust4->TotalCustomersInLine(), 1)
      << "TotalCustomersInLine should return 1 if there's no next customer.";
}

TEST(Customer, TotalProductsInLine) {
  std::shared_ptr<Customer> cust4 =
      std::make_shared<Customer>("Elmo", 5, nullptr);
  std::shared_ptr<Customer> cust3 =
      std::make_shared<Customer>("Aaron", 8, cust4);
  std::shared_ptr<Customer> cust2 =
      std::make_shared<Customer>("Damian", 2, cust3);
  std::shared_ptr<Customer> cust1 =
      std::make_shared<Customer>("Belle", 15, cust2);
  ASSERT_EQ(cust1->TotalProductsInLine(), 30)
      << "TotalCustomersInLine should return the total number of products in "
         "line beginning at the customer who's being asked.";
}

TEST(Driver, OutputShouldPrintTotalCustomersInLine) {
  ASSERT_EXECTHAT("main", "", HasSubstr("Total customers waiting: 5"))
      << "Main should print the total number of customers waiting in line.";
}

TEST(Driver, OutputShouldPrintTotalProductsInLine) {
  ASSERT_EXECTHAT("main", "", HasSubstr("Total products to be purchased: 34"))
      << "Main should print the total number of products held by ALL customers "
         "in line.";
}

TEST(Driver, OutputShouldPrintFirstAlphabeticalCustomer) {
  ASSERT_EXECTHAT("main", "",
                  HasSubstr("First customer name alphabetically: Adele"))
      << "Main should print the customer name that comes first alphabetically.";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
