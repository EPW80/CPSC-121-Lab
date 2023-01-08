#include <string>
class Breed {
 public:
  Breed() : species_("Dog"), breed_name_("Chihuahua"), color_("Fawn") {}
  Breed(std::string species, std::string breed_name, std::string color)
      : species_(species), breed_name_(breed_name), color_(color) {}
  std::string Species() const { return species_; }
  std::string BreedName() const { return breed_name_; }
  std::string Color() const { return color_; }

  void SetSpecies(std::string species) { species_ = species; }
  void SetBreedName(std::string breed_name) { breed_name_ = breed_name; }
  void SetColor(std::string color) { color_ = color; }

 private:
  std::string species_;
  std::string breed_name_;
  std::string color_;
};
