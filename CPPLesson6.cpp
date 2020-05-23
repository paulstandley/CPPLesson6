// CPPLesson6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Header.h"
#include <string>
#include <string_view>
#include <cstring> // For std::strlen


void ponter_address_operator()
{
    int memory_address{ 5 };
    std::cout << memory_address << '\n'; // print the value of variable 
    std::cout << &memory_address << '\n'; // print the memory address of variable 
    // The dereference operator (*) allows us to access the value at a particular address:
    int x{ 5 };
    std::cout << x << '\n'; // print the value of variable x
    std::cout << &x << '\n'; // print the memory address of variable x
    std::cout << *(&x) << '\n'; /// print the value at the memory address of variable x
                                // (parenthesis not required, but make it easier to read)
    /*
    Pointer variables are declared just like normal variables, 
    only with an asterisk between the data type and the variable name. 
    Note that this asterisk is not a dereference. 
    It is part of the pointer declaration syntax.
    */

    int *iPtr_int{}; // a pointer to an integer value
    double *dPtr_double{}; // a pointer to a double value
    int* iPtr2{}; // also valid syntax (acceptable, but not favored)
    int * iPtr3{}; // also valid syntax (but don't do this, it looks like multiplication)
    int *iPtr4{}, *iPtr5{}; // declare two pointers to integer variables (not recommended)
    //int* do_somthing();This makes it clear that the function is returning a value of type int* and not an int
    // When declaring a pointer variable, put the asterisk next to the variable name
    // When declaring a function, put the asterisk of a pointer return value next to the type
    int v{ 5 };
    int *ptr{ &v }; // initialize ptr with address of variable v
    std::cout << &v << '\n'; // print the address of variable v
    std::cout << ptr << '\n'; // print the address that ptr is holding

    int iValue{ 5 };
    double dValue{ 7.0 };

    int* iPtr{ &iValue }; // ok
    double* dPtr{ &dValue }; // ok
    //iPtr = &dValue; 
    // wrong -- int pointer cannot point to the address of a double variable
    //dPtr = &iValue; 
    // wrong -- double pointer cannot point to the address of an int variable
    //int *ptr{ 5 }; // wrong pointers can only hold addresses
    //double *dPtr{ 0x0012FF7C };
    //C++ will also not allow you to directly convert literal memory addresses to a pointer
}


int main()
{
    ponter_address_operator();

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
