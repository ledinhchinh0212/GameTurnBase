#include "Utility.hpp"

double RandomDouble(int a, int b)
{
    static std::mt19937 generator(static_cast<unsigned>(std::time(nullptr)));
    std::uniform_real_distribution<double> distribution(static_cast<double>(a), static_cast<double>(b));
    double x = distribution(generator);
    
    return x;
}

bool RandomDouble(double block)
{
    return RandomDouble(0, 1) <= block; // crit rate effect
}