#pragma once
#include <stdlib.h>
#include <ctime>
#include <random>
#include <sstream>
#include <conio.h>
#include <iostream>
#include "../Error-Notification/EnumError.hpp"

double RandomDouble(int, int);
bool RandomDouble(double);

std::string FormatTime(int seconds);

void TypeToContinue(int flag = 0);