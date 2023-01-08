#include <iostream>
#include <string>
#include "breed.h"
class Pet {
 public:
  Pet() : name_("Cookie"), weight_(15.6) {}
  Pet(const std::string name, const Breed breed, const double weight)
      : name_(name), breed_(breed), weight_(weight) {}
  Pet(const std::string name, const std::string breed, std::string breed_name,
      std::string color, const double weight)
      : name_(name), breed_(breed, breed_name, color), weight_(weight) {}
  std::string Name() const { return name_; }
  void SetName(std::string name) { name_ = name; }
  Breed GetBreed() const { return breed_; }
  void SetBreed(Breed &breed) { breed_ = breed; }
  void SetBreed(std::string species, std::string breed_name,
                std::string color) {
    Breed breed(species, breed_name, color);
    breed_ = breed;
  }
  double Weight() const { return weight_; }
  double SetWeight(double weight) {
    weight_ = weight;
    return weight_;
  }
  void Print() {
    std::cout << "Name: " << name_ << "\n";
    std::cout << "Species: " << breed_.Species() << "\n";
    std::cout << "Breed: " << breed_.BreedName() << "\n";
    std::cout << "Color: " << breed_.Color() << "\n";
    std::cout << "Weight: " << weight_ << "\n";
  }

 private:
  std::string name_;
  Breed breed_;
  double weight_;
};
