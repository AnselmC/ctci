#include "checkPermutation.hpp"
#include "uniqueCharacters.hpp"
#include "urlify.hpp"

#include "gtest/gtest.h"

using namespace ctci;

TEST(ArraysAndStrings, URLify) {
  std::vector<std::string> inputStrings, outputStrings;
  inputStrings.push_back("Mr. Tommy Lee Jones");
  outputStrings.push_back("Mr.%20Tommy%20Lee%20Jones");
  inputStrings.push_back("NothingToDoHere");
  outputStrings.push_back("NothingToDoHere");
  // TODO: fix urlify so that following tests pass
  // inputStrings.push_back(" ");
  // outputStrings.push_back("");
  // inputStrings.push_back("Varying  space     counts ");
  // outputStrings.push_back("Varying%20space%20counts");
  std::map<std::string, std::string> inputOutput;
  std::transform(inputStrings.begin(), inputStrings.end(),
                 outputStrings.begin(),
                 std::inserter(inputOutput, inputOutput.end()),
                 std::make_pair<std::string const &, std::string const &>);
  for (auto &element : inputOutput) {
    std::string input = element.first;
    std::string output = element.second;
    int numWhitespace = std::count(input.begin(), input.end(), ' ');
    int length = input.length() + numWhitespace * 2 + 1;
    char *charArray = (char *)std::malloc(length * sizeof(char));
    std::strcpy(charArray, input.c_str());
    urlify(charArray, input.length());
    ASSERT_EQ(output, charArray);
    std::free(charArray);
  }
}

TEST(ArraysAndStrings, UniqueCharacters) {
  std::map<std::string, bool> stringsToCheck;
  stringsToCheck.insert(std::make_pair("asdf", true));
  stringsToCheck.insert(std::make_pair("aaa", false));
  stringsToCheck.insert(std::make_pair("", true));
  stringsToCheck.insert(std::make_pair(" a", true));
  stringsToCheck.insert(std::make_pair(" a ", false));
  stringsToCheck.insert(std::make_pair("$a!", true));
  stringsToCheck.insert(std::make_pair("$a$", false));
  for (auto &elem : stringsToCheck) {
    ASSERT_EQ(allUnique(elem.first), elem.second);
  }
}

TEST(ArraysAndStrings, CheckPermutation) {
  std::vector<std::tuple<std::string, std::string, bool>> stringsToCheck;
  stringsToCheck.push_back(std::make_tuple("asdf", "dsaf", true));
  stringsToCheck.push_back(std::make_tuple("asdf", "dsa", false));
  stringsToCheck.push_back(std::make_tuple(" asd", "dsa", false));
  stringsToCheck.push_back(std::make_tuple("!@#$", "$#@!", true));
  stringsToCheck.push_back(
      std::make_tuple("Mr. John Smith", "Smith Mr. John", true));

  std::string first, second;
  bool isPerm;
  for (auto &elem : stringsToCheck) {
    std::tie(first, second, isPerm) = elem;
    ASSERT_EQ(checkPermutation(first, second), isPerm)
        << first << " and " << second << " should" << (!isPerm ? " NOT" : "")
        << " be a permutation";
  }
}
