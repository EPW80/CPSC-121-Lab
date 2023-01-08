#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>

// Credits and thanks goes to CPSC121 student developer Esteban Escartin.
int main() {
  char command_selection;
  int problem_number;

  if (system(NULL) == 1) {
    // Create Command to be run based off user input
    std::cout << "Which problem do you want to compile?\nEnter 1 or 2:\n";
    std::cin >> problem_number;
    std::string problem_str = (problem_number < 10)
                                  ? "prob0" + std::to_string(problem_number)
                                  : "prob" + std::to_string(problem_number);
    std::string command = "cd " + problem_str + " && make build && ./main";
    // Run command made above
    int status = system(command.c_str());
    if (status != 0) {
      return 0;
    }
    std::cout << std::endl
              << command.substr(3, 6)
              << " finished running. Would you like to run make commands?\nT: "
                 "make test\nS: make stylecheck\nF: make formatcheck\nPress "
                 "any other key to exit.\nSelection: "
              << std::endl;
    std::cin >> command_selection;
    switch (std::tolower(command_selection)) {
      case 't':
        command = "cd " + problem_str + " && make test";
        system(command.c_str());
        break;
      case 's':
        command = "cd " + problem_str + " && make clean && make stylecheck";
        system(command.c_str());
        break;
      case 'f':
        command = "cd " + problem_str + " && make clean && make formatcheck";
        system(command.c_str());
        break;
      default:
        break;
    }
    std::cout << "Done!" << std::endl;
  }
}