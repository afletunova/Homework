#pragma once

#include <SFML/Network.hpp>
#include "Command.h"

class NetworkManager
{
public:
    virtual ~NetworkManager();

    virtual void send(const Command &command);

    virtual bool receive(Command &command);

protected:
    sf::TcpSocket *getSocket() const;

    void setSocket(sf::TcpSocket *socket);

private:
    sf::TcpSocket *socket;
    Command commandBuffer;
    int argumentsRead = 0;

    sf::Clock clock;
};
