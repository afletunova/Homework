#include "ServerNetworkManager.h"
#include <SFML/Network.hpp>
#include <iostream>

void ServerNetworkManager::start(int port)
{
    sf::TcpListener listener;
    listener.listen((unsigned short) port);
    sf::TcpSocket *socket = new sf::TcpSocket;
    setSocket(socket);
    listener.accept(*socket);

    std::cout << "IP: " << socket->getRemoteAddress() << std::endl;
}