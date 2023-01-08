#include "cup.h"

#include <iostream>
#include <string>

Cup::Cup() : drink_type_("Water"), fluid_oz_(16.0) {}
Cup::Cup(std::string name, double quantity)
    : drink_type_(name), fluid_oz_(quantity) {
  if (fluid_oz_ < 0) fluid_oz_ = 0;
}
void Cup::Drink(double amount) {
  fluid_oz_ -= amount;
  if (fluid_oz_ < 0) fluid_oz_ = 0;
}
void Cup::Refill(double amount) {
  fluid_oz_ += amount;
  if (fluid_oz_ < 0) fluid_oz_ = 0;
}
void Cup::NewDrink(std::string name, int amount) {
  drink_type_ = name;
  fluid_oz_ = amount;
  if (fluid_oz_ < 0) fluid_oz_ = 0;
}
void Cup::Empty() {
  fluid_oz_ = 0;
  drink_type_ = "nothing";
}
std::string Cup::GetDrinkType() { return drink_type_; }
double Cup::GetFluidOz() { return fluid_oz_; }