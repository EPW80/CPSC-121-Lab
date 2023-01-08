#include <iostream>
#include <string>

class Cup {
 public:
  Cup();
  Cup(std::string, double);
  void Drink(double amount);
  void Refill(double amount);
  void NewDrink(std::string, int);
  void Empty();

  std::string GetDrinkType();
  double GetFluidOz();

 private:
  std::string drink_type_;
  double fluid_oz_;
};