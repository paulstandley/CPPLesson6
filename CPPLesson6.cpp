// CPPLesson6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Header.h"
#include <string>
#include <string_view>
#include <cstring> // For std::strlen


void size_of_pointer()
{
    char *chPtr{}; // chars are 1 byte
    int *iPtr{}; // ints are usually 4 bytes
    struct Something
    {
        int x{};
        int y{};
        int z{};
    };
    Something *somethingPtr{}; // Something is probably 12 bytes
    std::cout << sizeof(chPtr) << '\n'; // prints 4
    std::cout << sizeof(iPtr) << '\n'; // prints 4
    std::cout << sizeof(somethingPtr) << '\n'; // prints 4
    /*
    Pointers are variables that hold a memory address. 
    They can be dereferenced using the dereference operator (*) 
    to retrieve the value at the address they are holding. 
    Dereferencing a garbage pointer may crash your application.
    */
}


int main()
{
    size_of_pointer();

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
