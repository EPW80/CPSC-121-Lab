#include "date.h"
#include "vehicleid.h"
class Car {
 private:
  VehicleId id_;
  Date release_date_;

 public:
  Car();
  Car(VehicleId id);
  Car(Date release_date);
  Car(VehicleId id, Date release_date);
  VehicleId Id() const;
  Date ReleaseDate() const;
  void SetId(VehicleId id);
  void SetReleaseDate(Date release_date);
  void Print();
};
