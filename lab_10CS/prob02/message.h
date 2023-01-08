#pragma once

#include <string>

class Message {
 public:
  Message(const std::string &msg, const std::string &sender)
      : message_(msg), sender_(sender) {}

  const std::string& GetMessage() const {
    return message_;
  }
  const std::string& GetSender() const {
    return sender_;
  }

 private:
  std::string message_;
  std::string sender_;
};