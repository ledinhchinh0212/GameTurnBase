#pragma once
#include <chrono>
#include <ctime>
#include <iostream>

class Date
{
private:
    int day, month, year;
public:
    Date() {};
    Date(int day, int month, int year);

    Date RealDate();

    friend std::ostream &operator<<(std::ostream &out, const Date &date);
};