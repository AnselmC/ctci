#include <iostream>
#include <memory>
#include <string>
#include "CLI11.hpp"

namespace ctci {
struct UniqueCharactersOptions {
  std::vector<std::string> strings;
};
// Function declarations.
void setup_uniqueCharacters(CLI::App &app);
bool allUnique(std::string const &str);
void run_uniqueCharacters(UniqueCharactersOptions const &opt);
}  // namespace ctci
