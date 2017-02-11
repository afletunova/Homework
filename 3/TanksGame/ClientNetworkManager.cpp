#include "ClientNetworkManager.h"

bool ClientNetworkManager::connect(const std::string &server, int port)
{
    sf::TcpSocket *socket = new sf::TcpSocket;
    if (socket->connect(server, (unsigned short) port) != sf::Socket::Done)
        return false;
    setSocket(socket);
    return true;
}
