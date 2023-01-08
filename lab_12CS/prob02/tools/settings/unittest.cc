#include <gmock/gmock-matchers.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <memory>
#include <string>

#include "../../train.h"
#include "../cppaudit/gtest_ext.h"

using ::testing::HasSubstr;
using ::testing::Not;

TEST(Train, PublicFunctionsPresent) {
  Train train(150, 150, nullptr);
  train.GetNextCarriage();
  train.GetPassengerCount();
  train.GetSeatCount();
}

TEST(Train, RecursiveFunctionsPresent) {
  std::shared_ptr<Train> carriage1 = std::make_shared<Train>(150, 150, nullptr);
  carriage1->TotalTrainPassengers();
  carriage1->MaxCarriagePassengers();
  carriage1->IsTrainFull();
  std::shared_ptr<Train> carriage2 = std::make_shared<Train>(200, 200, nullptr);
  carriage1->AddCarriageToEnd(carriage2);
}

TEST(Train, NonDefaultConstructorSetsMembers) {
  std::shared_ptr<Train> amtrak_rear =
      std::make_shared<Train>(150, 200, nullptr);
  ASSERT_EQ(amtrak_rear->GetPassengerCount(), 150)
      << "The non-default Train constructor should set the train's passenger "
         "count";
  ASSERT_EQ(amtrak_rear->GetSeatCount(), 200)
      << "The non-default Train constructor should set the train's passenger "
         "count";

  std::shared_ptr<Train> amtrak_front =
      std::make_shared<Train>(555, 555, amtrak_rear);
  ASSERT_EQ(amtrak_front->GetPassengerCount(), 555)
      << "The non-default Train constructor should set the train's passenger "
         "count";
  ASSERT_EQ(amtrak_front->GetSeatCount(), 555)
      << "The non-default Train constructor should set the train's passenger "
         "count";
  ASSERT_EQ(amtrak_front->GetNextCarriage(), amtrak_rear)
      << "The non-default Train constructor should set the train's next "
         "carriage";
}

TEST(Train, TotalTrainPassengers) {
  std::shared_ptr<Train> caboose = std::make_shared<Train>(200, 200, nullptr);
  std::shared_ptr<Train> carriage3 = std::make_shared<Train>(150, 150, caboose);
  std::shared_ptr<Train> carriage2 =
      std::make_shared<Train>(100, 100, carriage3);
  std::shared_ptr<Train> carriage1 = std::make_shared<Train>(50, 50, carriage2);
  ASSERT_EQ(carriage1->TotalTrainPassengers(), 500)
      << "TotalTrainPassengers should return the total number of passengers "
         "on the train.";
}

TEST(Train, MaxCarriagePassengers) {
  std::shared_ptr<Train> caboose = std::make_shared<Train>(200, 200, nullptr);
  std::shared_ptr<Train> carriage3 = std::make_shared<Train>(150, 150, caboose);
  std::shared_ptr<Train> carriage2 =
      std::make_shared<Train>(100, 100, carriage3);
  std::shared_ptr<Train> carriage1 = std::make_shared<Train>(50, 50, carriage2);
  ASSERT_EQ(carriage1->MaxCarriagePassengers(), 200)
      << "MaxCarriagePassengers should return the maximum number of passengers "
         "that "
         "are seated on a single carriage in the train.";
}

TEST(Train, TrainIsFull) {
  std::shared_ptr<Train> caboose = std::make_shared<Train>(200, 200, nullptr);
  std::shared_ptr<Train> carriage3 = std::make_shared<Train>(150, 150, caboose);
  std::shared_ptr<Train> carriage2 =
      std::make_shared<Train>(100, 100, carriage3);
  std::shared_ptr<Train> carriage1 = std::make_shared<Train>(50, 50, carriage2);
  ASSERT_TRUE(carriage1->IsTrainFull())
      << "IsTrainFull should return true if every carriage in the train is "
         "full, i.e."
         "the passenger count is equal to the seat count.";
}

TEST(Train, TrainIsNotFull) {
  std::shared_ptr<Train> caboose = std::make_shared<Train>(0, 200, nullptr);
  std::shared_ptr<Train> carriage3 = std::make_shared<Train>(0, 150, caboose);
  std::shared_ptr<Train> carriage2 = std::make_shared<Train>(0, 100, carriage3);
  std::shared_ptr<Train> carriage1 = std::make_shared<Train>(50, 50, carriage2);
  ASSERT_FALSE(carriage1->IsTrainFull())
      << "IsTrainFull should return false if at least one carriage in the "
         "train is not full, i.e. the passenger count is less than the seat "
         "count.";
}

TEST(Train, AddCarriageToEnd) {
  std::shared_ptr<Train> front = std::make_shared<Train>(10, 10, nullptr);
  std::shared_ptr<Train> carriage = std::make_shared<Train>(20, 20, nullptr);
  front->AddCarriageToEnd(carriage);
  ASSERT_EQ(front->GetNextCarriage(), carriage)
      << "AddCarriageToEnd should add the given train to the end of the train.";
  std::shared_ptr<Train> caboose = std::make_shared<Train>(30, 30, nullptr);
  front->AddCarriageToEnd(caboose);
  ASSERT_EQ(carriage->GetNextCarriage(), caboose)
      << "AddCarriageToEnd should add the given train to the end of the train.";
}

TEST(Driver, OutputShouldPrintTotalPassengers) {
  ASSERT_EXECTHAT("main", "", HasSubstr("Total passengers in the train: 641"))
      << "Main should print the total number of passengers in the train.";
}

TEST(Driver, OutputShouldPrintMaxPassengersInCarriage) {
  ASSERT_EXECTHAT("main", "", HasSubstr("Max passengers in a carriage: 250"))
      << "Main should print the maximum number of passengers in a carriage.";
}

TEST(Driver, OutputShouldPrintFullFirstAndLaterAvailability) {
  ASSERT_EXECTHAT("main", "", HasSubstr("The train is full"))
      << "The train should be full to start.";
  ASSERT_EXECTHAT("main", "", HasSubstr("The train now has available seats."))
      << "The train should have available seats after adding the caboose.";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
