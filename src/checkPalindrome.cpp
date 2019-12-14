#include "checkPalindrome.hpp"

namespace ctci {
void setup_checkPalindrome(CLI::App &app) {
  // Create the option and subcommand objects.
  auto opt = std::make_shared<PalindromePermutationOptions>();
  auto sub = app.add_subcommand("check-palindrome",
                                "checks whether a string has is a palindrome");

  // Add options to sub, binding them to opt.
  sub->add_option("strings", opt->strings, "Strings to check")->required();

  // Set the run function as callback to be called when this subcommand is
  // issued.
  sub->callback([opt]() { run_checkPalindrome(*opt); });
}
bool checkPalindrome(std::string const &str) {
  std::locale loc;
  bool singleLetterFound = false;
  std::string strCopy = str;
  while (strCopy.length() > 0) {
    bool foundPair = false;
    char firstLetter = strCopy.front();
    if (!std::isalpha(firstLetter, loc)) {
      strCopy.erase(0, 1);  // ignore and erase non-alphabetic characters
      continue;
    }
    int i = 1;
    for (char &otherLetter : strCopy.substr(1)) {
      if (!std::isalpha(otherLetter, loc)) {
        strCopy.erase(i, 1);  // ignore and erase non-alphabetic characters
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
    if (!foundPair and singleLetterFound) {  // we found a second character with
                                             // only one occurence
      return false;
    } else if (!singleLetterFound and !foundPair) {
      strCopy.erase(0, 1);
      singleLetterFound = true;
    }
  }
  return true;
}

void run_checkPalindrome(PalindromePermutationOptions const &opt) {
  for (auto &str : opt.strings) {
    bool isPalindromePerm = ctci::checkPalindrome(str);
    std::cout << str << " is " << (isPalindromePerm ? "a " : "not a ")
              << "palindrome permutation" << std::endl;
  }
}
}  // namespace ctci
