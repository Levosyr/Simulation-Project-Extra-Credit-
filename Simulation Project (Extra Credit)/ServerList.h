#ifndef SERVERLIST_H
#define SERVERLIST_H

#include <vector>
#include "Server.h"

class ServerList {
private:
    std::vector<Server> servers;

public:
    void addServer(const Server& server) { servers.push_back(server); }
    int findFreeServer() const {
        for (size_t i = 0; i < servers.size(); ++i) {
            if (!servers[i].isServerBusy()) return static_cast<int>(i);
        }
        return -1; // No free server
    }
    void processServers() {
        for (auto& server : servers) {
            server.processTransaction();
        }
    }
    size_t getServerCount() const { return servers.size(); }

    Server& operator[](size_t index) { return servers[index]; }
    const Server& operator[](size_t index) const { return servers[index]; }
};

#endif
