#include <iostream>
#include <map>
#include <vector>

#include "bank.h"

int main() {
  Bank racks_("Dame mi feria guey!");
  // =================== YOUR CODE HERE ===================
  // 1. Create a Bank object, name it anything you'd like :)
  // =======================================================
  int tuffy_id = racks_.CreateAccount("Tuffy", 121.00);
  int frank_id = racks_.CreateAccount("Frank", 1234.56);
  int oreo_id = racks_.CreateAccount("Oreo", 140.12);

  // =================== YOUR CODE HERE ===================
  // 2. Create 3 new accounts in your bank.
  //    * The 1st account should belong to "Tuffy", with
  //      a balance of $121.00
  //    * The 2nd account should belong to "Frank", with
  //      a balance of $1234.56
  //    * The 3nd account should belong to "Oreo", with
  //      a balance of $140.12
  // =======================================================
  racks_.DeactivateAccount(tuffy_id);

  // =================== YOUR CODE HERE ===================
  // 3. Deactivate Tuffy's account.
  // =======================================================
  racks_.DisplayBalances();

  // =================== YOUR CODE HERE ===================
  // 4. Call DisplayBalances to print out all *active*
  //    account balances.
  // =======================================================
}
