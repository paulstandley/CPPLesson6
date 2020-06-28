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


/*Pointers to pointers and dynamic multidimensional arrays*/


void array_of_poniters()
{
    // allocate an array of 10 int pointers
    int **array = new int *[10];
    //int **array = new int[10][5]; // won’t work!
    //There are two possible solutions here. If the rightmost array dimension is a compile-time 
    // constant, you can do this:
    int(*array1)[5] = new int[10][5];
    //The parenthesis are required here to ensure proper precedence.In C++11 or newer, 
    //this is a good place to use automatic type deduction :
    auto array2 = new int[10][5]; // so much simpler!
    //Unfortunately, this relatively simple solution doesn’t work if any non-leftmost array dimension
    //isn’t a compile-time constant. In that case, we have to get a little more complicated.
    //First, we allocate an array of pointers (as per above). Then we iterate through the array of
    //pointers and allocate a dynamic array for each array element. 
    //Our dynamic two-dimensional array is a dynamic one-dimensional array of dynamic one-dimensional
    //arrays!
    int **array3 = new int *[10]; // allocate an array of 10 int pointers — these are our rows
    for (int count = 0; count < 10; ++count)
        array3[count] = new int[5]; // these are our columns
    array3[9][4] = 3; // This is the same as (array3[9])[4] = 3;
        int **array4 = new int *[10]; // allocate an array of 10 int pointers — these are our rows
    for (int count = 0; count < 10; ++count)
        array[count] = new int[count + 1]; // these are our columns
    //Note that we delete the array in the opposite order that we created it 
    //(elements first, then the array itself). 
    //If we delete array before the array elements, 
    //then we’d have to access deallocated memory to delete the array elements. 
    //And that would result in undefined behavior.
    for (int count = 0; count < 10; ++count)
        delete[] array4[count];
    delete[] array4; // this needs to be done last
    // Instead of this:
    int **array5 = new int *[10]; // allocate an array of 10 int pointers — these are our rows
    for (int count = 0; count < 10; ++count)
        array5[count] = new int[5]; // these are our columns
    // Do this 
    int *array6 = new int[50]; // a 10x5 array flattened into a single array
    // set array[9,4] to 3 using our flattened array
    
}

int main()
{
    pointers();

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
