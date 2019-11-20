#include <iostream>
#include <locale>
#include <string>
#include <utility>
#include <vector>

bool checkIfPalindromePermutation(const std::string str) {

  std::locale loc;
  bool singleLetterFound = false;
  std::string strCopy = str;
  while (strCopy.length() > 0) {
    bool foundPair = false;
    char firstLetter = strCopy.front();
    if (!std::isalpha(firstLetter, loc)) {
      strCopy.erase(0, 1); // ignore and erase non-alphabet characters
      continue;
    }
    int i = 1;
    for (char &otherLetter : strCopy.substr(1)) {
      if (!std::isalpha(otherLetter, loc)) {
        strCopy.erase(i, 1); // ignore and erase non-alphabet characters
        continue;
      }
      if (std::tolower(firstLetter) == std::tolower(otherLetter)) {
        // erase the matched pair
        strCopy.erase(i, 1);
        strCopy.erase(0, 1);
        foundPair = true;
        break;
      }
      i++;
    }
    if (!foundPair and singleLetterFound) { // we found a second character with
                                            // only one occurence
      return false;
    } else if (!singleLetterFound and !foundPair) {
      strCopy.erase(0, 1);
      singleLetterFound = true;
    }
  }
  return true;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "Need at least one string to check if palindrome permutation"
              << std::endl;
  }
  for (int i = 1; i < argc; i++) {
    const std::string str = argv[i];
    bool isPalindromePerm = checkIfPalindromePermutation(str);
    std::cout << str << " is " << (isPalindromePerm ? "a " : "not a ")
              << "palindrome permutation" << std::endl;
  }
}
