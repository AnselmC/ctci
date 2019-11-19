#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

void urlify(char *str, const int length) {
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

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "Need at least one string to URLify" << std::endl;
  }
  for (int i = 1; i < argc; i++) {
    std::string str = argv[i];
    int numWhitespace = std::count(str.begin(), str.end(), ' ');
    int length = str.length() + numWhitespace * 2 + 1;
    char *charArray = (char *)std::malloc(length * sizeof(char));
    std::strcpy(charArray, argv[i]);
    urlify(charArray, str.length());
    std::cout << "URLified string: " << charArray << std::endl;
    std::free(charArray);
  }
}
