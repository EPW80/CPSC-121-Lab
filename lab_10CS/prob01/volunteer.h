#include <iostream>
#include <memory>

#include "foodpantry.h"

class Volunteer {
 public:
  Volunteer(const std::string &name) : name_(name) {}
  Volunteer(const std::string &name, std::shared_ptr<FoodPantry> pantry)
      : name_(name), pantry_(pantry) {}

  void AssignToPantry(std::shared_ptr<FoodPantry> pantry) {
    std::cout << "Assigned " << name_ << " to " << pantry->GetName()
              << std::endl;
    pantry_ = pantry;
  }

  void Unassign(std::shared_ptr<FoodPantry> pantry) { pantry_ = nullptr; }

  const std::shared_ptr<FoodPantry> AssignedPantry() const { return pantry_; }

 private:
  std::string name_;
  std::shared_ptr<FoodPantry> pantry_;
};
