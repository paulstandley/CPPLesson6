// CPPLesson6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Header.h"
#include <string>
#include <string_view>
#include <cstring> // For std::strlen


void string_data()
{
    std::string_view str1{ "jimbob" };
    std::cout << str1 << '\n';
    // We use std::strlen because it's simple, this could be any other function
    // that needs a null-terminated string.
    // It's okay to use data() because we haven't modified the view, and the
    // string is null-terminated.
    std::cout << std::strlen(str1.data()) << '\n';

    std::string_view str2{ "balloon" };
    // Remove the "b"
    str2.remove_prefix(1);
    // remove the "oon"
    str2.remove_suffix(3);
    // Remember that the above doesn't modify the string, it only changes
    // the region that str is observing.
    std::cout << str2 << " has " << std::strlen(str2.data()) << " letter(s)\n";
    std::cout << "str.data() is " << str2.data() << '\n';
    std::cout << "str is " << str2 << '\n';
    /*
    Only use std::string_view::data() if the std::string_view‘s view hasn’t been modified and
    the string being viewed is null-terminated. 
    Using std::string_view::data() of a non-null-terminated string can cause undefined behavior.
    */
}


int main()
{
    string_data();

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
