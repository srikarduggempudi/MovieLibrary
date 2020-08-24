/**
 * ComedyCollection is a container that holds ComedyMovie types
 *
 * @author Srikar Duggempudi
 * @date 10 March 2020
 */

#include "comedycollection.h"
#include <algorithm>

using namespace std;

ComedyCollection::~ComedyCollection() = default;

// Comparator function for comparing ComedyMovies
bool compareComedyMovies(Movie *M1, Movie *M2) {
  return (M1->getTitle() < M2->getTitle() &&
          M1->getReleaseYear() < M2->getReleaseYear());
}

// Sort the collection based on ComedyMovie's Sorting order
void ComedyCollection::sortCollection() {
  sort(MovieList.begin(), MovieList.end(), compareComedyMovies);
}

// Find the Movie based on Movie's sorting attributes
Movie *ComedyCollection::findBy(const string &Title, int Year) {
  for (Movie *M : MovieList) {
    if (M->getTitle() == Title && M->getReleaseYear() == Year) {
      return M;
    }
  }
  return nullptr;
}