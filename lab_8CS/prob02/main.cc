#include <iostream>
#include <string>
#include <vector>

#include "chirp.h"

int main() {
  std::string input;
  const std::string prompt =
      "\nYou can \"chirp\" a new message to Chirper, "
      "or \"like\" an existing chirp, or \"exit\". What do you want to do? ";
  std::cout << prompt;
  std::getline(std::cin, input);
  std::vector<Chirp> chirps;
  int index = 0;
  while (input != "exit") {
    if (input == "chirp") {
      std::string user_message;
      std::cout << "What's your message? ";
      std::getline(std::cin, user_message);
      Chirp chirp;
      chirp.SetMessage(user_message);
      chirps.push_back(chirp);
    } else if (input == "like") {
      std::string user_index_string;
      std::cout << "Which index do you want to like? ";
      std::getline(std::cin, user_index_string);
      int user_index = std::stoi(user_index_string);
      chirps[user_index - 1].AddLike();
    }
    index += 1;
    std::cout << "Chirper has " << chirps.size() << " chirps:" << std::endl;
    for (int i = 0; i < chirps.size(); i++) {
      std::cout << (i + 1) << ". " << chirps[i].GetMessage() << " ("
                << chirps[i].GetLikes() << " likes)" << std::endl;
    }
    std::cout << prompt;
    std::getline(std::cin, input);
    if (input == "exit") {
      std::cout << "Goodbye!" << std::endl;
    }
  }
  return 0;
}