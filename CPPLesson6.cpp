// CPPLesson6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Header.h"
#include <string>
#include <string_view>
#include <cstring> // For std::strlen
#include <cstddef> // for NULL std::nullptr_t



void null_pointers()
{
    float *ptr1{ 0 };  // ptr is now a null pointer
    float *ptr2; // ptr2 is uninitialized
    ptr2 = 0; // ptr2 is now a null pointer
    double *ptr3{ 0 };
    // pointers convert to boolean false if they are null, and boolean true if they are non-null
    if (ptr3)
        std::cout << "ptr is pointing to a double value.";
    else
        std::cout << "ptr is a null pointer.";
    double *ptr4{ NULL }; // ptr is a null pointer
    int *ptr5{ nullptr }; 
    // note: ptr is still an integer pointer, just set to a null value
}

void print(int x)
{
    std::cout << "print(int): " << x << '\n';
}

void print(int *x)
{
    if (!x)
        std::cout << "print(int*): null\n";
    else
        std::cout << "print(int*): " << *x << '\n';
}
void call_print()
{
    int *x1{ NULL };
    print(x1); // calls print(int*) because x has type int*
    print(0); // calls print(int) because 0 is an integer literal
    print(NULL); // likely calls print(int), although we probably wanted print(int*)
    int *x2{ nullptr };
    print(x2); // calls print(int*)
    print(nullptr); // calls print(int*) as desired
}

void doSomething(std::nullptr_t ptr)
{
    std::cout << "in doSomething()\n";
}


int main()
{
    doSomething(nullptr); // call doSomething with an argument of type std::nullptr_t

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
