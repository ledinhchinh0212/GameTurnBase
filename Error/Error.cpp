#include "Error.hpp"

void Error::ErrorConsole(int num)
{
    if(num == INVALID_INPUT)
    {
        std::cout << "Invalid Input\n";
    }
}