/**
 * ClassicCollection is a container that holds ClassicMovie types
 *
 * @author Srikar Duggempudi
 * @date 10 March 2020
 */

#ifndef CLASSICCOLLECTION_H
#define CLASSICCOLLECTION_H

#include "moviecollection.h"
#include <string>
#include <vector>

using namespace std;

class ClassicCollection : public virtual MovieCollection {
public:
  ~ClassicCollection() override;
  // Find the Movie based on Movie's sorting attributes
  Movie *findBy(int ReleaseMonth, int ReleaseYear, const string &MajorActor);
  // Sort the collection based on Sorting order
  void sortCollection() override;

private:
};

#endif