#pragma once
#include <iostream>
#include <string>
template <typename T>
T safeInput(T minInput, T maxInput) {
while (true)
{
T method;
std::cin >> method;
if (std::cin.fail() || method < minInput || method > maxInput)
{
std::cin.clear();
std::cout << "Invalid input.\n Try again: ";
}
else
{
std::cin.ignore(32767, '\n');
std::cin.clear();
return method;
}
std::cin.ignore(32767, '\n');
}
}
