#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include "CLI11.hpp"

namespace ctci {
struct UrlifyOptions {
  std::vector<std::string> strings;
};
// Function declarations.
void setup_urlify(CLI::App &app);
void urlify(char *str, int const length);
void run_urlify(UrlifyOptions const &opt);
}  // namespace ctci
