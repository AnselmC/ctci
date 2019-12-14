#include "CLI11.hpp"
#include <iostream>
#include <string>

namespace ctci {
struct CheckPermutationOptions {
  std::vector<std::string> strings;
};
// Function declarations.
void setup_checkPermutation(CLI::App &app);
bool checkPermutation(std::string const &str1, std::string const &str2);
void run_checkPermutation(CheckPermutationOptions const &opt);
} // namespace ctci
