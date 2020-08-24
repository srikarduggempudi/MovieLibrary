/**
 * Movies are returned and borrowed
 *
 * @author Srikar Duggempudi
 * @date 10 March 2020
 */

#include "movie.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

Movie::Movie()
    : Genre{' '}, Title{""}, ReleaseYear{0}, Director{""}, Stock{0}, MediaType{
                                                                         'D'} {}

Movie::Movie(char Genre, const string &Title, int ReleaseYear, const string &Director,
             int Stock)
    : Genre{Genre}, Title{Title}, ReleaseYear{ReleaseYear}, Director{Director},
      Stock{Stock}, MediaType{'D'} {}
Movie::~Movie() = default;

    // Return the genre of the Movie
char Movie ::getGenre() { return Genre; }

// Sets the genre of the Movie
void Movie ::setGenre(char NewGenre) { Genre = NewGenre; }

// Return the title of the Movie
string Movie ::getTitle() { return Title; }

// Sets the title of the Movie
void Movie ::setTitle(const string &NewTitle) { Title = NewTitle; }

// Return the release year of the Movie
int Movie ::getReleaseYear() { return ReleaseYear; }

// Sets the release year of the Movie
void Movie ::setReleaseYear(int NewReleaseYear) {
  ReleaseYear = NewReleaseYear;
}

// Return the director of the Movie
string Movie ::getDirector() { return Director; }

// Sets the director of the Movie
void Movie ::setDirector(const string &NewDirector) { Director = NewDirector; }

// Return the stock of the Movie
int Movie::getStock() { return Stock; }

// Sets the stock of the Movie
void Movie::setStock(int NewStock) { Stock = NewStock; }

// Return the Media Type of the Movie
char Movie::getMediaType() { return MediaType; }

// Sets the Media Type of the Movie
void Movie::setMediaType(char NewMediaType) { MediaType = NewMediaType; }

// Overloaded equals operator
bool Movie::operator==(const Movie &M) const {
  return (Genre == M.Genre && Title == M.Title &&
          ReleaseYear == M.ReleaseYear && Director == M.Director &&
          Stock == M.Stock);
}
