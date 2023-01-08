#include "astronaut.h"

// These header guards are necessary to keep your class from being defined
// multiple times when it is included from multiple files.
#ifndef CREWMATE_H
#define CREWMATE_H

// ========================= YOUR CODE HERE =========================
// Define the Crewmate class here, which inherits from the Astronaut
// base class. Refer to the README for instructions.
// ===================================================================
class Crewmate : public Astronaut {
 public:
  Crewmate() : Astronaut("no name", graphics::Color(0, 0, 0)) {}
  Crewmate(std::string name, graphics::Color color)
      : Astronaut(name, color), alive_(true), task_count_(0) {}
  bool GetIsAlive() const {
    return alive_;
  }
  void SetIsAlive(bool alive) {
    alive_ = alive;
  }
  const int GetTaskCount() const {
    return task_count_;
  }
  int DoTask(std::string do_task) {
    task_count_ = task_count_ + 1;
    std::cout << GetName() << " is doing " << do_task;
    return task_count_;
  }
  const graphics::Color GetColor() const {
    if (alive_ == true) {
      return Astronaut::GetColor();
    }
    return graphics::Color((Astronaut::GetColor().Red() + 256) / 2,
                           (Astronaut::GetColor().Green() + 256) / 2,
                           (Astronaut::GetColor().Blue() + 256) / 2);
  }
  const std::string GetIconFilename() const {
    if (alive_ == true) {
      return Astronaut::GetIconFilename();
    }
    return "ghost.bmp";
  }

 private:
  bool alive_ = true;
  int task_count_ = 0;
};

#endif  // CREWMATE_H
