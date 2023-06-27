#include "time_converter.h"
#include <iostream>

int main()
{
  int military_time;
  std::cout << "Please enter the time in military time: ";
  std::cin >> military_time;
  std::string regular_time;
  regular_time = MilitaryToRegularTime(military_time);
  std::cout << "The equivalent regular time is: " << regular_time;
  return 0;
}