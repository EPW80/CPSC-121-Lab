#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../cppaudit/gtest_ext.h"
#include "../../dice.h"

using ::testing::HasSubstr;

TEST(DiceTest, RollDiceAndGetValue) {
  srand(0);
  Dice die;
  die.Roll();
  ASSERT_EQ(die.GetValue(), 2) << "    Rolling the dice should set the value to be a random number mod six, plus 1.";
}

TEST(DiceTest, RollDiceAndGetValueTwice) {
  srand(0);
  Dice die;
  die.Roll();
  ASSERT_EQ(die.GetValue(), 2) << "    Rolling the dice should set the value to be a random number mod six, plus 1.";
  ASSERT_EQ(die.GetValue(), 2) << "    GetValue should not call rand(), only Roll() should call rand().";
}

TEST(DiceTest, ReRollDice) {
  srand(0);
  Dice die;
  die.Roll();
  ASSERT_EQ(die.GetValue(), 2) << "    Rolling the dice should set the value to be a random number mod six, plus 1.";
  die.Roll();
  ASSERT_EQ(die.GetValue(), 5) << "    Each time Roll() is called, the value should be updated based on rand().";
}

TEST(YahtzeeTest, DoesNotWantToPlay) {
  std::streambuf* original = std::cin.rdbuf();
  std::istringstream stream("n\n");
  std::cin.rdbuf(stream.rdbuf());

  std::streambuf* original_out = std::cout.rdbuf();
  std::stringstream stream_out;
  std::cout.rdbuf(stream_out.rdbuf());

  PlayYahtzee();

  std::cin.rdbuf(original);
  std::cout.rdbuf(original_out);
  EXPECT_THAT(stream_out.str(), HasSubstr("Do you want to roll"))
      << "    You should ask the user if they want to roll.";
}

TEST(YahtzeeTest, PlayOnce) {
  srand(0);
  std::streambuf* original = std::cin.rdbuf();
  std::istringstream stream("y\nn\n");
  std::cin.rdbuf(stream.rdbuf());

  std::streambuf* original_out = std::cout.rdbuf();
  std::stringstream stream_out;
  std::cout.rdbuf(stream_out.rdbuf());

  PlayYahtzee();

  std::cin.rdbuf(original);
  std::cout.rdbuf(original_out);
  EXPECT_THAT(stream_out.str(), HasSubstr("2 5 4"))
      << "    Your Yahtzee game should have three dice. Print the value of the "
      << "three dice to the terminal after rolling them when the user wants to roll once.";
}

TEST(YahtzeeTest, PlayMultipleTimes) {
  srand(0);
  std::streambuf* original = std::cin.rdbuf();
  std::istringstream stream("y\ny\nn\n");
  std::cin.rdbuf(stream.rdbuf());

  std::streambuf* original_out = std::cout.rdbuf();
  std::stringstream stream_out;
  std::cout.rdbuf(stream_out.rdbuf());

  PlayYahtzee();

  std::cin.rdbuf(original);
  std::cout.rdbuf(original_out);
  EXPECT_THAT(stream_out.str(), HasSubstr("2 6 2"))
      << "    Your Yahtzee game should have three dice. Print the value of the "
      << "three dice to the terminal after rolling them each time the user responds \"y\".";
}

TEST(YahtzeeTest, PlaysWithoutYahtzee) {
  // With srand(0), Yahtzee on the 9th roll. Try 8 yeses.
  srand(0);
  std::streambuf* original = std::cin.rdbuf();
  std::istringstream stream("y\ny\ny\ny\ny\ny\ny\ny\nn\n");
  std::cin.rdbuf(stream.rdbuf());

  std::streambuf* original_out = std::cout.rdbuf();
  std::stringstream stream_out;
  std::cout.rdbuf(stream_out.rdbuf());

  PlayYahtzee();

  std::cin.rdbuf(original);
  std::cout.rdbuf(original_out);
  EXPECT_THAT(stream_out.str(), testing::Not(HasSubstr("Yahtzee")))
      << "    You should not print out \"Yahtzee\" when the value of all three dice is not the same.";
}

TEST(YahtzeeTest, PlaysUntilYahtzee) {
  // With srand(0), Yahtzee on the 9th roll.
  srand(0);
  std::streambuf* original = std::cin.rdbuf();
  std::istringstream stream("y\ny\ny\ny\ny\ny\ny\ny\ny\nn\n");
  std::cin.rdbuf(stream.rdbuf());

  std::streambuf* original_out = std::cout.rdbuf();
  std::stringstream stream_out;
  std::cout.rdbuf(stream_out.rdbuf());

  PlayYahtzee();

  std::cin.rdbuf(original);
  std::cout.rdbuf(original_out);
  EXPECT_THAT(stream_out.str(), HasSubstr("3 3 3"));
  EXPECT_THAT(stream_out.str(), HasSubstr("Yahtzee"))
      << "    You should print out \"Yahtzee\" when the value of all three dice is the same.";
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
