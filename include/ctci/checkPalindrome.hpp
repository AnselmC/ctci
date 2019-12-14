#include <iostream>
#include <locale>
#include <string>
#include <utility>
#include <vector>
#include "CLI11.hpp"

namespace ctci {
struct PalindromePermutationOptions {
  std::vector<std::string> strings;
};
// Function declarations.
void setup_checkPalindrome(CLI::App &app);
bool checkPalindrome(std::string const &str);
void run_checkPalindrome(PalindromePermutationOptions const &opt);
}  // namespace ctci
