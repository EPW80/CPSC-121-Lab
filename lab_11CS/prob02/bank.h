#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <memory>
#include <string>

#include "account.h"

class Bank {
public:
  Bank();
  Bank(const std::string &name) : bank_name_(name) {}
  std::string GetBankName() const { return bank_name_; }
  std::map<int, Account> GetAccounts() const { return accounts_; }
  int CreateAccount(const std::string &name, double balance) {
    Account new_account_(name, balance);
    int ID = GenerateAccountId();
    accounts_.insert({ID, new_account_});
    return ID;
  }
  int TotalAccounts() { return accounts_.size(); }
  void DisplayBalances() {
    for (std::map<int, Account>::iterator it = accounts_.begin();
         it != accounts_.end(); it++) {
      std::cout << it->second.GetAccountHolder() << ": $"
                << it->second.GetBalance() << "\n";
    }
  }
  void DeactivateAccount(int ID) {
    std::map<int, Account>::iterator it = accounts_.find(ID);
    accounts_.erase(it);
  }

private:
  std::string bank_name_;
  std::map<int, Account> accounts_;
  int GenerateAccountId() const {
    return std::rand() % 9000 + 1000; // [1000, 9999]
  }
};
