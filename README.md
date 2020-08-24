# Movie Store

## Replace all TODO with actual information

Author(s): Srikar Duggempudi

GitHub URL: TODO

Expected Mark: TODO

## Checklist

Development Platform: Windows

Tested on CSS Linux Lab: Yes

Tested on Travis: Yes

clang-tidy messages:
```
/home/NETID/srikardu/CSS 343/uwb2020wi343b-movies-srikarduggempudi/hashtable.cpp:14:1: warning: constructor does not initialize these fields: CollectionTable [cppcoreguidelines-pro-type-member-init]
HashTable::HashTable() {
^
```
I decided to ignore this message because I initialized the HashTable in the .h file.

valgrind messages: None

## Command Functionality Checklist

For each command, state Full, Partial or None to indicate 
if it has been fully, partially or not implemented at all.
Explain any partial implementations.

Inventory: Full <br>
History: Full <br>
Borrow: Full <br>
Return: Full

## Location of error message or functionality

State the file and function where the information can be found

invalid command code: <br> Store.cpp/Store::loadCommandFile() 

invalid movie type: <br> Store.cpp/Store::loadMoviesFile()

invalid customer ID: <br> Store.cpp/Store::loadCustomerFile()
 
invalid movie: <br> Store.cpp/Store::loadMoviesFile()

factory classes: None

hashtable: <br> HashTable maps the Genre to the right Collection 

container used for comedy movies: <br> ComedyCollection/MovieCollection::MovieList

function for sorting comedy movies: <br> ComedyCollection/ComedyCollection::sortCollection()

function where comedy movies are sorted: <br> ComedyCollection/ComedyCollection::compareComedyMovies()

functions called when retrieving a comedy movie based on title and year: <br> ComedyCollection/ComedyCollection::findBy()

functions called for retrieving and printing customer history: <br> Store::displayHistory and then Customer::displayHistory()

container used for customer history: <br> Customer::History

functions called when borrowing a movie: <br> Store::borrowMovie() and then Customer::borrowMovie()

explain borrowing a movie that does not exist: <br> When executing borrow command we will parse the given Movie. If the movie does not exist, return an error. <br> Store::loadCommandsFile() 

explain borrowing a movie that has 0 stock: <br> Check whether the  Movie is in Stock <br> Store::borrowMovie()

explain returning a movie that customer has not checked out: <br> Check whether the Movie has been borrowed by the Customer <br> Customer::returnMovie()

any static_cast or dynamic_cast used: <br>  ClassicCollection::compareClassicMovies() <br> 
ClassicCollection::findBy()


