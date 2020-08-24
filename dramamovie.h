/**
 * DramaMovie is a type of Movie
 *
 * @author Srikar Duggempudi
 * @date 10 March 2020
 */

#ifndef DRAMAMOVIE_H
#define DRAMAMOVIE_H

#include "movie.h"
#include <string>

using namespace std;

class DramaMovie : public virtual Movie {
public:
  DramaMovie();
  explicit DramaMovie(const string &Line);
  DramaMovie(char Genre, const string &Title, int ReleaseYear, const string &Director,
             int Stock);
  ~DramaMovie() override;
  // Returns a string with the display info
  string getInfo() override;
  // Returns a string with the sorting attributes
  string getSortingAttributes() override;
};

#endif