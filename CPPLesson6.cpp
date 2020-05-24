// CPPLesson6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Header.h"
#include <string>
#include <string_view>
#include <cstring> // For std::strlen


void reassign_pointer()
{
    int value1{ 5 };
    int value2{ 7 };
    int *ptr1{};
    ptr1 = &value1; // ponits to value1
    std::cout << "pointer to value 1 " << *ptr1 << '\n';// prints 5
    std::cout << "pointer address 1 " << ptr1 << '\n';// address
    std::cout << "reassign pointer\n";
    ptr1 = &value2;// points to value2
    std::cout << "pointer to value 1 " << *ptr1 << '\n';// prints 7
    std::cout << "pointer address 1 " << ptr1 << '\n';// address

    int value3{ 5 };
    int *ptr2{ &value3 }; // ptr2 points to value3
    *ptr2 = 15; // *ptr2 is the same as value3, which is assigned 15
    std::cout << value3 << '\n'; // prints 15

}


int main()
{
    reassign_pointer();

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
