#include <iomanip>
#include <iostream>

#include "utensils.h"

int main() {
  std::string name;
  std::string color;
  double mass;
  double size;
  double bite_size;

  std::cout << "Please enter the name of a food item: ";
  std::getline(std::cin, name);
  std::cout << "Please enter the mass of the food item: ";
  std::cin >> mass;
  // =================== YOUR CODE HERE ===================
  // 1. Create a Food object using the user's input.
  // =======================================================
  Food food(name, mass);

  std::cout << "Please enter the size of the spoon: ";
  std::cin >> size;
  std::cout << "Please enter the color of the spoon: ";
  std::cin.ignore();
  std::getline(std::cin, color);
  std::cout << "Please enter your bite size using the spoon: ";
  std::cin >> bite_size;
  // =================== YOUR CODE HERE ===================
  // 2. Create a Spoon object using the user's input.
  // =======================================================
  Spoon spoon(size, color, bite_size);

  std::cout << "Food before being eaten:\n";
  // =================== YOUR CODE HERE ===================
  // 3. Call the Food object's Print member function
  // =======================================================
  food.Print();

  std::cout << "Food after spoon used:\n";
  // =================== YOUR CODE HERE ===================
  // 4. Call the spoon object's use function and pass your
  // Food object as the argument.
  // =======================================================
  spoon.Use(food);

  // =================== YOUR CODE HERE ===================
  // 5. Call the Food object's Print member function again
  // =======================================================
  food.Print();
  return 0;
}
