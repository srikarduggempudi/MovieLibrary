/**
 * Customer is the one who borrows and returns the Movies
 *
 * @author Srikar Duggempudi
 * @date 10 March 2020
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "moviecollection.h"
#include <map>
#include <string>
#include <vector>

using namespace std;

class Customer {
public:
  Customer();
  explicit Customer(const string &Line);
  // Returns name
  string getName();
  // Set name
  void setName(const string &NewName);
  // Returns first name
  string getFirstName();
  // Set first name
  void setFirstName(const string &NewFirstName);
  // Returns last name
  string getLastName();
  // Set last name
  void setLastName(const string &NewLastName);
  // Returns ID
  int getID();
  // Set ID
  void setID(int NewID);
  // Return a vector of borrowed movies
  vector<Movie *> getBorrowedMovies();
  // Display history
  void displayHistory();
  // Borrow Movie
  void borrowMovie(Movie *M);
  // Return Movie
  void returnMovie(Movie *M);

private:
  string Name;
  string LastName;
  string FirstName;
  int ID;
  vector<string> History;
  vector<Movie *> BorrowedMovies;

  // Adding the transaction type to the history record
  string buildHistoryRecord(char Operation, Movie*M);
};

#endif