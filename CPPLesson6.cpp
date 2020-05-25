// CPPLesson6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Header.h"
#include <string>
#include <string_view>
#include <cstring> // For std::strlen
#include <cstddef> // for NULL std::nullptr_t


void array_decay_to_address()
{
    int array[5]{ 9, 7, 5, 3, 1 };
    // print address of the array's first element
    std::cout << "Element 0 has address: " << &array[0] << '\n';
    // print the value of the pointer the array decays to
    std::cout << "The array decays to a pointer holding address: " << array << '\n';
}

void dereference_array_to_get_value_of_first_element()
{
    int array0[5]{ 9, 7, 5, 3, 1 };
    // dereferencing an array returns the first element (element 0)
    std::cout << "Dereferencing an array returns the first element " << *array0 << '\n'; // will print 9!
    char name[]{ "Paul" }; // C-style string (also an array)
    std::cout << "Char array first element dereference " << *name << '\n'; // will print 'P'
    /*
    Note that we’re not actually dereferencing the array itself. 
    The array (of type int[5]) gets implicitly converted into a pointer (of type int *), 
    and we dereference the pointer to get the value at the memory address the pointer 
    is holding (the value of the first element of the array).
    */
    int array1[5]{ 9, 7, 5, 3, 1 };
    std::cout << "Dereferencing an array returns the first element " << *array1 << '\n'; // will print 9
    int *ptr1{ array1 };
    std::cout << "Array1 decays into a pointer of type int * and our pointer(also of type int*) " << *ptr1 << '\n'; // will print 9
    /*
    This works because the array1 decays into a pointer of type int *, 
    and our pointer (also of type int *) has the same type
    */
    int array2[5]{ 9, 7, 5, 3, 1 };
    std::cout << "Sizeof(int) * array length " << sizeof(array2) << '\n'; // will print sizeof(int) * array length
    int *ptr2{ array2 };
    std::cout << "Size of a pointer " << sizeof(ptr2) << '\n'; // will print the size of a pointer
    /*
    The primary difference occurs when using the sizeof() operator. 
    When used on a fixed array, sizeof returns the size of the entire 
    array (array length * element size). 
    When used on a pointer, sizeof returns the size of a memory address (in bytes)
    A fixed array knows how long the array it is pointing to is. A pointer to the array does not
    
    The second difference occurs when using the address-of operator (&). 
    Taking the address of a pointer yields the memory address of the pointer variable.
    Taking the address of the array returns a pointer to the entire array. 
    This pointer also points to the first element of the array, but the type information is different 
    (in the above example, the type of &array is int(*)[5]). 
    It’s unlikely you’ll ever need to use this.
    */
}

int main()
{
    dereference_array_to_get_value_of_first_element();

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
