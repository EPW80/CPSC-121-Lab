#include "salary.h"
#include <iomanip>
#include <iostream>

int main() {
  double hourly_wage;
  int hours_worked;

  std::cout << "Hourly wage: ";
  std::cin >> hourly_wage;
  std::cout << "Hours worked: ";
  std::cin >> hours_worked;

  if (hourly_wage < 1.0 || hours_worked < 1.0) {
    std::cout << "Invalid input";
  } else {
    double total_salary = calculateSalary(hours_worked, hourly_wage);
    std::cout << "Total Salary Owed: ";
    std::cout << std::setprecision(2) << std::fixed << total_salary;
  }
  return 0;
}
