#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../cppaudit/gtest_ext.h"
#include "../../cpputils/graphics/test/image_test_utils.h"
#include "../../astronaut.h"
#include "../../impostor.h"
#include "../../crewmate.h"


using ::testing::HasSubstr;

graphics::Color blue(0, 0, 255);
graphics::Color pink(255, 0, 255);

TEST(AstronautTest, GetName) {
  Astronaut astronaut("ruth_bader_ginsburg", blue);
  ASSERT_EQ(astronaut.GetName(), "ruth_bader_ginsburg") << "    Astronaut should save the "
      "std::string name from the constructor in a member variable and return "
      "that in the GetName member function.";
}

TEST(AstronautTest, GetColor) {
  Astronaut astronaut("jane_goodall", pink);
  ASSERT_EQ(astronaut.GetColor(), pink) << "    Astronaut should save the "
      "graphics::Color from the constructor in a member variable and return "
      "that in the GetColor member function.";
}

TEST(AstronautTest, GetIconFilename) {
  Astronaut astronaut("marie_curie", pink);
  ASSERT_EQ(astronaut.GetIconFilename(), "astronaut.bmp") << "    Astronaut should "
      "always return \"astronaut.bmp\" from the GetIconFilename method.";
}

TEST(ImpostorTest, IsBaseClass) {
  bool is_parent = std::is_base_of<Astronaut, Impostor>::value;
  ASSERT_TRUE(is_parent) << "    Impostor should inherit from Astronaut";
}

TEST(ImpostorTest, SuperclassGetters) {
  Impostor astronaut("sally_ride", blue);
  ASSERT_EQ(astronaut.GetName(), "sally_ride") << "    Impostor should use the parent "
      "class constructor with the name and color passed into its constructor.";
  ASSERT_EQ(astronaut.GetColor(), blue) << "    Impostor should use the parent "
      "class constructor with the name and color passed into its constructor.";
  ASSERT_EQ(astronaut.GetIconFilename(), "astronaut.bmp")
      << "    Impostor should use superclass GetIconFilename method";
}

TEST(ImpostorTest, HasGetColorAndNameFunctionFromBaseClass) {
  Impostor impostor("lise_meitner", blue);
  Astronaut* a_ptr = &impostor;
  EXPECT_EQ(a_ptr->GetName(), "lise_meitner") << "    Impostor class should not redefine "
          "GetName which gets the name which was set in the constructor.";
  EXPECT_EQ(a_ptr->GetColor(), blue) << "    Impostor class should not redefine "
          "GetColor which gets the color which was set in the constructor.";
}

TEST(CrewmateTest, IsBaseClass) {
  bool is_parent = std::is_base_of<Astronaut, Crewmate>::value;
  ASSERT_TRUE(is_parent) << "    Crewmate should inherit from Astronaut";
}

TEST(CrewmateTest, SuperclassGetters) {
  Crewmate astronaut("grace_hopper", pink);
  ASSERT_EQ(astronaut.GetName(), "grace_hopper") << "    Crewmate should use the parent "
      "class constructor with the name and color passed into its constructor.";
  ASSERT_EQ(astronaut.GetColor(), pink) << "    Crewmate should use the parent "
      "class constructor with the name and color passed into its constructor, and "
      "GetColor should return the color passed to the superclass constructor.";
}

TEST(CrewmateTest, IsAlive) {
  Crewmate astronaut("katherine_johnson", blue);
  ASSERT_TRUE(astronaut.GetIsAlive()) << "   Crewmate should be alive by default.";
  astronaut.SetIsAlive(false);
  ASSERT_FALSE(astronaut.GetIsAlive()) << "   Crewmate should not be alive after SetIsAlive(false).";
}

TEST(CrewmateTest, GetIconFilename) {
  Crewmate astronaut("grace_hopper", pink);
  ASSERT_TRUE(astronaut.GetIsAlive()) << "   Crewmate should be alive by default.";
  ASSERT_EQ(astronaut.GetIconFilename(), "astronaut.bmp")
      << "    Crewmate should use superclass GetIconFilename method to return \"astronaut.bmp\" when the Crewmate is still alive.";
  astronaut.SetIsAlive(false);
  ASSERT_EQ(astronaut.GetIconFilename(), "ghost.bmp")
      << "    Crewmate should return \"ghost.bmp\" when the Crewmate is not alive.";
}

TEST(CrewmateTest, GetColor) {
  Crewmate astronaut("nettie_stevens", blue);
  ASSERT_TRUE(astronaut.GetIsAlive()) << "   Crewmate should be alive by default.";
  ASSERT_EQ(astronaut.GetColor(), blue) << "    Crewmate should use the parent "
      "class constructor with the name and color passed into its constructor, and "
      "GetColor should return the color passed to the superclass constructor.";
  astronaut.SetIsAlive(false);
  ASSERT_EQ(astronaut.GetColor(), graphics::Color(128, 128, 255))
      << "    Crewmate should return a modified color when the Crewmate is not "
      "alive. Use the formula from the README to shift the Astronaut::GetColor() when "
      "GetIsAlive() is false.";
}

TEST(CrewmateTest, Tasks) {
  Crewmate astronaut("cecilia_payne", pink);
  ASSERT_EQ(0, astronaut.GetTaskCount()) << "    Crewmate should have default 0 tasks before DoTask has been called.";

  std::streambuf* original_out = std::cout.rdbuf();
  std::stringstream stream_out;
  std::cout.rdbuf(stream_out.rdbuf());
  astronaut.DoTask("asteroid avoidance");
  std::cout.rdbuf(original_out);
  EXPECT_THAT(stream_out.str(), testing::HasSubstr("cecilia_payne is doing asteroid avoidance"))
      << "    Crewmate::DoTask should print the crewmate name, the string \" is doing \", and the "
      "task name.";

  ASSERT_EQ(1, astronaut.GetTaskCount()) << "    Crewmate should have 1 tasks after DoTask has been called once";
}

TEST(CrewmateTest, HasGetNameFunctionFromBaseClass) {
  Crewmate crewmate("elizabeth_blackwell", blue);
  Astronaut* a_ptr = &crewmate;
  EXPECT_EQ(a_ptr->GetName(), "elizabeth_blackwell") << "    Impostor class should not redefine "
          "GetName which gets the name which was set in the constructor.";
}

TEST(ImpostorAndCrewmateTest, ImpostorKillsCrewmate) {
  Impostor impostor("pie", blue);
  Crewmate crewmate("robot", pink);
  ASSERT_TRUE(crewmate.GetIsAlive());

  std::streambuf* original_out = std::cout.rdbuf();
  std::stringstream stream_out;
  std::cout.rdbuf(stream_out.rdbuf());
  impostor.Kill(crewmate);
  std::cout.rdbuf(original_out);
  EXPECT_THAT(stream_out.str(), testing::HasSubstr("pie killed robot"))
      << "    Impostor::Kill should print the impostor name, the string \" killed \", and the "
      "crewmate name.";

  EXPECT_FALSE(crewmate.GetIsAlive()) << "    Make sure your impostor Kill function "
      "calls Crewmate::SetIsAlive(false). Make sure the Kill function uses pass by reference, a Crewmate&.";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  bool skip = true;
  for (int i = 0; i < argc; i++)
  {
    if (std::string(argv[i]) == "--noskip")
    {
      skip = false;
    }
  }
  if (skip)
  {
    ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  }
  return RUN_ALL_TESTS();
}
