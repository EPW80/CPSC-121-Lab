#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../cppaudit/gtest_ext.h"
#include "../../chirp.h"

using ::testing::HasSubstr;

TEST(ChirpTest, GetAndSetMessage) {
  Chirp chirp;
  chirp.SetMessage("Hi there");
  ASSERT_EQ(chirp.GetMessage(), "Hi there")
      << "    You should save the message set in SetMessage to a private member variable of Chirp, and return it in GetMessage.";
}

TEST(ChirpTest, AddAndGetLikes) {
  Chirp chirp;
  chirp.SetMessage("Hello world!");
  ASSERT_EQ(chirp.GetMessage(), "Hello world!")
      << "    You should save the message set in SetMessage to a private member variable of Chirp, and return it in GetMessage.";
  ASSERT_EQ(chirp.GetLikes(), 0) << "    Chirps should start with 0 likes.";
  chirp.AddLike();
  ASSERT_EQ(chirp.GetLikes(), 1) << "    AddLike should increment the number of likes by 1. Save the number of likes in a private member variable..";
  chirp.AddLike();
  ASSERT_EQ(chirp.GetLikes(), 2) << "    AddLike should increment the number of likes by 1. Save the number of likes in a private member variable..";
}

TEST(ChirperNetworkTest, ExecutesAndExits) {
  std::string user_input="exit\n";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should exit when the user types \"exit\". The "
    << "starter code already did this, so you can use \"git diff\" to see "
    << "what's changed.";
}

TEST(ChirperNetworkTest, AddsChirpText) {
  std::string user_input="chirp\nHi there\nexit\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("Hi there"))
    << "      Your program should print all the Chirps at the end of each loop.";
}

TEST(ChirperNetworkTest, PrintsTotalChirps) {
  std::string user_input="chirp\nHi there\nexit\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("1 chirp"))
    << "      Your program should print the total number of chirps.";
}

TEST(ChirperNetworkTest, AddsChirpLikes) {
  std::string user_input="chirp\nHi there\nexit\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("Hi there (0 likes)"))
    << "      Your program should print all the Chirps at the end of each loop with their number of likes";
}

TEST(ChirperNetworkTest, AddsChirpIndex) {
  std::string user_input="chirp\nHi there\nexit\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("1. Hi there (0 likes)"))
    << "      Your program should print all the Chirps at the end of each loop with their index, starting at 1 for the first item in the vector.";
}

TEST(ChirperNetworkTest, AddsMultipleChirps) {
  std::string user_input="chirp\nHi there\nchirp\nThis network is great\nchirp\nI love Chirper!\nexit\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("1. Hi there (0 likes)"))
    << "      Your program should print all the Chirps and their likes at the end of each loop with their index, starting at 1 for the first item in the vector.";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("2. This network is great (0 likes)"))
    << "      Your program should print all the Chirps and their likes at the end of each loop with their index, starting at 1 for the first item in the vector.";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("3. I love Chirper! (0 likes)"))
    << "      Your program should print all the Chirps and their likes at the end of each loop with their index, starting at 1 for the first item in the vector.";
}

TEST(ChirperNetworkTest, PrintsTotalChirpsMultiple) {
  std::string user_input="chirp\nHi there\nchirp\na social network for one!\nchirp\ncoding is fun\nexit\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("3 chirps"))
    << "      Your program should print the total number of chirps.";
}

TEST(ChirperNetworkTest, AddsLike) {
  std::string user_input="chirp\nCats are the best\nlike\n1\nexit\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("1. Cats are the best (1 like"))
    << "      When the user \"likes\" an index, you should AddLike() to the Chirp at that number minus one (for zero-based indexing).";
}

TEST(ChirperNetworkTest, AddsLikes) {
  std::string user_input="chirp\nCats are the best\nlike\n1\nchirp\nDogs drool\nlike\n2\nlike\n1\nexit\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("1. Cats are the best (2 likes)"))
    << "      When the user \"likes\" an index, you should AddLike() to the Chirp at that number minus one (for zero-based indexing).";
}

TEST(ChirpTest, OverloadingConstructorWithMessage) {
  Chirp chirp("I love CPSC121!");
  ASSERT_EQ(chirp.GetMessage(), "I love CPSC121!")
      << "    You should save the message passed to the non-default constructor overload, and return it in GetMessage.";
  ASSERT_EQ(chirp.GetLikes(), 0) << "    Chirps should start with 0 likes.";
  chirp.AddLike();
  ASSERT_EQ(chirp.GetLikes(), 1) << "    AddLike should increment the number of likes by 1.";
}

TEST(ChirpTest, OverloadingConstructorWithMessageAndLikeCount) {
  Chirp chirp("I love CPSC121!", 121);
  ASSERT_EQ(chirp.GetMessage(), "I love CPSC121!")
      << "    You should save the message passed to the non-default constructor overload, and return it in GetMessage.";
  ASSERT_EQ(chirp.GetLikes(), 121) << "    Chirp should start with 121 likes, as passed in the non-default constructor.";
  chirp.AddLike();
  ASSERT_EQ(chirp.GetLikes(), 122) << "    AddLike should increment the number of likes by 1.";
}

TEST(ChirpTest, OverloadAddLikeWithIntParameter) {
  Chirp chirp;
  chirp.SetMessage("Thanks JC and Paul!");
  ASSERT_EQ(chirp.GetMessage(), "Thanks JC and Paul!")
      << "    You should save the message passed to SetMessage and return it in GetMessage.";
  ASSERT_EQ(chirp.GetLikes(), 0) << "    Chirp should start with 0 likes.";
  chirp.AddLike(121);
  ASSERT_EQ(chirp.GetLikes(), 121) << "    AddLike should increment the number of likes by the parameter passed into the AddLike function overload that accepts an int parameter.";
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
