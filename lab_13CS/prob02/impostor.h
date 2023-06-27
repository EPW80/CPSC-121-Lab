#include "astronaut.h"
#include "crewmate.h"

// These header guards are necessary to keep your class from being defined
// multiple times when it is included from multiple files.
#ifndef IMPOSTOR_H
#define IMPOSTOR_H

class Impostor : public Astronaut {
 public:
  Impostor(std::string name, graphics::Color color) : Astronaut(name, color) {}
  Impostor() : Astronaut("no name", graphics::Color(0, 0, 0)) {}
  void Kill(Crewmate& kill) {
    std::cout << Astronaut::GetName() << " killed " << kill.GetName();
    kill.SetIsAlive(false);
  }
};

// ========================= YOUR CODE HERE =========================
// Define the Impostor class here, which inherits from the Astronaut
// base class. Refer to the README for instructions.
// ===================================================================

#endif  // IMPOSTOR_H
