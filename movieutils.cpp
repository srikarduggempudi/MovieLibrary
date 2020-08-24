/**
 * MovieUtils has the utilities used by other classes
 *
 * @author Srikar Duggempudi
 * @date 10 March 2020
 */

#include "movieutils.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Splits a line into tokens based on the separator
vector<string> MovieUtils::splitString(const string &Line, char Separator) {
  vector<string> Words;
  stringstream Ss(Line);
  while (Ss.good()) {
    string Substr;
    getline(Ss, Substr, Separator);
    // remove leading spaces
    Substr = Substr.erase(0, Substr.find_first_not_of(' '));
    Words.push_back(Substr);
  }

  return Words;
}