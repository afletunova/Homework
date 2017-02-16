#pragma once

#include "NetworkManager.h"

class ServerNetworkManager : public NetworkManager
{
public:
    /**
     * @brief
     * Starts server on the given port
     * @param port
     */
    void start(int port);
};


