#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

class FoodPantry {
 public:
  FoodPantry(const std::string &name) : name_(name) {}
  FoodPantry(const std::string &name,
             const std::map<std::string, int> &products)
      : name_(name), products_(products) {}

  const std::string &GetName() const { return name_; }

  void Donate(const std::string &item, int quantity) {
    if (products_.count(item) == 0) {
      products_.insert({item, quantity});
    } else {
      products_.at(item) += quantity;
    }
  }

  void DisplayPantryItems() const {
    for (const std::pair<std::string, int> &pair : products_) {
      std::cout << pair.second << " " << pair.first << std::endl;
    }
  }

 private:
  std::string name_;
  std::map<std::string, int> products_;
};
