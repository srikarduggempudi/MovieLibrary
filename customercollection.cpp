/**
 * CustomerCollection is a container that holds Customer types
 *
 * @author Srikar Duggempudi
 * @date 10 March 2020
 */

#include "customercollection.h"

CustomerCollection ::~CustomerCollection() {
  for (Customer *C : CustomerList) {
    delete C;
  }
}

// Add Customer
void CustomerCollection ::addCustomer(Customer *C) {
  CustomerList.push_back(C);
}

// Find Customer by Customer ID
Customer *CustomerCollection ::findCustomerByID(int CustomerID) {
  for (Customer *C : CustomerList) {
    if (C->getID() == CustomerID) {
      return C;
    }
  }
  return nullptr;
}
