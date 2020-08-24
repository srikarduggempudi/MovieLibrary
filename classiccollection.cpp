/**
 * ClassicCollection is a container that holds ClassicMovie types
 *
 * @author Srikar Duggempudi
 * @date 10 March 2020
 */

#include "classiccollection.h"
#include "classicmovie.h"
#include <algorithm>

using namespace std;

ClassicCollection::~ClassicCollection() = default;

// Comparator function for comparing ClassicMovies
bool compareClassicMovies(Movie *M1, Movie *M2) {
  auto *CM1 = dynamic_cast<ClassicMovie *>(M1);
  auto *CM2 = dynamic_cast<ClassicMovie *>(M2);

  return (CM1->getReleaseMonth() < CM2->getReleaseMonth() &&
          CM1->getMajorActor() < CM2->getMajorActor());
}

// Sort the collection based on ClassicMovie's Sorting order
void ClassicCollection::sortCollection() {
  sort(MovieList.begin(), MovieList.end(), compareClassicMovies);
}

// Find the Movie based on Movie's sorting attributes
Movie *ClassicCollection::findBy(int ReleaseMonth, int ReleaseYear,
                                 const string &MajorActor) {
  for (Movie *M : MovieList) {
    auto *CM = dynamic_cast<ClassicMovie *>(M);
    if (CM->getReleaseYear() == ReleaseYear &&
        CM->getReleaseMonth() == ReleaseMonth &&
        CM->getMajorActor() == MajorActor) {
      return M;
    }
  }
  return nullptr;
}