/**
 * ClassicMovie is a type of Movie
 *
 * @author Srikar Duggempudi
 * @date 10 March 2020
 */

#ifndef CLASSICMOVIE_H
#define CLASSICMOVIE_H

#include "movie.h"
#include <string>

using namespace std;

class ClassicMovie : public virtual Movie {
public:
  ClassicMovie();
  explicit ClassicMovie(const string &Line);
  ClassicMovie(char Genre, const string &Title, int ReleaseYear,
               const string &Director, int Stock, const string &MajorActor,
               int ReleaseMonth);
  ~ClassicMovie() override;
  // Returns a string with the display info
  string getInfo() override;
  // Returns a string with the sorting attributes
  string getSortingAttributes() override;

  // Return major actor
  string getMajorActor();
  // Set major actor
  void setMajorActor(const string &NewMajorActor);
  // Return release month
  int getReleaseMonth();
  // Set release month
  void setReleaseMonth(int NewReleaseMonth);

private:
  string MajorActor;
  int ReleaseMonth;
};

#endif