#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <memory>

#include "../../message.h"
#include "../../network.h"
#include "../../phone.h"
#include "../cppaudit/gtest_ext.h"

using ::testing::HasSubstr;

TEST(Phone, NonDefaultConstructor) {
  Phone my_phone("JC");
  ASSERT_EQ(my_phone.GetOwner(), "JC")
      << "The phone constructor should set the owner's name";
}

TEST(Phone, AcceptMessage) {
  Phone my_phone("Paul");
  std::shared_ptr<Message> msg = std::make_shared<Message>("Heya!", "JC");
  my_phone.AcceptMessage(msg);
  ASSERT_EQ(my_phone.GetOwner(), "Paul")
      << "The phone constructor should set the owner's name";
}

TEST(Phone, AuthorMessage) {
  Phone my_phone("Paul");
  std::shared_ptr<Message> msg = my_phone.AuthorMessage("Hello world");
  ASSERT_EQ(msg->GetSender(), "Paul")
      << "AuthorMessage should return a pointer to a Message authored by this "
         "phone's owner.";
  ASSERT_EQ(msg->GetMessage(), "Hello world")
      << "AuthorMessage should return a pointer to a Message containing the "
         "given text.";
}

TEST(Phone, PrintMessagesAfterAcceptMessage){SIMULATE_SIO(
    "",
    {
      Phone my_phone("Paul");
      std::shared_ptr<Message> msg = std::make_shared<Message>("Heya!", "JC");
      my_phone.AcceptMessage(msg);
      my_phone.PrintMessages();
    },
    {
      ASSERT_THAT(your_output, HasSubstr("JC: Heya!"))
          << "PrintMessages should display all messages received on a phone.";
    })}

TEST(Phone, PrintMessagesAfterManyAcceptMessage){SIMULATE_SIO(
    "",
    {
      Phone my_phone("Paul");
      my_phone.AcceptMessage(std::make_shared<Message>("Heya!", "JC"));
      my_phone.AcceptMessage(std::make_shared<Message>("Hi!", "Lyka"));
      my_phone.AcceptMessage(std::make_shared<Message>("Sup", "Nick"));
      my_phone.PrintMessages();
    },
    {
      ASSERT_THAT(your_output, HasSubstr("JC: Heya!"))
          << "PrintMessages should display all messages received on a phone.";
      ASSERT_THAT(your_output, HasSubstr("Lyka: Hi!"))
          << "PrintMessages should display all messages received on a phone.";
      ASSERT_THAT(your_output, HasSubstr("Nick: Sup"))
          << "PrintMessages should display all messages received on a phone.";
    })}

TEST(Network, DefaultConstructor) {
  Network my_network;
}

TEST(Network, AddPhoneAndSendMessage){SIMULATE_SIO(
    "",
    {
      Network my_network;
      std::shared_ptr<Phone> pauls_phone = std::make_shared<Phone>("Paul");
      my_network.AddPhone(pauls_phone);
      my_network.SendMessage(std::make_shared<Message>("Heya!", "JC"), "Paul");
      pauls_phone->PrintMessages();
    },
    {
      ASSERT_THAT(your_output, HasSubstr("JC: Heya!"))
          << "PrintMessages should display all messages received on a phone.";
    })}

TEST(Network, AddPhoneAndSendMessageToMultipleRecipients){SIMULATE_SIO(
    "",
    {
      Network my_network;
      std::shared_ptr<Phone> pauls_phone = std::make_shared<Phone>("Paul");
      std::shared_ptr<Phone> jcs_phone = std::make_shared<Phone>("JC");
      my_network.AddPhone(pauls_phone);
      my_network.AddPhone(jcs_phone);
      std::vector<std::string> names;
      names.push_back("JC");
      names.push_back("Paul");
      my_network.SendMessage(std::make_shared<Message>("Heya!", "JC"), names);
      my_network.SendMessage(std::make_shared<Message>("Hi!", "Paul"), names);
      pauls_phone->PrintMessages();
      jcs_phone->PrintMessages();
    },
    {
      ASSERT_THAT(your_output, HasSubstr("JC: Heya!"))
          << "PrintMessages should display all messages received on a phone.";
      ASSERT_THAT(your_output, HasSubstr("Paul: Hi!"))
          << "PrintMessages should display all messages received on a phone.";
    })}

TEST(Network, SendMessageToNonexistentRecipient) {
  Network my_network;
  my_network.SendMessage(std::make_shared<Message>("Heya!", "JC"), "Nobody");
}

TEST(Network, AddPhonesAndSendMessageToNonexistentRecipients) {
  Network my_network;
  std::vector<std::string> names;
  names.push_back("Nobody1");
  names.push_back("Nobody2");
  my_network.SendMessage(std::make_shared<Message>("Heya!", "JC"), names);
}

TEST(Driver, OutputShouldShowAllReceivedMessages) {
  ASSERT_EXECTHAT("main", "", HasSubstr("Printing messages sent to Anna"))
      << "Main should print messages sent to Anna";
  ASSERT_EXECTHAT("main", "", HasSubstr("Printing messages sent to Raf"))
      << "Main should print messages sent to Raf";
  ASSERT_EXECTHAT("main", "", HasSubstr("Printing messages sent to JC"))
      << "Main should print messages sent to JC";
  ASSERT_EXECTHAT("main", "", HasSubstr("Raf: Lol"))
      << "Main should print messages authored by Raf";
  ASSERT_EXECTHAT("main", "", HasSubstr("Raf: Lol"))
      << "Main should print messages authored by Raf";
  ASSERT_EXECTHAT("main", "", HasSubstr("Raf: help how do C++"))
      << "Main should print messages authored by Raf";
  ASSERT_EXECTHAT("main", "", HasSubstr("JC: Hi class!"))
      << "Main should print messages authored by JC";
  ASSERT_EXECTHAT("main", "", HasSubstr("Anna: Sup"))
      << "Main should print messages authored by Anna";
  ASSERT_EXECTHAT("main", "", HasSubstr("Anna: Hi Prof!"))
      << "Main should print messages authored by Anna";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
