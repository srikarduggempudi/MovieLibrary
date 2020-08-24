/**
 * Driver for starting movie store tests
 *
 * @author Srikar Duggempudi
 * @date 10 March 2020
 */


#include <iostream>

using namespace std;

// forward declaration, implementation in store_test.cpp
void testAll();
void testFile();

int main() {
  //testAll();
  testFile();
  cout << "Done." << endl;
  return 0;
}
