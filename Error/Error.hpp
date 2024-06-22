#pragma once
#include <iostream>
#include "EnumError.hpp"

class Error
{
public:
    static void ErrorConsole(int num, std::string others = "");
};