#ifndef CUSTOMERQUEUE_H
#define CUSTOMERQUEUE_H

#include <queue>
#include "Customer.h"

class CustomerQueue {
private:
    std::queue<Customer> queue;

public:
    void addCustomer(const Customer& customer) { queue.push(customer); }
    Customer removeCustomer() {
        Customer frontCustomer = queue.front();
        queue.pop();
        return frontCustomer;
    }
    bool isEmpty() const { return queue.empty(); }
    int getQueueSize() const { return queue.size(); }
    void updateWaitTimes() {
        std::queue<Customer> tempQueue;
        while (!queue.empty()) {
            Customer customer = queue.front();
            customer.updateWaitTime();
            tempQueue.push(customer);
            queue.pop();
        }
        queue = tempQueue;
    }
};

#endif
