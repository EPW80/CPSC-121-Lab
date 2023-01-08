#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <random>
#include "../../player.h"
#include "../cppaudit/gtest_ext.h"

using ::testing::HasSubstr;

TEST(Player, DefaultConstructor) {
  Player your_player;
  ASSERT_EQ(your_player.GetXpos(), 0) << "The default constructor should set xpos to 0.";
  ASSERT_EQ(your_player.GetYpos(), 0) << "The default constructor should set ypos to 0.";
  ASSERT_EQ(your_player.GetName(), "Ash") << "The default constructor should set name to Ash.";
  ASSERT_EQ(your_player.GetHealth(), 10) << "The default constructor should set health to 10.";
  ASSERT_EQ(your_player.GetStrength(), 5) << "The default constructor should set strength to 5.";
  ASSERT_EQ(your_player.GetDefense(), 2) << "The default constructor should set defense to 2.";
}

TEST(Player, NonDefaultConstructor) {
  Player your_player("Almira", 5, 4, 3, 2, 1);
  ASSERT_EQ(your_player.GetXpos(), 2) << "The nondefault constructor should have set xpos to 2.";
  ASSERT_EQ(your_player.GetYpos(), 1) << "The nondefault constructor should have set ypos to 1.";
  ASSERT_EQ(your_player.GetName(), "Almira") << "The nondefault constructor should have set name to Almira.";
  ASSERT_EQ(your_player.GetHealth(), 5) << "The nondefault constructor should have set health to 5.";
  ASSERT_EQ(your_player.GetStrength(), 4)<< "The nondefault constructor should have set strength to 4.";
  ASSERT_EQ(your_player.GetDefense(), 3)<< "The nondefault constructor should have set defense to 3.";
}

TEST(Player, PublicMethodPresent) {
  Player your_player1;
  your_player1.GetXpos();
  your_player1.GetYpos();
  your_player1.GetName();
  your_player1.GetHealth();
  your_player1.GetStrength();
  your_player1.GetDefense();
  your_player1.SetXpos(1);
  your_player1.SetYpos(1);
  your_player1.SetName("Name");
  your_player1.SetHealth(1);
  your_player1.SetStrength(1);
  your_player1.SetDefense(1);
  SIMULATE_SIO("", {
    your_player1.DisplayStat();
    your_player1.PlayerMove();
    your_player1.IsPlayerDead();
    your_player1.TakeDamage(1);
  }, {})
}

TEST(Player, MutatorsAndAccessors) {
  Player your_player;
  your_player.SetXpos(2);
  your_player.SetYpos(1);
  your_player.SetName("Almira");
  your_player.SetHealth(5);
  your_player.SetStrength(4);
  your_player.SetDefense(3);

  ASSERT_EQ(your_player.GetXpos(), 2) << "The mutator should have set xpos to 2.";
  ASSERT_EQ(your_player.GetYpos(), 1) << "The mutator should have set ypos to 1.";
  ASSERT_EQ(your_player.GetName(), "Almira") << "The mutator should have set name to Almira.";
  ASSERT_EQ(your_player.GetHealth(), 5) << "The mutator should have set health to 5.";
  ASSERT_EQ(your_player.GetStrength(), 4)<< "The mutator should have set strength to 4.";
  ASSERT_EQ(your_player.GetDefense(), 3)<< "The mutator should have set defense to 3.";
}

TEST(Player, DisplayStat) {
  Player your_player;
  your_player.SetXpos(22);
  your_player.SetYpos(71);
  your_player.SetName("Shaniqua");
  your_player.SetHealth(50);
  your_player.SetStrength(14);
  your_player.SetDefense(47);

  SIMULATE_SIO("", {
    your_player.DisplayStat();
  }, {
    ASSERT_THAT(your_output, HasSubstr("22")) << "The display should have shown xpos as 22.";
    ASSERT_THAT(your_output, HasSubstr("71")) << "The display should have shown ypos as 71.";
    ASSERT_THAT(your_output, HasSubstr("Shaniqua")) << "The display should have shown name as Shaniqua.";
    ASSERT_THAT(your_output, HasSubstr("50")) << "The display should have shown health as 50.";
    ASSERT_THAT(your_output, HasSubstr("14"))<< "The display should have shown strength as 14.";
    ASSERT_THAT(your_output, HasSubstr("47"))<< "The display should have shown defense as 47.";
  });
}

TEST(Player, ChangePosition1) {
  Player your_player;
  your_player.PlayerMove();
  your_player.PlayerMove();
  your_player.PlayerMove();
  ASSERT_EQ(your_player.GetXpos(), 3) << "Callling PlayerMove three times should have set xpos to 3.";
  ASSERT_EQ(your_player.GetYpos(), 3) << "Callling PlayerMove three times should have set ypos to 3.";
}

TEST(Player, ChangePosition2) {
  Player your_player;
  your_player.PlayerMove();
  your_player.PlayerMove();
  your_player.PlayerMove();
  your_player.PlayerMove();
  your_player.PlayerMove();
  your_player.PlayerMove();
  ASSERT_EQ(your_player.GetXpos(), 6) << "Callling PlayerMove six times should have set xpos to 6.";
  ASSERT_EQ(your_player.GetYpos(), 6) << "Callling PlayerMove six times should have set ypos to 6.";
}

TEST(Player, IsPlayerDeadFalse) {
  Player your_player;
  your_player.SetHealth(10);
  ASSERT_FALSE(your_player.IsPlayerDead()) << "The player should not be dead with a health of 10.";
}

TEST(Player, IsPlayerDeadTrue) {
  Player your_player;
  your_player.SetHealth(0);
  ASSERT_TRUE(your_player.IsPlayerDead()) << "The player should be dead with a health of 0.";
}

TEST(Player, DamagePlayerAlive) {
  Player your_player;
  your_player.SetName("Tifa");
  your_player.SetHealth(30);
  SIMULATE_SIO("", {
    your_player.TakeDamage(20);
  }, {
    ASSERT_THAT(your_output, HasSubstr("Tifa took 20 damage")) << "The program should display 20 damage dealt to Tifa.";
    ASSERT_THAT(your_output, Not(HasSubstr("Tifa is dead"))) << "The damage dealt to Tifa should not be enough to kill her.";
  })
}

TEST(Player, DamagePlayerDead) {
  Player your_player;
  your_player.SetName("Snake");
  your_player.SetHealth(30);
  SIMULATE_SIO("", {
    your_player.TakeDamage(40);
  }, {
    ASSERT_THAT(your_output, HasSubstr("Snake took 40 damage"));
    ASSERT_THAT(your_output, HasSubstr("Snake is dead"));
  })
}

TEST(Driver, Output) {
  std::string unittest_output = "Player: Ash\n"
                                "Health: 10\n"
                                "Strength: 5\n"
                                "Defense: 2\n"
                                "At position: (10, 10)\n\n"
                                "Player: Les\n"
                                "Health: 20\n"
                                "Strength: 10\n"
                                "Defense: 6\n"
                                "At position: (0, 0)\n\n"
                                "Ash took 25 damage\n"
                                "Ash is dead\n\n"
                                "Player: Ash\n"
                                "Health: 0\n"
                                "Strength: 5\n"
                                "Defense: 2\n"
                                "At position: (10, 10)\n";
  ASSERT_EXECEQ("main", "", unittest_output);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
