/**
 * Store is the databse that has access to the customers and movies
 *
 * @author Srikar Duggempudi
 * @date 10 March 2020
 */

#include "store.h"
#include "classiccollection.h"
#include "classicmovie.h"
#include "comedycollection.h"
#include "comedymovie.h"
#include "dramacollection.h"
#include "dramamovie.h"
#include "movieutils.h"
#include <fstream>
#include <iostream>

using namespace std;

// Load Movie file
void Store ::loadMovieFile(const string &Filename) {
  ifstream InFile(Filename);
  string Line;
  int LineNumber = 1;

  while (getline(InFile, Line)) {
    if (Line.rfind('C', 0) == 0) {
      auto *CM = new ClassicMovie(Line);
      MovieTable.addMovie(CM);
    } else if (Line.rfind('D', 0) == 0) {
      auto *DM = new DramaMovie(Line);
      MovieTable.addMovie(DM);
    } else if (Line.rfind('F', 0) == 0) {
      auto *FM = new ComedyMovie(Line);
      MovieTable.addMovie(FM);
    } else {
      cout << "Error: Not a valid Movie Type [Line " << LineNumber 
          // << ": " << Line 
          << "] " << endl;
    }
    LineNumber++;
  }
}

// Load Customer file
void Store ::loadCustomerFile(const string &Filename) {
  ifstream InFile(Filename);
  string Line;
  while (getline(InFile, Line)) {
    auto *C = new Customer(Line);
    CustomerList.addCustomer(C);
  }
}

Movie *Store::parseMovie(char Genre, const string &Rest) {
  // B 8000 D F You've Got Mail, 1998
  // B 1000 D D Barry Levinson, Good Morning Vietnam,
  // B 1000 D C 5 1940 Katherine Hepburn
  Movie *M = nullptr;
  vector<string> Words;
  if (Genre == 'F') {
    Words = MovieUtils::splitString(Rest, ',');
    string Title = Words.at(0);
    int Year = stoi(Words.at(1));
    auto *FM =
        dynamic_cast<ComedyCollection *>(MovieTable.getMovieCollection(Genre));
    M = FM->findBy(Title, Year);
  } else if (Genre == 'D') {
    Words = MovieUtils::splitString(Rest, ',');
    string Director = Words.at(0);
    string Title = Words.at(1);
    Title = Title.erase(0, Title.find_first_not_of(' '));
    auto *DM =
        dynamic_cast<DramaCollection *>(MovieTable.getMovieCollection(Genre));
    M = DM->findBy(Director, Title);
  } else if (Genre == 'C') {
    Words = MovieUtils::splitString(Rest, ' ');
    int Month = stoi(Words.at(0));
    int Year = stoi(Words.at(1));
    string MajorActor = Words.at(2) + " " + Words.at(3);
    auto *CM =
        dynamic_cast<ClassicCollection *>(MovieTable.getMovieCollection(Genre));
    M = CM->findBy(Month, Year, MajorActor);
  }
  return M;
}

// Load Commands file
void Store ::loadCommandsFile(const string &Filename) {
  ifstream InFile(Filename);
  string Line;
  int LineNumber = 1;

  while (getline(InFile, Line)) {
    vector<string> Tokens = MovieUtils::splitString(Line, ' ');
    if (Line.rfind('B', 0) == 0) {
      // Borrow command
      // B 8000 D F You've Got Mail, 1998
      // B 1000 D D Barry Levinson, Good Morning Vietnam,
      // B 1000 D C 5 1940 Katherine Hepburn
      int CustomerID = stoi(Tokens.at(1));
      string MediaType = Tokens.at(2);
      char MovieType = Tokens.at(3)[0];
      string Rest = Line.substr(11);
      Movie *M = parseMovie(MovieType, Rest);
      if (M != nullptr) {
        borrowMovie(CustomerID, M);
      } else {
        cout << "Error: Not a valid Command [Line "
             << LineNumber //<< ": " << Line
             << "] " << endl;
      }
    } else if (Line.rfind('R', 0) == 0) {
      // Return command
      // R 8000 D F You've Got Mail, 1998
      // R 1000 D D Barry Levinson, Good Morning Vietnam,
      // R 1000 D C 5 1940 Katherine Hepburn
      int CustomerID = stoi(Tokens.at(1));
      string MediaType = Tokens.at(2);
      char MovieType = Tokens.at(3)[0];
      string Rest = Line.substr(11);
      Movie *M = parseMovie(MovieType, Rest);
      if (M != nullptr) {
        returnMovie(CustomerID, M);
      } else {
        cout << "Error: Not a valid Command [Line "
             << LineNumber //<< ": " << Line
             << "] " << endl;
      }
    } else if (Line.rfind('I', 0) == 0) {
      // Inventory command
      displayInventory();
    } else if (Line.rfind('H', 0) == 0) {
      // History command
      // H 1000
      int CustomerID = stoi(Tokens.at(1));
      displayHistory(CustomerID);
    } else {
      cout << "Error: Not a valid Command [Line " << LineNumber //<< ": " << Line
           << "] "  << endl;
    }
    LineNumber++;
  }
}

// Borrow Movie
void Store ::borrowMovie(int CustomerID, Movie *M) {
  if (M->getStock() == 0) {
    cout << "Error: Movie [" << M->getTitle() << "] is not in Stock" << endl;
  } else {
    Customer *Cust = CustomerList.findCustomerByID(CustomerID);
    if (Cust == nullptr) {
      cout << "Error: Cannot find Customer with ID " << CustomerID << endl;
    } else {
      Cust->borrowMovie(M);
    }
  }
}

// Return Movie
void Store ::returnMovie(int CustomerID, Movie *M) {
  Customer *Cust = CustomerList.findCustomerByID(CustomerID);
  if (Cust == nullptr) {
    cout << "Error: Cannot find Customer with ID " << CustomerID << endl;
  } else {
    Cust->returnMovie(M);
  }
}

// Display Inventory
void Store::displayInventory() { MovieTable.display(); }

// Display History
void Store::displayHistory(int CustomerID) {
  Customer *Cust = CustomerList.findCustomerByID(CustomerID);
  if (Cust == nullptr) {
    cout << "Error: Cannot find Customer with ID " << CustomerID << endl;
  } else {
    cout << "#############################" << endl;
    cout << "History for " << CustomerID << " " << Cust->getName() << endl;
    Cust->displayHistory();
    cout << "-----------------------------" << endl;
  }
}