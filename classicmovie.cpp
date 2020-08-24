/**
 * ClassicMovie is a type of Movie
 *
 * @author Srikar Duggempudi
 * @date 10 March 2020
 */

#include "classicmovie.h"
#include "movieutils.h"
#include <sstream>

using namespace std;

ClassicMovie::ClassicMovie() : MajorActor{""}, ReleaseMonth{0} {}

// Constructor parses a ClassicMovie line into tokens and stores them in
// repective variables
ClassicMovie::ClassicMovie(const string &Line) {
  // Classics: C, Stock, Director, Title, Major actor Release date
  // C, 10, George Cukor, Holiday, Cary Grant 9 1938

  vector<string> Words = MovieUtils::splitString(Line, ',');

  Genre = 'C';
  Stock = stoi(Words.at(1));
  Director = Words.at(2);
  Title = Words.at(3);
  vector<string> ActorDate = MovieUtils::splitString(Words.at(4), ' ');
  MajorActor = "";
  MajorActor.append(ActorDate.at(0));
  MajorActor.append(" ");
  MajorActor.append(ActorDate.at(1));
  ReleaseMonth = stoi(ActorDate.at(2));
  ReleaseYear = stoi(ActorDate.at(3));
}

ClassicMovie::ClassicMovie(char Genre, const string &Title, int ReleaseYear,
                           const string &Director, int Stock,
                           const string &MajorActor, int ReleaseMonth)
    : Movie(Genre, Title, ReleaseYear, Director, Stock), MajorActor{MajorActor},
      ReleaseMonth{ReleaseMonth} {}

ClassicMovie::~ClassicMovie() = default;

// Return major actor
string ClassicMovie::getMajorActor() { return MajorActor; }

// Set major actor
void ClassicMovie::setMajorActor(const string &NewMajorActor) {
  MajorActor = NewMajorActor;
}

// Return release month
int ClassicMovie::getReleaseMonth() { return ReleaseMonth; }

// Set release month
void ClassicMovie::setReleaseMonth(int NewReleaseMonth) {
  ReleaseMonth = NewReleaseMonth;
}

// Returns a string with the display info
string ClassicMovie::getInfo() {
  stringstream Ss;

  Ss << this->getGenre() << ", " << this->getStock() << ", "
     << this->getDirector() << ", " << this->getTitle() << ", " << MajorActor
     << ", " << ReleaseMonth << " " << this->getReleaseYear();
  return Ss.str();
}

// Returns a string with the sorting attributes
string ClassicMovie::getSortingAttributes() {
  // D C 9 1938 Katherine Hepburn
  stringstream Ss;

  Ss << this->getMediaType() << " " << this->getGenre() << " "
     << this->getReleaseMonth() << " " << this->getReleaseYear() << " "
     << this->getMajorActor();

  return Ss.str();
}
