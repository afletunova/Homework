#include "Command.h"

Command::Command(std::string name, int argumentsCount) : name(name),
                                                         argumentsCount(argumentsCount),
                                                         arguments(new int[argumentsCount])
{

}

void Command::addArgument(int argument, int index)
{
    arguments[index] = argument;
}

int Command::getArgument(int index) const
{
    return arguments[index];
}

std::string Command::getName() const
{
    return name;
}

int Command::getArgumentsCount() const
{
    return argumentsCount;
}

Command::~Command()
{
    if (arguments)
        delete[] arguments;
}

void Command::reInit()
{
    name = "";
    if (arguments)
        delete[] arguments;
    arguments = nullptr;
    argumentsCount = -1;
}

Command::Command()
{}
