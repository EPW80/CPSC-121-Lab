#include <stdlib.h>
#include <time.h>

#include "dice.h"

// You do not need to edit this file.
int main() {
  // Initialize random number generator. The tests initialize with srand(0)
  // which you can try if you want to have the same state as the test.
  srand(time(nullptr));

  // Start playing.
  PlayYahtzee();
  return 0;
}
