/**
 * Store is the databse that has access to the customers and movies
 *
 * @author Srikar Duggempudi
 * @date 10 March 2020
 */

#ifndef STORE_H
#define STORE_H

#include "customercollection.h"
#include "hashtable.h"
#include <map>
#include <string>
#include <vector>

using namespace std;

class Store {
public:
  // Load Movie file
  void loadMovieFile(const string &Filename);
  // Load Customer file
  void loadCustomerFile(const string &Filename);
  // Load Commands file
  void loadCommandsFile(const string &Filename);
  // Borrow Movie
  void borrowMovie(int CustomerID, Movie *M);
  // Return Movie
  void returnMovie(int CustomerID, Movie *M);
  // Display Inventory
  void displayInventory();
  // Parse Movie
  Movie *parseMovie(char Genre, const string &Rest);
  // Display History
  void displayHistory(int CustomerID);

private:
  CustomerCollection CustomerList;
  HashTable MovieTable;
};

#endif