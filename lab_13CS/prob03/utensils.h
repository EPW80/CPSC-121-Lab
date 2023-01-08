#include <iostream>
// ========================= YOUR CODE HERE =========================
// Define the Food, Utensil, and Spoon classes here.
// Refer to the README for instructions.
// ===================================================================
class Food {
 public:
  Food() {
    name_ = "Apple Pie";
    mass_ = 1000;
  }
  Food(std::string name, double mass) : name_(name), mass_(mass) {}
  std::string Name() {
    return name_;
  }
  void SetName(std::string name) {
    name_ = name;
  }
  double Mass() {
    return mass_;
  }
  void SetMass(double mass) {
    mass_ = mass;
  }
  void Eat(double eat) {
    mass_ -= eat;
    if (mass_ < 0) mass_ = 0;
  }
  void Print() {
    std::cout << name_ << " " << mass_ << "g\n";
  }

 private:
  std::string name_;
  double mass_;
};

class Utensil {
 public:
  Utensil() {
    size_ = 8.5;
    color_ = "silver";
  }
  Utensil(double size, std::string color) : size_(size), color_(color) {}
  double Size() {
    return size_;
  }
  void SetSize(double size) {
    size_ = size;
  }
  std::string Color() {
    return color_;
  }
  void SetColor(std::string color) {
    color_ = color;
  }
  void Use(Food &food) {}

 private:
  double size_;
  std::string color_;
};

class Spoon : public Utensil {
 public:
  Spoon() : Utensil(6, "silver") {
    bite_size_ = 25;
  };
  Spoon(double size, std::string color, double bite_size)
      : Utensil(size, color), bite_size_(bite_size){};
  double BiteSize() {
    return bite_size_;
  }
  void SetBiteSize(double bite_size) {
    bite_size_ = bite_size;
  }
  void Use(Food &food) {
    food.Eat(bite_size_);
  }

 private:
  double bite_size_;
};