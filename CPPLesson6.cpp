// CPPLesson6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Header.h"
#include <string>
#include <string_view>
#include <cstring> // For std::strlen


void incomplete_implementation()
{
    std::string s{ "hello" };
    std::string_view v{ "world" };
    // Doesn't work
    //std::cout << (s + v) << '\n';
    //std::cout << (v + s) << '\n';
    // Potentially unsafe, or not what we want, because we're treating
    // the std::string_view as a C-style string.
    std::cout << (s + v.data()) << '\n';
    std::cout << (v.data() + s) << '\n';
    // Ok, but ugly and wasteful because we have to construct a new std::string.
    std::cout << (s + std::string{ v }) << '\n';
    std::cout << (std::string{ v } +s) << '\n';
    std::cout << (s + static_cast<std::string>(v)) << '\n';
    std::cout << (static_cast<std::string>(v) + s) << '\n';
}


int main()
{
    incomplete_implementation();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
