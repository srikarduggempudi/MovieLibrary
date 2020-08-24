/**
 * HashTable maps the Genre to the right Collection
 *
 * @author Srikar Duggempudi
 * @date 10 March 2020
 */

#include "hashtable.h"
#include "classiccollection.h"
#include "comedycollection.h"
#include "dramacollection.h"
#include "moviecollection.h"

HashTable::HashTable() {
  CollectionTable[0] = new ComedyCollection();
  CollectionTable[1] = new DramaCollection();
  CollectionTable[2] = new ClassicCollection();
}

HashTable::~HashTable() {
  for (MovieCollection *M : CollectionTable) {
    delete M;
  }
}

// Gets HashKey of each genre
int HashTable::getHashKey(char MovieType) {
  switch (MovieType) {
  case 'F':
    return 0;
  case 'D':
    return 1;
  case 'C':
    return 2;
  default:
    return -1;
  }
}

// Add Movie to HashTable
bool HashTable ::addMovie(Movie *M) {
  int Index = getHashKey(M->getGenre());
  if (Index >= 0) {
    CollectionTable[Index]->add(M);
    return true;
  }
  return false;
}

// Displays HashTable
void HashTable::display() {
  for (MovieCollection *MC : CollectionTable) {
    MC->display();
  }
}

// Get MovieCollection based on genre
MovieCollection *HashTable::getMovieCollection(char Genre) {
  return CollectionTable[getHashKey(Genre)];
}
