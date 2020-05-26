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


void dynamic_memory_allocation()
{
    int *ptr{ new int }; 
    // dynamically allocate an integer and assign the address to ptr so we can access it later
    *ptr = 7; // assign value of 7 to allocated memory
    int *ptr1{ new int(5) }; // use direct initialization
    int *ptr2{ new int { 6 } }; // use uniform initialization
    std::cout << ptr << '\t' << ptr1 << '\t' << ptr2 << '\n';
    // assume ptr has previously been allocated with operator new
    // return the memory pointed to by ptr to the operating system
    // set ptr to be a null pointer (use nullptr instead of 0 in C++11)
    delete ptr, ptr1, ptr2;
    ptr = 0;
    ptr1 = 0;
    ptr2 = 0;
}

void dangling_pointer()
{
    int* ptr_1{ new int }; 
    // dynamically allocate an integer
    *ptr_1 = 7; 
    // put a value in that memory location
    delete ptr_1; 
    // return the memory to the operating system.  ptr is now a dangling pointer.
    //std::cout << *ptr_1; 
    // Dereferencing a dangling pointer will cause undefined behavior
    delete ptr_1; 
    // trying to deallocate the memory again will also lead to undefined behavior.

    int *ptr{ new int{} }; // dynamically allocate an integer
    int *other_ptr{ ptr }; // otherPtr is now pointed at that same memory location
    delete ptr; // return the memory to the operating system.  ptr and otherPtr are now dangling pointers.
    ptr = nullptr; // ptr is now a nullptr
    // however, otherPtr is still a dangling pointer!
    std::cout << other_ptr << '\n';

    int *value1{ new (std::nothrow) int{} }; // ask for an integer's worth of memory
    if (!value1) // handle case where new returned null
    {
        // Do error handling here
        std::cout << "Could not allocate memory";
    }
    int value2 = 5;
    int *ptr2{ new int{} }; // allocate memory
    ptr2 = &value2; // old address lost, memory leak results
    int value3 = 5;
    int *ptr3{ new int{} }; // allocate memory
    delete ptr3; // return memory back to operating system
    ptr3 = &value3; // reassign pointer to address of value
    int *ptr4{ new int{} };
    ptr4 = new int{}; // old address lost, memory leak results
    delete other_ptr;
    other_ptr = nullptr;
    delete value1;
    value1 = nullptr;
    delete ptr2;
    ptr2 = nullptr;
    delete ptr3;
    ptr3 = nullptr;
    delete ptr4;
    ptr4 = nullptr;

}



int main()
{
    dangling_pointer();


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
