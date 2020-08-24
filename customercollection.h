/**
 * CustomerCollection is a container that holds Customer types
 *
 * @author Srikar Duggempudi
 * @date 10 March 2020
 */

#ifndef CUSTOMERCOLLECTION_H
#define CUSTOMERCOLLECTION_H

#include "customer.h"
#include <map>
#include <string>
#include <vector>

using namespace std;

class CustomerCollection {
public:
  ~CustomerCollection();
  // Add Customer
  void addCustomer(Customer *C);
  // Find Customer by Customer ID
  Customer *findCustomerByID(int CustomerID);

private:
  vector<Customer *> CustomerList;
};

#endif