#include <iostream>
#include <memory>

#include "foodpantry.h"
#include "volunteer.h"

std::shared_ptr<FoodPantry> CreatePantry(const std::string &pantry_name) {
  return std::make_shared<FoodPantry>(pantry_name);
}

int main() {
  Volunteer jc("JC");
  Volunteer paul("Paul");
  std::shared_ptr<FoodPantry> tuffys_pantry = CreatePantry("Tuffy's Pantry");
  std::cout << tuffys_pantry.use_count() << std::endl;
  jc.AssignToPantry(tuffys_pantry);
  paul.AssignToPantry(tuffys_pantry);
  std::cout << tuffys_pantry.use_count() << std::endl;
  jc.AssignedPantry()->Donate("Mango", 5);
  paul.AssignedPantry()->Donate("Mango", 20);
  tuffys_pantry->DisplayPantryItems();
  std::shared_ptr<FoodPantry> jc_pantry = CreatePantry("JC's Pantry");
  std::shared_ptr<FoodPantry> paul_pantry = CreatePantry("Paul's Pantry");
  jc.AssignToPantry(jc_pantry);
  paul.AssignToPantry(paul_pantry);
  std::cout << tuffys_pantry.use_count() << std::endl;
  tuffys_pantry = nullptr;
  std::cout << tuffys_pantry.use_count() << std::endl;
  std::cout << "TUFFY121L" << std::endl;
  std::cout << "Erik Williams:" << std::endl;
  std::cout << "epwilliams@csu.fullerton.edu:" << std::endl;
  std::cout << "GitHub: EPW80" << std::endl;
  std::cout << "Lab partner 2 name: Ian Chang" << std::endl;
  std::cout << "Email: ianchang@csu.fulleton.edu" << std::endl;
  std::cout << "GitHub: EatYoVeggiez" << std::endl;
  std::cout << "Usman Akhtar:" << std::endl;
  std::cout << "uakhtar19@csu.fullerton.edu:" << std::endl;
  std::cout << "Usman1919:" << std::endl;
}
