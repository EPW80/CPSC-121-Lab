#include <gmock/gmock-matchers.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>

#include "../../plane.h"
#include "../cppaudit/gtest_ext.h"

using ::testing::HasSubstr;
using ::testing::Not;

TEST(Driver, OutputShouldPrintAllWeightsInVector) {
  ASSERT_EXECTHAT("main", "", HasSubstr("3.2 4.7 2.1 5.5 9.8 7.4 1.6 9.3"))
      << "Main should print all weights in the weights vector.";
}

TEST(Driver, OutputShouldPrintAllStatePopulations) {
  ASSERT_EXECTHAT("main", "", HasSubstr("Alabama: 5.1 million"))
      << "Main should print out the full state name and its population.";
  ASSERT_EXECTHAT("main", "", HasSubstr("California: 39.2 million"))
      << "Main should print out the full state name and its population.";
  ASSERT_EXECTHAT("main", "", HasSubstr("Georgia: 10.8 million"))
      << "Main should print out the full state name and its population.";
  ASSERT_EXECTHAT("main", "", HasSubstr("Texas: 29.5 million"))
      << "Main should print out the full state name and its population.";
}

TEST(Plane, DefaultConstructor) {
  Plane my_plane;
  ASSERT_EQ(my_plane.GetSeatCount(), 121)
      << "The default Plane constructor should set the seat count to 121";
  ASSERT_EQ(my_plane.GetPassengerCount(), 121)
      << "The default Plane constructor should set the passenger count to 121";
  ASSERT_EQ(my_plane.GetDestination(), "Fullerton")
      << "The default Plane constructor should set the destination to "
         "Fullerton";
}

TEST(Plane, NonDefaultConstructor) {
  std::string destination = "Manila";
  Plane my_plane(500, 450, destination);
  ASSERT_EQ(my_plane.GetSeatCount(), 500)
      << "The non-default Plane constructor should set the seat count";
  ASSERT_EQ(my_plane.GetPassengerCount(), 450)
      << "The non-default Plane constructor should set the passenger count";
  ASSERT_EQ(my_plane.GetDestination(), "Manila")
      << "The non-default Plane constructor should set the destination";
}

TEST(Driver, OutputShouldPrintAllFullyBookedPlanes) {
  ASSERT_EXECTHAT("main", "", HasSubstr("121 passengers flying to Fullerton"))
      << "Main should print all fully booked planes.";
  ASSERT_EXECTHAT("main", "", HasSubstr("220 passengers flying to Atlanta"))
      << "Main should print all fully booked planes.";
  ASSERT_EXECTHAT("main", "",
                  HasSubstr("75 passengers flying to Guatemala City"))
      << "Main should print all fully booked planes.";
}

TEST(Driver, OutputShouldNotPrintPlanesNotFullyBooked) {
  ASSERT_EXECTHAT("main", "", Not(HasSubstr("New York City")))
      << "Main should not print any plane that is not fully booked.";
  ASSERT_EXECTHAT("main", "", Not(HasSubstr("Medellin")))
      << "Main should not print any plane that is not fully booked.";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
