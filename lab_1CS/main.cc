#include <iostream> // standard header library
#include <iomanip>  // library for setprecision

int main() // begin main program
{

    double meal_cost, taxes, tip_percent, tip, sub_total, total_amount; // declare variables as float type

    std::cout << "Please input meal cost: "; // ask user for data

    std::cin >> meal_cost; // input data

    std::cout << "Please input tip percentage: "; // ask user for data

    std::cin >> tip_percent; // input data

    sub_total = meal_cost; // meal_cost data stored in sub_total

    taxes = sub_total * (7.5 / 100); // calculate tax and store data in taxes variable

    tip = meal_cost * (tip_percent / 100); // calculate tip and store data in tip variable

    total_amount = sub_total + taxes + tip; // calculate total amount and store data in total_amount variable

    std::cout << std::fixed << std::setprecision(2) << std::endl; // set precision set to 2 decimal places

    std::cout << "Restaurant Bill" << std::endl; // print to user

    std::cout << "====================" << std::endl; // ====...

    std::cout << "Subtotal: $" << sub_total << std::endl; // print sub total to user

    std::cout << "Taxes: $" << taxes << std::endl; // print tax to user

    std::cout << "Tip: $" << tip << std::endl; // print tip to user

    std::cout << "====================" << std::endl; // ====...

    std::cout << "Total: $" << total_amount << std::endl; // print total amount to user

    return 0;

    // end of main
}