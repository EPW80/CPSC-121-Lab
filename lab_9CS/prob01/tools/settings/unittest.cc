#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../../car.h"
#include "../cppaudit/gtest_ext.h"

using ::testing::HasSubstr;

TEST(Car, PublicMethodPresent) {
  VehicleId your_identifier;
  Date your_date;
  Car your_car1;
  Car your_car2(your_identifier);
  Car your_car3(your_date);
  Car your_car4(your_identifier, your_date);
  your_car1.Id();
  your_car1.SetId(your_identifier);
  your_car1.ReleaseDate();
  your_car1.SetReleaseDate(your_date);
}

TEST(CarClass, AccessorsAndMutators) {
  VehicleId unittest_identity("Ford", 1, "123456");
  Date unittest_date(28, 3, 1984);
  Car your_car;
  your_car.SetId(unittest_identity);
  your_car.SetReleaseDate(unittest_date);

  ASSERT_EQ((your_car.Id()).Model(), unittest_identity.Model())
    << "The car's VehicleId model should be Ford";
  ASSERT_EQ((your_car.Id()).Vin(), unittest_identity.Vin())
    << "The car's VehicleId VIN should be 1";
  ASSERT_EQ((your_car.Id()).LicensePlate(),
            unittest_identity.LicensePlate())
    << "The car's VehicleId license plate should be 123456";
  ASSERT_EQ((your_car.ReleaseDate()).Day(), unittest_date.Day())
    << "The car's release date day should be 28";
  ASSERT_EQ((your_car.ReleaseDate()).Month(), unittest_date.Month())
    << "The car's release date month should be 3";
  ASSERT_EQ((your_car.ReleaseDate()).Year(), unittest_date.Year())
    << "The car's release date year should be 1984";
}

TEST(CarClass, DefaultConstructor) {
  Car your_car;
  ASSERT_EQ((your_car.Id()).Model(), "Tesla")
    << "The car's VehicleId model should be Tesla";
  ASSERT_EQ((your_car.Id()).Vin(), 121)
    << "The car's VehicleId VIN should be 121";
  ASSERT_EQ((your_car.Id()).LicensePlate(), "TUFFY121L")
    << "The car's VehicleId license plate should be TUFFY121L";
  ASSERT_EQ((your_car.ReleaseDate()).Day(), 1)
    << "The car's release date day should be 1";
  ASSERT_EQ((your_car.ReleaseDate()).Month(), 1)
    << "The car's release date month should be 1";
  ASSERT_EQ((your_car.ReleaseDate()).Year(), 2022)
    << "The car's release date year should be 2022";
}

TEST(CarClass, NonDefaultVehicleIdConstructor) {
  VehicleId your_identifier("Honda", 3, "7B319X4");
  Car your_car(your_identifier);
  ASSERT_EQ((your_car.Id()).Model(), "Honda")
    << "The car's VehicleId model should be Honda";
  ASSERT_EQ((your_car.Id()).Vin(), 3)
    << "The car's VehicleId VIN should be 3";
  ASSERT_EQ((your_car.Id()).LicensePlate(), "7B319X4")
    << "The car's VehicleId license plate should be 7B319X4";
  ASSERT_EQ((your_car.ReleaseDate()).Day(), 1)
    << "The car's release date day should be 1";
  ASSERT_EQ((your_car.ReleaseDate()).Month(), 1)
    << "The car's release date month should be 1";
  ASSERT_EQ((your_car.ReleaseDate()).Year(), 2022)
    << "The car's release date year should be 2022";
}

TEST(CarClass, NonDefaultReleaseDateConstructor) {
  Date your_date(28, 3, 1984);
  Car your_car(your_date);

  ASSERT_EQ((your_car.Id()).Model(), "Tesla")
    << "The car's VehicleId model should be Tesla";
  ASSERT_EQ((your_car.Id()).Vin(), 121)
    << "The car's VehicleId VIN should be 121";
  ASSERT_EQ((your_car.Id()).LicensePlate(), "TUFFY121L")
    << "The car's VehicleId license plate should be TUFFY121L";
  ASSERT_EQ((your_car.ReleaseDate()).Day(), 28)
    << "The car's release date day should be 28";
  ASSERT_EQ((your_car.ReleaseDate()).Month(), 3)
    << "The car's release date month should be 3";
  ASSERT_EQ((your_car.ReleaseDate()).Year(), 1984)
    << "The car's release date year should be 1984";
}

