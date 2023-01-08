#include <iostream>
#include <map>
#include <string>
int main() {
  std::string text;
  std::cout << "Enter text input to analyze: ";
  std::getline(std::cin, text);
  std::map<char, int> my_map;
  for (char ch : text) {
    my_map[ch]++;
  }

  char input;

  while (true) {
    std::cout << "What character do you want stats on? ";
    std::cin >> input;
    if (input == 'Q') {
      break;
    } else {
      int count = my_map[input];
      std::cout << "The character " << input << " appears " << count
                << " times."
                << "\n";
    }
  }
  std::cout << "Goodbye!"
            << "\n";
  return 0;
}