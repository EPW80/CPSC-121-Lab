#include <gmock/gmock-matchers.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <memory>
#include <string>

#include "../../utensils.h"
#include "../cppaudit/gtest_ext.h"

using ::testing::HasSubstr;
using ::testing::Not;

TEST(Food, AccessorsMutators) {
  Food your_food;
  your_food.SetName("Chocolate cake");
  your_food.SetMass(500);
  ASSERT_EQ(your_food.Name(), "Chocolate cake")
      << "The default food name should be Chocolate cake.";
  ASSERT_EQ(your_food.Mass(), 500) << "The default food mass should be 500.";
}

TEST(Food, DefaultConstructor) {
  Food your_food;
  ASSERT_EQ(your_food.Name(), "Apple Pie")
      << "The food name should be Apple Pie.";
  ASSERT_EQ(your_food.Mass(), 1000) << "The food mass should be 1000.";
}

TEST(Food, NondefaultConstructor) {
  Food your_food("Raspberry Jello", 750);
  ASSERT_EQ(your_food.Name(), "Raspberry Jello")
      << "The default food name should be Raspberry Jello.";
  ASSERT_EQ(your_food.Mass(), 750) << "The default food mass should be 750.";
}

TEST(Food, Eat) {
  Food your_food("Apple Pie", 750);
  your_food.Eat(150);
  ASSERT_EQ(your_food.Mass(), 600)
      << "The Apple pie should have 600g left after eating 150g from the "
         "original 750g.";
}

TEST(Food, OverEat) {
  Food your_food("Apple Pie", 750);
  your_food.Eat(760);
  ASSERT_EQ(your_food.Mass(), 0) << "The Apple pie should have 0g left if you "
                                    "eat more than the original 750g.";
}

TEST(Food, Print1) {
  Food your_food("Apple Pie", 750);
  SIMULATE_SIO(
      "", { your_food.Print(); },
      {
        ASSERT_THAT(your_output, HasSubstr("Apple Pie"))
            << "The member function should display the food name, Apple Pie.";
        ASSERT_THAT(your_output, HasSubstr("750g"))
            << "The member function should display the food mass, 750g.";
      })
}

TEST(Food, Print2) {
  Food your_food("Kuchinta", 100);
  SIMULATE_SIO(
      "", { your_food.Print(); },
      {
        ASSERT_THAT(your_output, HasSubstr("Kuchinta"))
            << "The member function should display the food name, Kuchinta.";
        ASSERT_THAT(your_output, HasSubstr("100g"))
            << "The member function should display the food mass, 100g.";
      })
}

TEST(Utensil, AccessorsMutators) {
  Utensil your_utensil;
  your_utensil.SetSize(7.5);
  your_utensil.SetColor("platinum");
  ASSERT_EQ(your_utensil.Size(), 7.5) << "The utensil size should be 7.5.";
  ASSERT_EQ(your_utensil.Color(), "platinum")
      << "The utensil color should be platinum.";
}

TEST(Utensil, DefaultConstructor) {
  Utensil your_utensil;
  ASSERT_EQ(your_utensil.Size(), 8.5)
      << "The default utensil size should be 8.5.";
  ASSERT_EQ(your_utensil.Color(), "silver")
      << "The default utensil color should be silver.";
}

TEST(Utensil, NondefaultConstructor) {
  Utensil your_utensil(8, "gold");
  ASSERT_EQ(your_utensil.Size(), 8) << "The default utensil size should be 8.";
  ASSERT_EQ(your_utensil.Color(), "gold")
      << "The default utensil color should be gold.";
}

TEST(Utensil, Use) {
  Food your_food("Tamales", 400);
  Utensil your_utensil(5, "black");
  your_utensil.Use(your_food);
  ASSERT_EQ(your_food.Mass(), 400)
      << "The mass of the food should not change after calling Utensil's use "
         "member function.";
}

TEST(Spoon, AccessorMutator) {
  Spoon your_spoon;
  your_spoon.SetSize(7.5);
  your_spoon.SetColor("platinum");
  your_spoon.SetBiteSize(100);
  ASSERT_EQ(your_spoon.Size(), 7.5) << "The spoon size should be 7.5.";
  ASSERT_EQ(your_spoon.Color(), "platinum")
      << "The spoon color should be platinum.";
  ASSERT_EQ(your_spoon.BiteSize(), 100)
      << "The spoon bite size should be 100.";
}

TEST(Spoon, DefaultConstructor) {
  Spoon your_spoon;
  ASSERT_EQ(your_spoon.Size(), 6) << "The default spoon size should be 6.";
  ASSERT_EQ(your_spoon.Color(), "silver")
      << "The default spoon color should be silver.";
  ASSERT_EQ(your_spoon.BiteSize(), 25)
      << "The default spoon bite size should be 25.";
}

TEST(Spoon, ConstructorTest) {
  std::string constructed_color = "gold";
  double constructed_size = 8, constructed_bite_size = 35;
  Spoon your_spoon(8, "gold", 35);
  ASSERT_EQ(your_spoon.Size(), 8) << "The default spoon size should be 8.";
  ASSERT_EQ(your_spoon.Color(), "gold")
      << "The default spoon color should be gold.";
  ASSERT_EQ(your_spoon.BiteSize(), 35)
      << "The default spoon bite size should be 35.";
}

TEST(Spoon, Use) {
  Food your_food("Yang chow fried rice", 1000);
  Spoon your_spoon(5, "black", 50);
  your_spoon.Use(your_food);
  ASSERT_EQ(your_food.Mass(), 950)
      << "The mass of the food should reduce by 50 grams after calling Spoon's "
         "use member function.";
}

TEST(Spoon, UseOverEat) {
  Food your_food("Tiramisu", 45);
  Spoon your_spoon(5, "silver", 50);
  your_spoon.Use(your_food);
  ASSERT_EQ(your_food.Mass(), 0)
      << "The mass of the food should be 0 because the bite was larger than "
         "the current mass.";
}

TEST(Driver, Input) {
  std::string unittest_input = "Pumpkin Pie\n1250\n5\ngold\n20\n";
  ASSERT_EXECEXIT("main", unittest_input, 3);
}

TEST(Driver, Ouptut) {
  std::string unittest_input = "Pumpkin Pie\n1250\n5\ngold\n20\n";
  std::string unittest_output =
      "Please enter the name of a food item: "
      "Please enter the mass of the food item: "
      "Please enter the size of the spoon: "
      "Please enter the color of the spoon: "
      "Please enter your bite size using the spoon: "
      "Food before being eaten:\n"
      "Pumpkin Pie 1250g\n"
      "Food after spoon used:\n"
      "Pumpkin Pie 1230g\n";
  ASSERT_EXECEQ("main", unittest_input, unittest_output);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
