#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "message.h"

class Phone {
 public:
  Phone(const std::string &owner) : owner_(owner) {}
  std::string GetOwner() const {
    return owner_;
  }
  std::shared_ptr<Message> AuthorMessage(const std::string &message) {
    return std::make_shared<Message>(message, owner_);
  }
  void AcceptMessage(std::shared_ptr<Message> message) {
    messages_.push_back(message);
  }
  // moved function definition to phone.cc
  void PrintMessages();

 private:
  std::string owner_;
  std::vector<std::shared_ptr<Message>> messages_;
};