#include "phone.h"
void Phone::PrintMessages() {
  for (std::shared_ptr<Message> message : messages_) {
    std::cout << message->GetSender() << ": " << message->GetMessage()
              << std::endl;
  }
}