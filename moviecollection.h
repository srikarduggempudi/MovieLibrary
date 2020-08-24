/**
 * MovieCollection is a container that holds Movie types
 *
 * @author Srikar Duggempudi
 * @date 10 March 2020
 */

#ifndef MOVIECOLLECTION_H
#define MOVIECOLLECTION_H

#include "movie.h"
#include <string>
#include <vector>

using namespace std;

class MovieCollection {
public:
  MovieCollection() = default;
  virtual ~MovieCollection();
  // Sorts the MovieCollection
  virtual void sortCollection() = 0;
  // Displays the Movie info
  void display();
  // Check for the given movie
  bool contains(Movie *M);
  // Adds the Movie
  bool add(Movie *M);

protected:
  // MovieList stores all the Movies
  vector<Movie *> MovieList;

private:
};

#endif