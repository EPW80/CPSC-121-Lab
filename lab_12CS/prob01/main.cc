#include <iostream>
#include <memory>

#include "customer.h"

int main() {
  // Creates a line of customers with Adele at the front.
  // LinkedList diagram:
  //   Adele -> Kehlani -> Giveon -> Drake -> Ruel
  std::shared_ptr<Customer> ruel =
      std::make_shared<Customer>("Ruel", 5, nullptr);
  std::shared_ptr<Customer> drake =
      std::make_shared<Customer>("Drake", 8, ruel);
  std::shared_ptr<Customer> giveon =
      std::make_shared<Customer>("Giveon", 2, drake);
  std::shared_ptr<Customer> kehlani =
      std::make_shared<Customer>("Kehlani", 15, giveon);
  std::shared_ptr<Customer> adele =
      std::make_shared<Customer>("Adele", 4, kehlani);

  std::cout << "Total customers waiting: ";
  // =================== YOUR CODE HERE ===================
  // 1. Print out the total number of customers waiting
  //    in line by invoking TotalCustomersInLine.
  // ======================================================
  std::cout << adele->TotalCustomersInLine() << std::endl;
  std::cout << "Total products to be purchased: ";
  // =================== YOUR CODE HERE ===================
  // 2. Print out the total number of products held by
  //    customers in line by invoking TotalProductsInLine.
  // ======================================================
  std::cout << adele->TotalProductsInLine() << std::endl;
  std::cout << "First customer name alphabetically: ";
  // =================== YOUR CODE HERE ===================
  // 3. Print out the name of the customer in line whose
  //    name comes first alphabetically by invoking
  //    FirstAlphabeticalCustomerInLine.
  // ======================================================
  std::cout << adele->FirstAlphabeticalCustomerInLine() << std::endl;
  return 0;
}
