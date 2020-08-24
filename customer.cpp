/**
 * Customer is the one who borrows and returns the Movies
 *
 * @author Srikar Duggempudi
 * @date 10 March 2020
 */

#include "customer.h"
#include "movieutils.h"

#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

Customer::Customer() {
  Name = "";
  ID = 0;
}

// Constructor parses a Customer line into tokens and stores them in
// repective variables
Customer::Customer(const string &Line) {
  vector<string> Words = MovieUtils::splitString(Line, ' ');

  ID = stoi(Words.at(0));
  LastName = Words.at(1);
  FirstName = Words.at(2);
  Name = LastName + " " + FirstName;
}

// Returns last name
string Customer::getLastName() { return LastName; }

// Set last name
void Customer ::setLastName(const string &NewLastName) { Name = NewLastName; }

// Returns first name
string Customer::getFirstName() { return FirstName; }

// Set first name
void Customer ::setFirstName(const string &NewFirstName) {
  Name = NewFirstName;
}

// Return name
string Customer ::getName() { return Name; }

// Set name
void Customer ::setName(const string &NewName) { Name = NewName; }

// Return ID
int Customer ::getID() { return ID; }

// Set ID
void Customer ::setID(int NewID) { ID = NewID; }

// Return a vector of borrowed movies
vector<Movie *> Customer ::getBorrowedMovies() { return BorrowedMovies; }

// Display history
void Customer ::displayHistory() {
  for (const string &S : History) {
    cout << S << endl;
  }
}

// Adding the transaction type to the history record
string Customer::buildHistoryRecord(char Operation, Movie *M) {
  stringstream Ss;
  Ss << Operation << " " << M->getSortingAttributes();
  return Ss.str();
}

// Borrow Movie
void Customer ::borrowMovie(Movie *M) {
  M->setStock(M->getStock() - 1);
  BorrowedMovies.push_back(M);
  // B 1234 D C 9 1938 Katherine Hepburn
  // B 1234 D F Pirates of the Caribbean,2003
  // R 1234 D C 9 1938 Katherine Hepburn
  // B 1234 D D Steven Spielberg,Schindler's List,
  History.push_back(buildHistoryRecord('B', M));
}

// Return Movie
void Customer ::returnMovie(Movie *M) {
  bool Borrowed = false;
  for (int I = 0; I < BorrowedMovies.size(); ++I) {
    if (BorrowedMovies[I] == M) {
      BorrowedMovies.erase(BorrowedMovies.begin() + I);
      Borrowed = true;
    }
  }
  if (Borrowed) {
    M->setStock(M->getStock() + 1);
    // add a history record with latest on the top of history
    History.insert(History.begin(), buildHistoryRecord('R', M));
  } else {
    cout << "Movie [" << M->getTitle() << "] has not been borrowed by Customer ["
         << this->getName() << "] " << endl;
  }
}
