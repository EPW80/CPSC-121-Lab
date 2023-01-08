#include <iostream>
#include <string>

#include "star.h"

int main() {
  int num = 0;
  std::cout << "How many stars? ";
  std::cin >> num;
  for (int i = 0; i < num; i++) {
    std::string name;
    double radius;
    std::cout << "Enter star 0's name: ";
    std::cin >> name;
    std::cout << "What is the solar radius? ";
    std::cin >> radius;
    Star S(name, radius);
    std::cout << "Created star " << S.GetName() << "\n";
  }

  // Write a loop to allow the user to create `num` stars.
  // Each iteration of the loop should ask the user for the
  // star's name and solar radius, and use that to construct
  //  a `Star` object. After you create the `Star`, print "Created star " with
  // its name, to announce the birth of a new star.

  return 0;
}
