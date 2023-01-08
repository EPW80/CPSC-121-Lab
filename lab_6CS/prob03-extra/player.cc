```cpp
#include <iostream>

class Player {
private:
  int xpos_;
  int ypos_;
  std::string name_;
  int health_;
  int strength_;
  int defense_;

#include "player.h"
#include <iostream>

void Player::DisplayStat() {
  std::cout << "Player: " << name_ << "\n";
  std::cout << "Health: " << health_ << "\n";
  std::cout << "Strength: " << strength_ << "\n";
  std::cout << "Defense: " << defense_ << "\n";
  std::cout << "At position: (" << xpos_ << ", " << ypos_ << ")\n";
}

void Player::TakeDamage(int damage) {
  std::cout << name_ << " took " << damage << " damage\n";
  health_ -= damage;
  if (health_ < 0) {
    health_ = 0;
  }
  if (IsPlayerDead()) {
    std::cout << name_ << " is dead\n";
  }
}
