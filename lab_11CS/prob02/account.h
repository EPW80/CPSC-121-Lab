#include <string>

class Account {
public:
  Account(const std::string &name, double balance)
      : account_holder_(name), balance_(balance) {}
  const std::string &GetAccountHolder() const { return account_holder_; }
  double GetBalance() const { return balance_; }

private:
  std::string account_holder_;
  double balance_;
};
