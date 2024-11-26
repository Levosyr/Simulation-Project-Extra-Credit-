#ifndef SERVER_H
#define SERVER_H

#include "Customer.h"

class Server {
private:
    int serverID;
    bool isBusy;
    int transactionTime;
    Customer currentCustomer;

public:
    Server() : serverID(0), isBusy(false), transactionTime(0) {}
    void setServerID(int id) { serverID = id; }
    int getServerID() const { return serverID; }
    bool isServerBusy() const { return isBusy; }
    void setTransactionTime(int time) { transactionTime = time; }
    void assignCustomer(const Customer& customer) {
        currentCustomer = customer;
        isBusy = true;
    }
    void processTransaction() {
        if (isBusy) {
            transactionTime--;
            if (transactionTime <= 0) isBusy = false;
        }
    }
};

#endif
