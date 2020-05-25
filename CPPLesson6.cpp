// CPPLesson6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Header.h"
#include <string>
#include <string_view>
#include <cstring> // For std::strlen
#include <cstddef> // for NULL std::nullptr_t

void print_size_of1(int *array)
{
    // array is treated as a pointer here
    std::cout << sizeof(array) << '\n';
    // prints the size of a pointer, not the size of the array!
}

// C++ will implicitly convert parameter array[] to *array
void print_size_of2(int array[])
{
    // array is treated as a pointer here, not a fixed array
    std::cout << sizeof(array) << '\n'; 
    // prints the size of a pointer, not the size of the array!
}

void passing_fixed_arrays_to_functions()
{
    int array[]{ 1, 1, 2, 3, 5, 8, 13, 21 };
    std::cout << sizeof(array) << '\n'; // will print sizeof(int) * array length
    print_size_of1(array); // the array argument decays into a pointer here
    print_size_of2(array); // the array argument decays into a pointer here
}


int main()
{
    passing_fixed_arrays_to_functions();

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
