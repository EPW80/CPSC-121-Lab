#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../cppaudit/gtest_ext.h"
#include "../../cup.h"

using ::testing::HasSubstr;

TEST(Cup, DefaultConstructor) {
  Cup your_cup;
  ASSERT_EQ(your_cup.GetDrinkType(),"Water") << "   The default value of drink_type_ should be Water";
  ASSERT_DOUBLE_EQ(your_cup.GetFluidOz(), 16.0)<< "   The default value of fluid_oz_ should be 16.0";
}
TEST(Cup, NonDefaultConstructor) {
  Cup your_cup("Aquafina", 32);
  ASSERT_EQ(your_cup.GetDrinkType(),"Aquafina")<< "   The value of drink_type_ should be Aquafina";
  ASSERT_DOUBLE_EQ(your_cup.GetFluidOz(), 32.0)<< "   The value of fluid_oz_ should be 32.0";
}
TEST(Cup, TestDrinkReducesFluidOz){
  Cup your_cup;
  your_cup.Drink(10);
  ASSERT_EQ(your_cup.GetFluidOz(),6)<< "   The cup should have 6oz left after drinking 10oz";
  your_cup.Drink(4);
  ASSERT_EQ(your_cup.GetFluidOz(),2)<< "   The cup should have 2oz left after drinking 4oz";
  your_cup.Drink(6);
  ASSERT_EQ(your_cup.GetFluidOz(),0)<< "   The cup should have 0oz left after trying to drink 6oz";
}

TEST(Cup, TestRefill){
  Cup your_cup;
  your_cup.Refill(8);
  ASSERT_EQ(your_cup.GetFluidOz(),24)<< "   The cup should now have 24oz after refilling 8oz";
  your_cup.Refill(4);
  ASSERT_EQ(your_cup.GetFluidOz(),28)<< "   The cup should now have 28oz after refilling 4oz";;
}

TEST(Cup, TestNewDrink)
{
  Cup your_cup;
  your_cup.NewDrink("Pepsi", 44.0);
  ASSERT_EQ(your_cup.GetDrinkType(),"Pepsi")<< "   The cup should now have Pepsi as the new drink type";
  ASSERT_EQ(your_cup.GetFluidOz(),44.0)<< "   The cup should now have 44oz as the new amount";
}
TEST(Cup, TestEmpty)
{
  Cup your_cup;
  your_cup.Empty();
  ASSERT_EQ(your_cup.GetDrinkType(),"nothing")<< "   The cup should now have nothing as the drink type after emptying";
  ASSERT_EQ(your_cup.GetFluidOz(),0.0)<< "   The cup should now contain 0oz after emptying";
}

TEST(Driver, StartWith8ozDrink2oz) {
  std::string input = "Orange Juice\n8\nD\n2oz\nX\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", input, HasSubstr("6 oz. of Orange Juice"));
  });
}

TEST(Driver, StartWith8ozRefill1oz) {
  std::string input = "Orange Juice\n8\nR\n1oz\nX\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", input, HasSubstr("9 oz. of Orange Juice"));
  });
}

TEST(Driver, NewDrink) {
  std::string input = "Orange Juice\n8\nN\nMilk\n32\nX\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", input, HasSubstr("32 oz. of Milk"));
  });
}

TEST(Driver, Empty) {
  std::string input = "Orange Juice\n8\nE\nX\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", input, HasSubstr("Your cup currently has 0 oz. of nothing"));
  });
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
