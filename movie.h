/**
 * Movies are returned and borrowed 
 *
 * @author Srikar Duggempudi
 * @date 10 March 2020
 */

#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <vector>
using namespace std;

class Movie {
public:
  Movie();
  Movie(char Genre, const string &Title, int ReleaseYear, const string &Director, int Stock);
  virtual ~Movie();
  // Returns a string with the display info
  virtual string getInfo() = 0;
  // Returns a string with the sorting attributes
  virtual string getSortingAttributes() = 0;
  // Overloaded equals operator
  bool operator==(const Movie &M) const;
  // Return the genre of the Movie
  char getGenre();
  // Sets the genre of the Movie
  void setGenre(char NewGenre);
  // Return the title of the Movie
  string getTitle();
  // Sets the title of the Movie
  void setTitle(const string &NewTitle);
  // Return the release year of the Movie
  int getReleaseYear();
  // Sets the release year of the Movie
  void setReleaseYear(int NewReleaseYear);
  // Return the director of the Movie
  string getDirector();
  // Sets the director of the Movie
  void setDirector(const string &NewDirector);
  // Return the stock of the Movie
  int getStock();
  // Sets the stock of the Movie
  void setStock(int NewStock);
  // Return the Media Type of the Movie
  char getMediaType();
  // Sets the Media Type of the Movie
  void setMediaType(char NewMediaType);

protected:
  char Genre;
  string Title;
  int ReleaseYear;
  string Director;
  int Stock;
  char MediaType;

private:
};

#endif