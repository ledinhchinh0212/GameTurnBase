#include "ErrorNoti.hpp"

void Error::ErrorConsole(int num, std::string others)
{
    if(others != "")
    {
        if(num == INVALID_INPUT)
        {
            std::cout << "Invalid Input\n";
        }
    }
    else 
    {
        std::cout << others << "\n";
    }
}