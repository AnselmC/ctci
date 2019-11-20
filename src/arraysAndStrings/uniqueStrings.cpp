#include <iostream>
#include <string>

namespace ctci {
namespace arraysAndStrings {
bool allUnique(const std::string &str) {
  int i = 0;
  for (const char &letter : str) {
    for (const char &otherLetter : str.substr(i + 1, str.length())) {
      if (letter == otherLetter) {
        return false;
      }
    }
    i++;
  }
  return true;
}
} // namespace arraysAndStrings
} // namespace ctci

int main(int argc, char **argv) {
  if (argc == 1) {
    std::cout << "Enter at least one word to check for uniqueness" << std::endl;
    return -1;
  }
  for (int i = 1; i < argc; i++) {

    std::string str = argv[i];
    bool unique = ctci::arraysAndStrings::allUnique(str);
    std::cout << str
              << " has all unique characters: " << (unique ? "True" : "False")
              << std::endl;
  }
  return 0;
}
