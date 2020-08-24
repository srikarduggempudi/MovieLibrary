/**
 * DramaCollection is a container that holds DramaMovie types
 *
 * @author Srikar Duggempudi
 * @date 10 March 2020
 */

#include "dramacollection.h"
#include <algorithm>

using namespace std;

DramaCollection::~DramaCollection() = default;

// Comparator function for comparing DramaMovies
bool compareDramaMovies(Movie *M1, Movie *M2) {
  return (M1->getDirector() < M2->getDirector() &&
          M1->getTitle() < M2->getTitle());
}

// Sort the collection based on DramaMovie's Sorting order
void DramaCollection::sortCollection() {
  sort(MovieList.begin(), MovieList.end(), compareDramaMovies);
}

// Find the Movie based on Movie's sorting attributes
Movie *DramaCollection::findBy(const string &Director, const string &Title) {
  for (Movie *M : MovieList) {
    if (M->getDirector() == Director && M->getTitle() == Title) {
      return M;
    }
  }
  return nullptr;
}