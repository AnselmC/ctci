#include "CLI11.hpp"
#include "uniqueCharacters.hpp"
#include "urlify.hpp"
#include <iostream>

int main(int argc, char **argv) {
  CLI::App app{
      "A command line tool for running the algorithms from Cracking the "
      "Coding Interview 6th Edition"};
  ctci::setup_urlify(app);
  ctci::setup_uniqueCharacters(app);
  app.require_subcommand();

  CLI11_PARSE(app, argc, argv);

  return 0;
}
