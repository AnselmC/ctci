#include "checkPermutation.hpp"
#include <iostream>
#include <string>

namespace ctci {
void setup_checkPermutation(CLI::App &app) {
  // Create the option and subcommand objects.
  auto opt = std::make_shared<CheckPermutationOptions>();
  auto sub = app.add_subcommand(
      "check-perm",
      "checks whether two strings are a permutation of each other");
  // Add options to sub, binding them to opt.
  sub->add_option("strings", opt->strings, "Two strings to check")->required();
  // Set the run function as callback to be called when this subcommand is
  // issued.
  sub->callback([opt]() { run_checkPermutation(*opt); });
}

void run_checkPermutation(CheckPermutationOptions const &opt) {
  if (opt.strings.size() != 2) {
    std::cout << "Pass exactly two strings to check if one is a permutation of "
                 "the other"
              << std::endl;
    return;
  }

  std::string const str1 = opt.strings[0];
  std::string const str2 = opt.strings[1];
  bool isPermutation = ctci::checkPermutation(str1, str2);
  std::cout << str1 << " is " << (isPermutation ? "" : "not ")
            << "a permutation of " << str2 << std::endl;
}

bool checkPermutation(std::string const &str1, std::string const &str2) {
  if (str1.size() != str2.size()) {
    return false;
  }
  std::string str2Copy = str2;
  for (const char &letter : str1) {
    int j = 0;
    bool found = false;
    for (const char &otherLetter : str2Copy) {
      if (letter == otherLetter) {
        str2Copy.erase(j, 1);
        found = true;
        break;
      }
      j++;
    }
    if (!found) {
      return false;
    }
  }
  return true;
}
}  // namespace ctci
