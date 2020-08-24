/**
 * DramaMovie is a type of Movie
 *
 * @author Srikar Duggempudi
 * @date 10 March 2020
 */

#include "dramamovie.h"
#include "movieutils.h"
#include <sstream>
#include <string>
using namespace std;

DramaMovie::DramaMovie() = default;

// Constructor parses a DramaMovie line into tokens and stores them in
// repective variables
DramaMovie::DramaMovie(const string &Line) {
  // Drama: D, Stock, Director, Title, Year it released
  // D, 10, Steven Spielberg, Schindler's List, 1993
  vector<string> Words = MovieUtils::splitString(Line, ',');

  Genre = 'D';
  Stock = stoi(Words.at(1));
  Director = Words.at(2);
  Title = Words.at(3);
  ReleaseYear = stoi(Words.at(4));
}

DramaMovie::DramaMovie(char Genre, const string &Title, int ReleaseYear,
                       const string &Director, int Stock)
    : Movie(Genre, Title, ReleaseYear, Director, Stock) {}

// Returns a string with the display info
string DramaMovie::getInfo() {
  stringstream Ss;

  Ss << this->getGenre() << ", " << this->getStock() << ", "
     << this->getDirector() << ", " << this->getTitle() << ", "
     << this->getReleaseYear();
  return Ss.str();
}

DramaMovie::~DramaMovie() = default;

// Returns a string with the sorting attributes
string DramaMovie::getSortingAttributes() {
  // D D Steven Spielberg, Schindler's List,
  stringstream Ss;

  Ss << this->getMediaType() << " " << this->getGenre() << " "
     << this->getDirector() << ", " << this->getTitle() << ",";

  return Ss.str();
}
