#include <iostream>

#include "car.h"
int main() {
  Car c1;
  c1.Print();
  std::cout << "\n";
  VehicleId identity1("Honda", 3, "7B319X4");
  Car c2(identity1);
  c2.Print();
  std::cout << "\n";
  Date date1(04, 11, 2018);
  Car c3(date1);
  c3.Print();
  std::cout << "\n";
  Car c4(identity1, date1);
  c4.Print();
  std::cout << "\n";
  VehicleId identity2;
  Date date2;
  c4.SetId(identity2);
  c4.SetReleaseDate(date2);
  c4.Print();
  return 0;
}
