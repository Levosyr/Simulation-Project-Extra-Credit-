#include <iostream>
#include <cstdlib>
#include <ctime>
#include "CustomerQueue.h"
#include "ServerList.h"

void runSimulation(int simulationTime, int serverCount, int transactionTime, int arrivalInterval) {
    CustomerQueue customerQueue;
    ServerList serverList;

    for (int i = 0; i < serverCount; ++i) {
        Server server;
        server.setServerID(i + 1);
        serverList.addServer(server);
    }

    int currentTime = 0;
    int customerID = 1;
    int totalCustomers = 0;
    int completedTransactions = 0;

    while (currentTime < simulationTime) {
        // Simulate a customer arrival
        if (rand() % arrivalInterval == 0) {
            Customer customer;
            customer.setCustomerID(customerID++);
            customerQueue.addCustomer(customer);
            totalCustomers++;
        }

        // Process servers
        serverList.processServers();

        // Update customer wait times
        customerQueue.updateWaitTimes();

        // Assign customers to free servers
        int freeServerIndex = serverList.findFreeServer();
        while (freeServerIndex != -1 && !customerQueue.isEmpty()) {
            Customer customer = customerQueue.removeCustomer();
            Server& freeServer = serverList[freeServerIndex];
            freeServer.assignCustomer(customer);
            freeServer.setTransactionTime(transactionTime);
            completedTransactions++;
            freeServerIndex = serverList.findFreeServer();
        }

        currentTime++;
    }

    std::cout << "Simulation Results:\n";
    std::cout << "Total Customers Arrived: " << totalCustomers << "\n";
    std::cout << "Completed Transactions: " << completedTransactions << "\n";
    std::cout << "Customers Left in Queue: " << customerQueue.getQueueSize() << "\n";
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    int simulationTime = 100;   // Total time units
    int serverCount = 1;        // Number of servers
    int transactionTime = 5;    // Time taken for each transaction
    int arrivalInterval = 4;    // Average time between arrivals

    runSimulation(simulationTime, serverCount, transactionTime, arrivalInterval);

    return 0;
}
