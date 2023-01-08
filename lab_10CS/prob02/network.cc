#include "network.h"

#include "phone.h"
void Network::AddPhone(std::shared_ptr<Phone> my_phone) {
  phonebook_.insert({my_phone->GetOwner(), my_phone});
 }
void Network::SendMessage(std::shared_ptr<Message> my_message,
                          const std::string &recipient) {
    if (phonebook_.count(recipient)) {
      phonebook_.at(recipient)->AcceptMessage(my_message);
    }
}
void Network::SendMessage(std::shared_ptr<Message> my_message,const 
                          std::vector<std::string> &recipients) {
    for (const std::string &recipient : recipients  ) {
  if (phonebook_.count(recipient)) {
      phonebook_.at(recipient)->AcceptMessage(my_message);
    }
  }
}