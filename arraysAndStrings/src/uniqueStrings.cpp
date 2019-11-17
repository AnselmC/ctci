#include <iostream>
#include <string>

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

int main(int argc, char **argv) {
  std::string myStr = "asdfhjklasdf";
  if (argc == 1) {
    std::cout << "Enter at least one word to check for uniqueness" << std::endl;
    return -1;
  }
  for (int i = 1; i < argc; i++) {

    std::string str = argv[i];
    bool unique = allUnique(str);
    std::cout << str
              << " has all unique characters: " << (unique ? "True" : "False")
              << std::endl;
  }
  return 0;
}