TEST(CarClass, NonDefaultVehicleIdReleaseDateConstructor) {
  VehicleId your_identifier("Honda", 3, "7B319X4");
  Date your_date(28, 3, 1984);
  Car your_car(your_identifier, your_date);
  ASSERT_EQ((your_car.Id()).Model(), "Honda")
    << "The car's VehicleId model should be Honda";
  ASSERT_EQ((your_car.Id()).Vin(), 3)
    << "The car's VehicleId VIN should be 3";
  ASSERT_EQ((your_car.Id()).LicensePlate(), "7B319X4")
    << "The car's VehicleId license plate should be 7B319X4";
  ASSERT_EQ((your_car.ReleaseDate()).Day(), 28)
    << "The car's release date day should be 28";
  ASSERT_EQ((your_car.ReleaseDate()).Month(), 3)
    << "The car's release date month should be 3";
  ASSERT_EQ((your_car.ReleaseDate()).Year(), 1984)
    << "The car's release date year should be 1984";
}

TEST(CarClass, Print1) {
  SIMULATE_SIO("", {
    Car your_car(VehicleId("Subaru", 3, "6VFH322"), Date(31, 7, 2019));
    your_car.Print();
  }, {
    ASSERT_THAT(your_output, HasSubstr("Subaru"))
      << "The member function should print Subaru for the VehicleId model";
    ASSERT_THAT(your_output, HasSubstr("3"))
      << "The member function should print 3 for the VehicleId VIN";
    ASSERT_THAT(your_output, HasSubstr("6VFH322"))
      << "The member function should print 6VFH322 for the VehicleId license plate";
    ASSERT_THAT(your_output, HasSubstr("7/31/2019"))
      << "The member function should print 7/31/2019 for the release date";
  })
}

TEST(CarClass, Print2) {
  SIMULATE_SIO("", {
    Car your_car(VehicleId("Jeep", 6, "6WRT885"), Date(21, 2, 2017));
    your_car.Print();
  }, {
    ASSERT_THAT(your_output, HasSubstr("Jeep"))
      << "The member function should print Jeep for the VehicleId model";
    ASSERT_THAT(your_output, HasSubstr("6"))
      << "The member function should print 6 for the VehicleId VIN";
    ASSERT_THAT(your_output, HasSubstr("6WRT885"))
      << "The member function should print 6WRT885 for the VehicleId license plate";
    ASSERT_THAT(your_output, HasSubstr("2/21/2017"))
      << "The member function should print 2/21/2017 for the release date";
  })
}

TEST(Driver, Output) {
  std::string unittest_output =
      "The model of the car is: Tesla\nThe VIN of the car is: 121\nThe license "
      "plate of the car is: TUFFY121L\nThe release date of the car is: "
      "1/1/2022\n\nThe model of the car is: Honda\nThe VIN of the car is: 3\nThe "
      "license plate of the car is: 7B319X4\nThe release date of the car is: "
      "1/1/2022\n\nThe model of the car is: Tesla\nThe VIN of the car is: 121\nThe "
      "license plate of the car is: TUFFY121L\nThe release date of the car is: "
      "11/4/2018\n\nThe model of the car is: Honda\nThe VIN of the car is: "
      "3\nThe license plate of the car is: 7B319X4\nThe release date of the "
      "car is: 11/4/2018\n\nThe model of the car is: Tesla\nThe VIN of the car "
      "is: 121\nThe license plate of the car is: TUFFY121L\nThe release date of the "
      "car is: 1/1/2022\n";
  ASSERT_EXECEQ("main", "", unittest_output);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
