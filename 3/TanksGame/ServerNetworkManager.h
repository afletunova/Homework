#pragma once

#include "NetworkManager.h"

class ServerNetworkManager : public NetworkManager
{
public:
    void start(int port);
};


