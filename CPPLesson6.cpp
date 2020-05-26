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


void dynamically_allocate_arrays_of_variables()
{
    std::cout << "Enter a postitive integer: ";
    int length{};
    std::cin >> length;
    // use array new.  Note that length does not need to be constant!
    int *array{ new int[length] };
    std::cout << "I just allocated an array of integers of length " << length << '\n';
    array[0] = 5;
    int *array1{ new int[5]{ 9, 7, 5, 3, 1 } }; // initialize a dynamic array in C++11
    delete[] array;
    array = nullptr;
    delete[] array1;
}



int main()
{
    dynamically_allocate_arrays_of_variables();

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
