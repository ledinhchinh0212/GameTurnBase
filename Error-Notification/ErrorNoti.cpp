#include "ErrorNoti.hpp"

void ErrorNoti::ErrorConsole(int num, std::string others)
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