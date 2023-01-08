#include "minimum.h"

int IndexOfMinimumElement(std::vector<double> input) {
  if (input.size() == 0)
    return -1;
  double minimumValue = input[0];
  int index = 0;
  for (int i = 1; i < input.size(); i++) {
    if (minimumValue > input[i]) {
      minimumValue = input[i];
      index = i;
    }
  }
  return index;
}
