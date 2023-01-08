#include <memory>
#include <string>

class Customer {
public:
  Customer();
  Customer(const std::string &name, int product_count,
           std::shared_ptr<Customer> next_customer)
      : name_(name), product_count_(product_count),
        next_customer_(next_customer) {}
  std::string GetName() const { return name_; }
  int GetProductCount() const { return product_count_; }
  std::shared_ptr<Customer> GetNextCustomer() const { return next_customer_; }
  int TotalCustomersInLine() {
    int total_number_of_customers_ = 1;
    if (next_customer_ == nullptr)
      return 1;
    else
      return 1 + next_customer_->TotalCustomersInLine();
  }
  int TotalProductsInLine() {
    int total_number_of_products_ = product_count_;
    if (next_customer_ == nullptr)
      return product_count_;
    else
      return product_count_ + next_customer_->TotalProductsInLine();
  }
  // ====================== YOUR CODE HERE ======================
  // 1. Define a constructor using member initializer list syntax
  //    according to the README.
  // 2. Define the accessor functions (i.e. the getter functions)
  //    `GetName`, `GetProductCount`, and `GetNextCustomer`.
  //    You do not need to create mutator functions (setters).
  // 3. Define the recursive functions specified in the README.
  // ============================================================
  std::string FirstAlphabeticalCustomerInLine() {
    if (next_customer_ == nullptr) {
      return name_;
    }
    if (name_ < next_customer_->FirstAlphabeticalCustomerInLine()) {
      return name_;
    } else {
      return next_customer_->FirstAlphabeticalCustomerInLine();
    }
  }

private:
  std::string name_;
  int product_count_;
  std::shared_ptr<Customer> next_customer_;
};
