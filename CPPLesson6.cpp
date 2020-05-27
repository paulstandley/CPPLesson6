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


void pointer_to_const()
{
    int value1 = 5;
    const int* ptr1 = &value1; // ptr points to a const int
    int value2 = 6;
    ptr1 = &value2; // okay, ptr now points at some other const int
    // A const pointer is a pointer whose value can not be changed after initialization
    int value3 = 5;
    int *const ptr3 = &value3;
    // because the value being pointed to is still non-const, it is
    // possible to change the value being pointed to via dereferencing the const pointer:
    int value4 = 5;
    int *const ptr4 = &value4; // ptr4 will always point to value4
    *ptr4 = 6; // allowed, since ptr4 points to a non-const int
    // Const pointer to a const value
    // Finally, it is possible to declare a const pointer to a const value by using the 
    // const keyword both before the typeand before the variable name :
    int value5 = 5;
    const int *const ptr5 = &value5;
    // A const pointer to a const value can not be set to point to another address, 
    // nor can the value it is pointing to be changed through the pointer.
    /*
    1) A non-const pointer can be redirected to point to other addresses.

    2) A const pointer always points to the same address, 
    and this address can not be changed.

    3) A pointer to a non-const value can change the value it is pointing to. 
    These can not point to a const value.

    4) A pointer to a const value treats the value as const (even if it is not), 
    and thus can not change the value it is pointing to.
    */
    int value5 = 5;
    const int *ptr5 = &value5; 
    // ptr1 points to a "const int", so this is a pointer to a const value.
    int *const ptr6 = &value5; 
    // ptr2 points to an "int", so this is a const pointer to a non-const value.
    const int *const ptr7 = &value5; 
    // ptr3 points to a "const int", so this is a const pointer to a const value.
}




int main()
{
    make_dynamic_array();

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
