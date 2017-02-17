#pragma once

#include <string>

/**
 * @brief The Command class
 * It contains a data packet, which NetworkManager sends and receives
 */

class Command
{
public:
    Command(std::string name, int argumentsCount);
    Command();
    void addArgument(int argument, int index);

    int getArgument(int index) const;
    std::string getName() const;
    int getArgumentsCount() const;

    ~Command();

private:
    std::string name = "";
    int *arguments = nullptr;
    int argumentsCount = -1;

    void reInit();

    friend class NetworkManager;
};


