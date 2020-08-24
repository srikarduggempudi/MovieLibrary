/**
 * MovieCollection is a container that holds Movie types
 *
 * @author Srikar Duggempudi
 * @date 10 March 2020
 */

#include "moviecollection.h"
#include <iostream>
using namespace std;

MovieCollection::~MovieCollection() {
  for (auto M : MovieList) {
    delete M;
  }
}

// Displays the Movie info
void MovieCollection::display() {
  for (Movie *M : MovieList) {
    cout << M->getInfo() << endl;
  }
}

// Check for the given movie
bool MovieCollection ::contains(Movie *M) {
  for (auto *N : MovieList) {
    if (N == M) {
      return true;
    }
  }
  return false;
}

// Adds the Movie
bool MovieCollection::add(Movie *M) {
  MovieList.push_back(M);
  return true;
}