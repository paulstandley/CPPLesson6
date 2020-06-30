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
#include <vector>
#include <array>

void std_array()
{
    //Introduced in C++11, std::array provides fixed array functionality that won’t decay 
    //when passed into a function. std::array is defined in the <array> header, 
    //inside the std namespace
    // declare an integer array with length 3
    std::array<int, 3> my_array1;
    std::array<int, 5> myArray2 = { 9, 7, 5, 3, 1 }; // initializer list
    std::array<int, 5> myArray3{ 9, 7, 5, 3, 1 }; // uniform initialization
    //Just like the native implementation of fixed arrays, 
    //the length of a std::array must be known at compile time.
    //std::array<int, > myArray{ 9, 7, 5, 3, 1 }; // illegal, array length must be provided
    //std::array<int> myArray{ 9, 7, 5, 3, 1 }; // illegal, array length must be provided
    //However, since C++17, it is allowed to omit the type and size. 
    //They can only be omitted together, but not one or the other, 
    //and only if the array is explicitly initialized.
    std::array myArray4{ 9, 7, 5, 3, 1 }; // The type is deduced to std::array<int, 5>
    std::array myArray5{ 9.7, 7.31 }; // The type is deduced to std::array<double, 2>
    std::array<int, 5> myArray6;
    myArray6 = { 0, 1, 2, 3, 4 }; // okay
    myArray6 = { 9, 8, 7 }; // okay, elements 3 and 4 are set to zero!
    //myArray6 = { 0, 1, 2, 3, 4, 5 }; // not allowed, too many elements in initializer list!
    std::cout << myArray6[1] << '\n';
    myArray6[2] = 6;
    //Just like built-in fixed arrays, the subscript operator does not do any bounds-checking.
    //If an invalid index is provided, bad things will probably happen.
    //std::array supports a second form of array element access 
    //(the at() function) that does bounds checking:
    std::array myArray7{ 9, 7, 5, 3, 1 };
    myArray7.at(1) = 6; // array element 1 is valid, sets array element 1 to value 6
    myArray7.at(9) = 10; // array element 9 is invalid, will throw an error
}

int main()
{
    std_array();

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
