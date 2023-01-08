class Bubble {
 public:
  double GetRadius() const { return radius_; }
  void SetRadius(double const radius) { radius_ = radius; }
  double CalculateVolume();

 private:
  double radius_;
};
Bubble CombineBubbles(Bubble const& other1, Bubble const& other2);
