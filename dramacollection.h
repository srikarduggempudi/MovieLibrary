/**
 * DramaCollection is a container that holds DramaMovie types
 *
 * @author Srikar Duggempudi
 * @date 10 March 2020
 */

#ifndef DRAMACOLLECTION_H
#define DRAMACOLLECTION_H

#include "moviecollection.h"
#include <string>
#include <vector>

using namespace std;

class DramaCollection : public virtual MovieCollection {
public:
  ~DramaCollection() override;
  // Find the Movie based on Movie's sorting attributes
  Movie *findBy(const string &Director, const string &Title);
  // Sort the collection based on Sorting order
  void sortCollection() override;

private:
};

#endif