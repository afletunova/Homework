#pragma once

#include <SFML/Network.hpp>
#include "Command.h"

/**
 * @brief
 * Responsible for all network manipulations
 */
class NetworkManager
{
public:
    virtual ~NetworkManager();

    /**
     * @brief
     * Sends command to the opponent by the network
     * @param command
     */
    virtual void send(const Command &command);

    /**
     * @brief
     * Tries to receive a command and if succeed then puts received command in the command variable
     * @param command
     * @return true if command has been received, false otherwise
     */
    virtual bool receive(Command &command);

protected:
    sf::TcpSocket *getSocket() const;

    void setSocket(sf::TcpSocket *socket);

private:
    sf::TcpSocket *socket;
    Command commandBuffer;
    int argumentsRead = 0;
};
