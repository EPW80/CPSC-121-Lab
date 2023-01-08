#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../../pet.h"
#include "../cppaudit/gtest_ext.h"

using ::testing::HasSubstr;

TEST(Breed, PublicMethodsPresent) {
  Breed your_breed;
  your_breed.Species();
  your_breed.BreedName();
  your_breed.Color();
  your_breed.SetSpecies("Dog");
  your_breed.SetBreedName("Pug");
  your_breed.SetColor("Fawn");  
}

TEST(Breed, DefaultConstructor) {
  Breed your_breed;
  ASSERT_EQ(your_breed.Species(), "Dog") << "The default species should be Dog";
  ASSERT_EQ(your_breed.BreedName(), "Chihuahua") << "The default breed name should be Chihuahua";
  ASSERT_EQ(your_breed.Color(), "Fawn") << "The default color should be Fawn";
}

TEST(Breed, NonDefaultConstructor) {
  Breed your_breed("Cat", "Siamese", "Seal and white");
  ASSERT_EQ(your_breed.Species(), "Cat") << "The species should be Cat";
  ASSERT_EQ(your_breed.BreedName(), "Siamese") << "The name should be Siamese";
  ASSERT_EQ(your_breed.Color(), "Seal and white") << "The color should be Seal and white";
}

TEST(Breed, AccessorsAndMutators) {
  Breed your_breed;
  your_breed.SetSpecies("Cat");
  your_breed.SetBreedName("Siamese");
  your_breed.SetColor("Seal and white");

  ASSERT_EQ(your_breed.Species(), "Cat") << "The default species should be Cat";
  ASSERT_EQ(your_breed.BreedName(), "Siamese") << "The default name should be Siamese";
  ASSERT_EQ(your_breed.Color(), "Seal and white") << "The default color should be Seal and white";
}

TEST(Pet, PublicMethodsPresent) {
  Pet your_pet;
  Breed your_breed;
  your_pet.Name();
  your_pet.GetBreed();
  your_pet.Weight();
  your_pet.SetName("Doug");
  your_pet.SetBreed(your_breed);
  your_pet.SetBreed("Dog", "Pug", "Fawn");
  your_pet.SetWeight(15.6);
}

TEST(Pet, DefaultConstructor) {
  Pet your_pet;
  ASSERT_EQ(your_pet.GetBreed().Species(), "Dog") << "The default species should be Dog";
  ASSERT_EQ(your_pet.GetBreed().BreedName(), "Chihuahua")  << "The default Breed name should be Chihuahua";
  ASSERT_EQ(your_pet.GetBreed().Color(), "Fawn")  << "The default color should be Fawn";
  ASSERT_EQ(your_pet.Name(), "Cookie") << "The default name should be Cookie";
  ASSERT_EQ(your_pet.Weight(), 15.6) << "The default weight should be 15.6";
}

TEST(Pet, NonDefaultConstructorBreedParameter) {
  Breed your_breed("Cat", "Tabby", "Orange");
  Pet your_pet("Pumpkin", your_breed, 16.8);
  ASSERT_EQ(your_pet.GetBreed().Species(), "Cat") << "The species should be Cat";
  ASSERT_EQ(your_pet.GetBreed().BreedName(), "Tabby")  << "The Breed name should be Tabby";
  ASSERT_EQ(your_pet.GetBreed().Color(), "Orange") << "The color should be Orange";
  ASSERT_EQ(your_pet.Name(), "Pumpkin") << "The name should be Pumpkin";  
  ASSERT_EQ(your_pet.Weight(), 16.8) << "The weight should be 16.8";
}

TEST(Pet, NonDefaultConstructorExpandedBreedParameter) {
  Pet your_pet("Pumpkin", "Cat", "Tabby", "Orange", 16.8);
  ASSERT_EQ(your_pet.GetBreed().Species(), "Cat") << "The species should be Cat";
  ASSERT_EQ(your_pet.GetBreed().BreedName(), "Tabby")  << "The Breed name should be Tabby";
  ASSERT_EQ(your_pet.GetBreed().Color(), "Orange") << "The color should be Orange";
  ASSERT_EQ(your_pet.Name(), "Pumpkin") << "The name should be Pumpkin";  
  ASSERT_EQ(your_pet.Weight(), 16.8) << "The weight should be 16.8";
}

TEST(Pet, AccessorsAndMutators) {
  Pet your_pet;
  Breed your_breed("Dog", "American Pitbull Terrier", "Blonde");
  your_pet.SetBreed(your_breed);
  your_pet.SetName("Mimi");
  your_pet.SetWeight(38.4);
  ASSERT_EQ(your_pet.Name(), "Mimi");  
  ASSERT_EQ(your_pet.Weight(), 38.4);
  ASSERT_EQ(your_pet.GetBreed().Species(), "Dog");
  ASSERT_EQ(your_pet.GetBreed().BreedName(), "American Pitbull Terrier");
  ASSERT_EQ(your_pet.GetBreed().Color(), "Blonde");
}

TEST(Pet, SetBreedOverload) {
  Pet your_pet;
  your_pet.SetBreed("Dog", "Pug", "Fawn");
  ASSERT_EQ(your_pet.GetBreed().Species(), "Dog") << "The species should be Dog";
  ASSERT_EQ(your_pet.GetBreed().BreedName(), "Pug") << "The breed name should be Pug";
  ASSERT_EQ(your_pet.GetBreed().Color(), "Fawn") << "The color should be Fawn";
}

TEST(Pet, Print) {
  SIMULATE_SIO("", {
    Pet your_pet("Pumpkin", "Cat", "Tabby", "Orange", 16.8);
    your_pet.Print();
  }, {
    ASSERT_THAT(your_output, HasSubstr("Name: Pumpkin")) << "The name should be Pumpkin";  
    ASSERT_THAT(your_output, HasSubstr("Species: Cat")) << "The species should be Cat";
    ASSERT_THAT(your_output, HasSubstr("Breed: Tabby"))  << "The Breed name should be Tabby";  
    ASSERT_THAT(your_output, HasSubstr("Orange")) << "The color should be Orange";  
    ASSERT_THAT(your_output, HasSubstr("16.8")) << "The weight should be 16.8";
  })
}

TEST(Driver, Input) {
  std::string unittest_input = "AirBud\nDog\nGolden Retriever\nBlonde\n44.5\nCookie\nDog\nEnglish Bulldog\nBrown & White\n31.2\nq\n";
  ASSERT_EXECEXIT("main", unittest_input, 3);
}

TEST(Driver, Output) {
  std::string unittest_input = "AirBud\nDog\nGolden Retriever\nBlonde\n44.5\nCookie\nDog\nEnglish Bulldog\nBrown & White\n31.2\nq\n";

  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("Name: AirBud")) << "The name should be AirBud";  
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("Species: Dog")) << "The species should be Dog";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("Breed: Golden Retriever"))  << "The Breed name should be Golden Retriever";  
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("Color: Blonde")) << "The color should be Blonde";  
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("Weight: 44.5")) << "The weight should be 44.5";

  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("Name: Cookie")) << "The name should be Cookie";  
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("Species: Dog")) << "The species should be Dog";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("Breed: English Bulldog"))  << "The Breed name should be English Bulldog";  
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("Color: Brown & White")) << "The color should be Brown & White";  
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("Weight: 31.2")) << "The weight should be 31.2";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}