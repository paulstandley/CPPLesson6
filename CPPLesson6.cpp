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


void references_to_non_const_values()
{
    int value1{ 5 };// normal integer
    int &ref1{ value1 };// referance to variable value
    // In this context, the ampersand does not mean “address of”, it means “reference to”
    value1 = 6;
    std::cout << ref1 << '\n';
    --ref1;
    std::cout << ref1 << ' ' << value1 << '\n';
    std::cout << &ref1 << ' ' << &value1 << '\n';// same address
    // r value
    int y;      // define y as an integer variable
    y = 4;      // 4 evaluates to 4, which is then assigned to y
    y = 2 + 5;  // 2 + 5 evaluates to 7, which is then assigned to y

    int x;      // define x as an integer variable
    x = y;      // y evaluates to 7 (from before), which is then assigned to x.
    x = x;      // x evaluates to 7, which is then assigned to x (useless!)
    x = x + 1;  // x + 1 evaluates to 8, which is then assigned to x.
    // In this statement, the variable x is being used in two different contexts. 
    // On the left side of the assignment operator, “x” is being used as an l-value 
    // (variable with an address). 
    // On the right side of the assignment operator, x is being used as an r-value, 
    // and will be evaluated to produce a value (in this case, 7).
    //Unlike pointers, which can hold a null value, there is no such thing as a null reference.
    // References to non - const values can only be initialized with non - const l - values.
    // They can not be initialized with const l - values or r - values.
    //const int y{ 7 };
    //int& ref2{ y }; // not okay, y is a const l-value
    //int& ref3{ 6 }; // not okay, 6 is an r-value
    int value2{ 5 };
    int value3{ 6 };
    int& ref2{ value2 }; // okay, ref is now an alias for value1
    ref2 = value3; // assigns 6 (the value of value2) to value1 
    //-- does NOT change the reference it assigns the value of value2 to value3
}



int main()
{
    references_to_non_const_values();

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
