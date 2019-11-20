#include "urlify.hpp"

namespace ctci {
void setup_urlify(CLI::App &app) {
  // Create the option and subcommand objects.
  auto opt = std::make_shared<UrlifyOptions>();
  auto sub = app.add_subcommand("urlify", "urlifies a string (1.3)");

  // Add options to sub, binding them to opt.
  sub->add_option("strings", opt->strings, "Strings to urlify")->required();

  // Set the run function as callback to be called when this subcommand is
  // issued.
  sub->callback([opt]() { run_urlify(*opt); });
}

void urlify(char *str, int const length) {
  char *replacement = (char *)std::malloc(3 * sizeof(char));
  replacement[0] = '%';
  replacement[1] = '2';
  replacement[2] = '0';
  int foundWhiteSpaces = 0;
  for (int i = 0; i < length - 1 + foundWhiteSpaces * 2; i++) {
    if (str[i] == ' ') {
      for (int j = length + 1 + 2 * foundWhiteSpaces; j > i + 2; j--) {
        str[j] = str[j - 2];
      }
      for (int j = 0; j < 3; j++) {
        str[i + j] = replacement[j];
      }
      i += 2;
      foundWhiteSpaces++;
    }
  }
  std::free(replacement);
}

void run_urlify(UrlifyOptions const &opt) {

  for (std::string const &str : opt.strings) {
    int numWhitespace = std::count(str.begin(), str.end(), ' ');
    int length = str.length() + numWhitespace * 2 + 1;
    char *charArray = (char *)std::malloc(length * sizeof(char));
    std::strcpy(charArray, str.c_str());
    ctci::urlify(charArray, str.length());
    std::cout << "URLified string: " << charArray << std::endl;
    std::free(charArray);
  }
}
} // namespace ctci
