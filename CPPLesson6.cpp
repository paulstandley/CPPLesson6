// CPPLesson6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Header.h"
#include <string>
#include <string_view>
#include <cstring> // For std::strlen
#include <cstddef> // for NULL std::nullptr_t
#include <iterator> // for std::size std::begin and std::end
#include <algorithm>


void pointer_to_symbolic_constant()
{
    const char *my_name1{ "Kerrin" }; // pointer to symbolic constant
    std::cout << my_name1 << '\n';
    const char *my_name_2{ "Louise" };
    const char *my_name_3{ "Louise" };
    std::cout << &my_name_2 << '\t' <<  &my_name_3 << '\n';
    std::cout << get_pointer_to_array() << '\n';
    char c{ 'Q' };
    std::cout << &c << '\n';
    // std::cout assumed &c (which has type char*)
    // was a string. So it printed the ‘Q’, and then kept going
}

const char* get_pointer_to_array()
{
    int nArray[5]{ 9, 7, 5, 3, 1 };
    char cArray[]{ "Hello!" };
    const char* name{ "Alex" };
    std::cout << "nArray will decay to type int* " << nArray << '\n'; // nArray will decay to type int*
    std::cout << "cArray will decay to type char* " << cArray << '\n'; // cArray will decay to type char*
    std::cout << "name is already type char* " << name << '\n'; // name is already type char*
    return "Melissa";
}


int main()
{
    pointer_to_symbolic_constant();


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
