#include "Date.hpp"

Date::Date(int day, int month, int year) : 
    day(day), month(month), year(year) {}

Date Date::RealDate() 
{
    auto now = std::chrono::system_clock::now();

    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    std::tm *localTime = std::localtime(&currentTime);

    int day = localTime->tm_mday;
    int month = localTime->tm_mon + 1; // (0 - 11)
    int year = localTime->tm_year + 1900; // tm_year -> 1900 (bat dau tu 1900s)
    return Date(day, month, year);
}

std::ostream &operator<<(std::ostream &out, const Date &date)
{
    out << date.day << "/" << date.month << "/" << date.year;
    return out;
}