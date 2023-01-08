#include <iostream>

class Player {
private:
  int xpos_;
  int ypos_;
  std::string name_;
  int health_;
  int strength_;
  int defense_;

public:
  Player()
      : xpos_(0), ypos_(0), name_("Ash"), health_(10), strength_(5),
        defense_(2) {}
  Player(const std::string &name, int health, int strength, int defense,
         int xpos, int ypos)
      : xpos_(xpos), ypos_(ypos), name_(name), health_(health),
        strength_(strength), defense_(defense) {}

  int GetXpos() const { return xpos_; }
  void SetXpos(int xpos) { xpos_ = xpos; }
  int GetYpos() const { return ypos_; }
  void SetYpos(int ypos) { ypos_ = ypos; }
  std::string GetName() const { return name_; }
  void SetName(const std::string &name) { name_ = name; }
  int GetHealth() const { return health_; }
  void SetHealth(int health) { health_ = health; }
  int GetStrength() const { return strength_; }
  void SetStrength(int strength) { strength_ = strength; }
  int GetDefense() const { return defense_; }
  void SetDefense(int defense) { defense_ = defense; }

  void PlayerMove() {
    xpos_++;
    ypos_++;
  }
  bool IsPlayerDead() { return health_ == 0; }
  void DisplayStat();
  void TakeDamage(int damage);
};
