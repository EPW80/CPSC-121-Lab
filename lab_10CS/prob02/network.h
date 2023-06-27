#pragma once

#include <map>
#include <memory>

#include "message.h"
#include "phone.h"

class Network {
 public:
  void AddPhone(std::shared_ptr<Phone> my_phone);

  void SendMessage(std::shared_ptr<Message> my_message,
                   const std::string &message);

  void SendMessage(std::shared_ptr<Message> my_message,
                   const std::vector<std::string> &message);

 private:
  std::map<std::string, std::shared_ptr<Phone>> phonebook_;
};