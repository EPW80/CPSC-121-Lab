#include "bubble.h"
#include <math.h>
double Bubble::CalculateVolume() {
  double PI = 3.1415;
  return (4 * PI * radius_ * radius_ * radius_) / 3;
}
Bubble CombineBubbles(Bubble const& other1, Bubble const& other2) {
  Bubble combined;
  combined.SetRadius(other1.GetRadius() + other2.GetRadius());
  return combined;
};
