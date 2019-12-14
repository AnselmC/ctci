#include "uniqueCharacters.hpp"

namespace ctci {
void setup_uniqueCharacters(CLI::App &app) {
  // Create the option and subcommand objects.
  auto opt = std::make_shared<UniqueCharactersOptions>();
  auto sub = app.add_subcommand(
      "unique-chars", "checks whether a string has all unique chars (1.2)");

  // Add options to sub, binding them to opt.
  sub->add_option("strings", opt->strings, "Strings to check")->required();

  // Set the run function as callback to be called when this subcommand is
  // issued.
  sub->callback([opt]() { run_uniqueCharacters(*opt); });
}

bool allUnique(std::string const &str) {
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

void run_uniqueCharacters(UniqueCharactersOptions const &opt) {
  for (std::string const &str : opt.strings) {
    bool unique = ctci::allUnique(str);
    std::cout << str
              << " has all unique characters: " << (unique ? "True" : "False")
              << std::endl;
  }
}

} // namespace ctci
