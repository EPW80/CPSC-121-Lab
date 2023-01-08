#include <iomanip>
#include <iostream>
#include <string>

#include "cup.h"

int main() {
  std::string drink_name;
  double amount;
  char menu_input;

  std::cout << "What kind of drink can I get you?: ";
  std::getline(std::cin, drink_name);
  std::cout << "How much do you want to fill?: ";
  while (!(std::cin >> amount)) {
    // If the input is invalid, clear it, and ask again
    std::cin.clear();
    std::cin.ignore();
    std::cout << "Invalid input; please re-enter.\n";
  }
  Cup mug(drink_name, amount);

  while (true) {
    std::cout << "\n=== Your cup currently has " << mug.GetFluidOz()
              << " oz. of " << mug.GetDrinkType() << " === \n\n";
    std::cout << "Please select what you want to do with your drink/cup?:\n";
    std::cout << "D: Drink\n";
    std::cout << "R: Refill\n";
    std::cout << "N: Get a brand new drink\n";
    std::cout << "E: Empty\n";
    std::cout << "X: Exit\n";
    std::cout << "Selection: ";
    std::cin >> menu_input;
    std::cin.ignore();

    if (menu_input == 'X' || menu_input == 'x') {
      std::cout << "Thank you for using our cup!\n";
      break;
    }
    if (menu_input == 'D' || menu_input == 'd') {
      std::cout << "How much do you want to drink from the cup?: ";
      std::cin >> amount;
      std::cin.ignore();
      
      mug.Drink(amount);
      
    } else if (menu_input == 'R' || menu_input == 'r') {
      std::cout << "How much do you want to refill your cup?: ";
      std::cin >> amount;
      std::cin.ignore();
     
      mug.Refill(amount);
      
    } else if (menu_input == 'N' || menu_input == 'n') {
      std::cout << "What is the new drink you want?: ";
      std::getline(std::cin, drink_name);
      std::cout << "What is the amount you want?: ";
      std::cin >> amount;
      std::cin.ignore();
    
      mug.NewDrink(drink_name, amount);
      
    } else if (menu_input == 'E' || menu_input == 'e') {
      std::cout << "Emptying your cup\n";
     
      mug.Empty();
      
    } else {
      std::cout << "Invalid use of a cup!\n";
    }
  }
  return 0;
}