// CPPLesson6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Header.h"
#include <string>
#include <string_view>
#include <cstring> // For std::strlen
#include <cstddef> // for NULL std::nullptr_t


void pointer_arithmetic()
{
    int value1{ 7 };
    int *ptr1{ &value1 };

    std::cout << ptr1 << '\n';
    std::cout << ptr1 + 1 << '\n';
    std::cout << ptr1 + 2 << '\n';
    std::cout << ptr1 + 3 << '\n';

    short value2{ 7 };
    short *ptr2{ &value2 };

    std::cout << ptr2 << '\n';
    std::cout << ptr2 + 1 << '\n';
    std::cout << ptr2 + 2 << '\n';
    std::cout << ptr2 + 3 << '\n';

    int array1[]{ 9, 7, 5, 3, 1 };

    std::cout << "Element 0 is at address: " << &array1[0] << '\n';
    std::cout << "Element 1 is at address: " << &array1[1] << '\n';
    std::cout << "Element 2 is at address: " << &array1[2] << '\n';
    std::cout << "Element 3 is at address: " << &array1[3] << '\n';
}


int main()
{
    pointer_arithmetic();


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
