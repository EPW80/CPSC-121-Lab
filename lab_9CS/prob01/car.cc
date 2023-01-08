#include "car.h"
#include <iostream>
Car::Car() {}
Car::Car(VehicleId id) { id_ = id; }
Car::Car(Date release_date) { release_date_ = release_date; }
Car::Car(VehicleId id, Date release_date) {
  id_ = id;
  release_date_ = release_date;
}
VehicleId Car::Id() const { return id_; }
Date Car::ReleaseDate() const { return release_date_; }
void Car::SetId(VehicleId id) { id_ = id; }
void Car::SetReleaseDate(Date release_date) { release_date_ = release_date; }
void Car::Print() {
  std::cout << "The model of the car is: " << id_.Model() << std::endl;
  std::cout << "The VIN of the car is: " << id_.Vin() << std::endl;
  std::cout << "The license plate of the car is: " << id_.LicensePlate()
            << std::endl;
  std::cout << "The release date of the car is: " << release_date_.Month()
            << "/" << release_date_.Day() << "/" << release_date_.Year()
            << std::endl;
}
