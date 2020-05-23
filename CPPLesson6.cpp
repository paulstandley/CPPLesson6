// CPPLesson6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Header.h"
#include <string>
#include <string_view>

std::string_view ask_for_name()
{
    std::cout << "What's your name?\n";
    // Use a std::string, because std::cin needs to modify it.
    std::string str{};
    std::cin >> str;
    // We're switching to std::string_view for demonstrative purposes only.
    // If you already have a std::string, there's no reason to switch to
    // a std::string_view.
    std::string_view view{ str };
    std::cout << "Hello " << view << '\n';
    return view;
} // str dies, and so does the string that str created.

void ownership_issues()
{
    std::string_view view{ ask_for_name() };
    // view is observing a string that already died.
    std::cout << "Your name is " << view << '\n'; // Undefined behavior
    // Make sure that the underlying string viewed with a std::string_view 
    // does not go out of scope and isn’t modified while using the std::string_view.
}

int main()
{
    ownership_issues();

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
