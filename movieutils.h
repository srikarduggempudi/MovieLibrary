/**
 * MovieUtils has the utilities used by other classes
 *
 * @author Srikar Duggempudi
 * @date 10 March 2020
 */

#ifndef MOVIEUTILS_H
#define MOVIEUTILS_H

#include <string>
#include <vector>
using namespace std;

class MovieUtils {
public:
    // Splits a line into tokens based on the separator
    static vector<string> splitString(const string &Line, char Separator);
};
#endif