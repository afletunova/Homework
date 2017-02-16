#pragma once

#include <string>

/**
 * @brief The Command structure
 * It contains a data packet, which NetworkManager sends and receives
 */
struct Command
{
    ~Command()
    {
        if (arguments)
            delete[] arguments;
    }

    std::string name = "";
    int *arguments = nullptr;
    int argumentsCount = -1;

public:
    void reInit()
    {
        name = "";
        if (arguments)
            delete[] arguments;
        arguments = nullptr;
        argumentsCount = -1;
    }
};


