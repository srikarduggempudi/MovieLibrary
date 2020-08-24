/**
 * ComedyMovie is a type of Movie
 *
 * @author Srikar Duggempudi
 * @date 10 March 2020
 */

#ifndef COMEDYMOVIE_H
#define COMEDYMOVIE_H

#include "movie.h"
#include <string>

using namespace std;

class ComedyMovie : public virtual Movie {
public:
  ComedyMovie();
  explicit ComedyMovie(const string &Line);

  ComedyMovie(char Genre, const string &Title, int ReleaseYear, const string &Director,
              int Stock);
  ~ComedyMovie() override;
  // Returns a string with the display info
  string getInfo() override;
  // Returns a string with the sorting attributes
  string getSortingAttributes() override;
};

#endif