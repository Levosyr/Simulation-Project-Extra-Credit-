#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {
private:
    int customerID;
    int waitTime;

public:
    Customer() : customerID(0), waitTime(0) {}
    void setCustomerID(int id) { customerID = id; }
    int getCustomerID() const { return customerID; }
    void updateWaitTime() { waitTime++; }
    int getWaitTime() const { return waitTime; }
};

#endif
