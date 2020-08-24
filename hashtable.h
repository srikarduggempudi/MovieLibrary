/**
 * HashTable maps the Genre to the right Collection
 *
 * @author Srikar Duggempudi
 * @date 10 March 2020
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "movie.h"
#include "moviecollection.h"
#include <map>
#include <string>
#include <vector>

using namespace std;

class HashTable {
public:
  HashTable();
  ~HashTable();

  // Add Movie to HashTable
  bool addMovie(Movie *M);
  // Gets HashKey of each genre
  int getHashKey(char MovieType);
  // Displays HashTable
  void display();
  // Get MovieCollection based on genre
  MovieCollection *getMovieCollection(char Genre);

private:
  MovieCollection *CollectionTable[3];
};

#endif