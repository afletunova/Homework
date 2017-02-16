#include "NetworkManager.h"

void NetworkManager::send(const Command &command)
{
    sf::Packet packet;
    packet << sf::String(command.name);
    packet << command.argumentsCount;
    for (int i = 0; i < command.argumentsCount; ++i)
        packet << command.arguments[i];
    socket->send(packet);
}

bool NetworkManager::receive(Command &command)
{
    sf::Packet packet;
    socket->receive(packet);

    if (commandBuffer.name == "")
    {
        sf::String sfString;
        if (packet >> sfString)
            commandBuffer.name = sfString.toAnsiString();
        else
            return false;
    }

    if (commandBuffer.argumentsCount == -1)
        if (packet >> commandBuffer.argumentsCount)
            commandBuffer.arguments = new int[commandBuffer.argumentsCount];
        else
            return false;

    while (argumentsRead < commandBuffer.argumentsCount)
    {
        if (packet >> commandBuffer.arguments[argumentsRead])
            argumentsRead++;
        else
            return false;
    }
    command.name = commandBuffer.name;
    command.argumentsCount = commandBuffer.argumentsCount;
    command.arguments = new int[command.argumentsCount];
    std::copy(commandBuffer.arguments, commandBuffer.arguments + commandBuffer.argumentsCount, command.arguments);
    commandBuffer.reInit();
    argumentsRead = 0;
    return true;
}

sf::TcpSocket *NetworkManager::getSocket() const
{
    return socket;
}

void NetworkManager::setSocket(sf::TcpSocket *socket)
{
    this->socket = socket;
    socket->setBlocking(false);
}

NetworkManager::~NetworkManager()
{
    if (socket)
        delete socket;
}
