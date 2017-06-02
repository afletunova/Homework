#pragma once

#include "NetworkManager.h"

class ClientNetworkManager : public NetworkManager
{
public:
    /**
     * @brief
     * Connects to the server by given credentials
     * @param server
     * @param port
     * @return
     */
    bool connect(const std::string &server, int port);
};

