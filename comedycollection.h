/**
 * ComedyCollection is a container that holds ComedyMovie types
 *
 * @author Srikar Duggempudi
 * @date 10 March 2020
 */

#ifndef COMEDYCOLLECTION_H
#define COMEDYCOLLECTION_H

#include "moviecollection.h"
#include <string>
#include <vector>

using namespace std;

class ComedyCollection : public virtual MovieCollection {
public:
  ComedyCollection() = default;
  ~ComedyCollection() override;
  // Find the Movie based on Movie's sorting attributes
  Movie *findBy(const string &Title, int Year);
  // Sort the collection based on Sorting order
  void sortCollection() override;

private:
};

#endif