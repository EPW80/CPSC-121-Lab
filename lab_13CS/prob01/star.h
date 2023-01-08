#include <iomanip>
#include <iostream>
#include <string>

class Star {
public:
  Star(std::string name, double radius) : name_(name), radius_(radius) {
    std::cout << "The star " << name << " was born\n "
              << "Created star " << name << "\n";
  }
  ~Star() {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "The star " << name_ << " has gone supernova. It was "
              << (radius_ * radius_) << " times the volume of the sun.\n ";
  }
  std::string GetName() const { return name_; }

private:
  std::string name_;
  double radius_;
};
