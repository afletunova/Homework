#pragma once

#include "NetworkManager.h"

class ClientNetworkManager : public NetworkManager
{
public:
    bool connect(const std::string &server, int port);
};

