/**
 * ComedyMovie is a type of Movie
 *
 * @author Srikar Duggempudi
 * @date 10 March 2020
 */

#include "comedymovie.h"
#include "movieutils.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

ComedyMovie::ComedyMovie() = default;

// Constructor parses a ComedyMovie line into tokens and stores them in
// repective variables
ComedyMovie::ComedyMovie(const string &Line) {
  // F, 10, Nora Ephron, You've Got Mail, 1998
  // Comedy:F, Stock, Director, Title, Year it released
  vector<string> Words = MovieUtils::splitString(Line, ',');

  Genre = 'F';
  Stock = stoi(Words.at(1));
  Director = Words.at(2);
  Title = Words.at(3);
  ReleaseYear = stoi(Words.at(4));
}

ComedyMovie::ComedyMovie(char Genre, const string &Title, int ReleaseYear,
                         const string &Director, int Stock)
    : Movie(Genre, Title, ReleaseYear, Director, Stock) {}

ComedyMovie::~ComedyMovie() = default;

    // Returns a string with the display info
string ComedyMovie::getInfo() {
  stringstream Ss;

  Ss << this->getGenre() << ", " << this->getStock() << ", "
     << this->getDirector() << ", " << this->getTitle() << ", "
     << this->getReleaseYear();
  return Ss.str();
}

// Returns a string with the sorting attributes
string ComedyMovie::getSortingAttributes() {
  // D F Pirates of the Caribbean, 2003
  stringstream Ss;

  Ss << this->getMediaType() << " " << this->getGenre() << " "
     << this->getTitle() << ", " << this->getReleaseYear();

  return Ss.str();
}
