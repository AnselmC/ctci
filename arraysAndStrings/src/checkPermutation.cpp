#include <iostream>
#include <string>

namespace ctci {
namespace arraysAndStrings {
bool checkPermutation(const std::string &str1, const std::string &str2) {
  std::string str2Copy = str2;
  for (const char &letter : str1) {
    int j = 0;
    bool found = false;
    for (const char &otherLetter : str2Copy) {
      if (letter == otherLetter) {
        str2Copy.erase(j, 1);
        found = true;
        continue;
      }
      j++;
    }
    if (!found) {
      return false;
    }
  }
  return true;
}
} // namespace arraysAndStrings
} // namespace ctci

int main(int argc, char **argv) {
  if (argc != 3) {
    std::cout << "Exactly two arguments are accepted" << std::endl;
    return -1;
  }
  std::string str1 = argv[1];
  std::string str2 = argv[2];
  bool isPermutation = ctci::arraysAndStrings::checkPermutation(str1, str2);
  std::cout << str1 << " is " << (isPermutation ? "" : "not ")
            << "a permutation of " << str2 << std::endl;

  return 0;
}
