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
#include <algorithm>// for std::sort
#include <vector>
#include <array>
#include <functional> // std::function
#include <utility>


bool greater(int a, int b)
{
    // Order @a before @b if @a is greater than @b.
    return (a > b);
}

void std_algos_count()
{
    std::array<std::string_view, 5> arr{ "apple", "banana", "walnut", "lemon", "peanut" };
    auto nuts{ std::count_if(arr.begin(), arr.end(), containsNut) };
    std::cout << "Counted " << nuts << " nut(s)\n";
 
    //There’s a version of std::sort that takes a function as its 
    //third parameter that allows us to sort however we like. 
    //The function takes two parameters to compare, 
    //and returns true if the first argument should be ordered before the second.
     //By default, std::sort sorts the elements in ascending order.
    std::array arr1{ 13, 90, 99, 5, 40, 80 };
    // Pass greater to std::sort
    std::sort(arr1.begin(), arr1.end(), greater);
    for (int i : arr1)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    //Our greater function needs 2 arguments, but we’re not passing it any, 
    //so where do they come from? When we use a function without parentheses (), 
    //it’s only a function pointer, not a call.
    //std::sort uses this pointer and calls the actual greater function
    //with any 2 elements of the array. 
    //We don’t know which elements greater will be called with, 
    //because it’s not defined which sorting algorithm std::sort is using under the hood.

    std::sort(arr.begin(), arr.end(), std::greater{});
    // use the standard library greater comparison
    // Before C++17, we had to specify the element type when we create std::greater
    std::sort(arr.begin(), arr.end(), std::greater<int>{}); 
    // use the standard library greater comparison
    //Note that the std::greater{} needs the curly braces because it is not a callable 
    //function. It’s a type, and in order to use it, 
    //we need to instantiate an object of that type.
    //The curly braces instantiate an anonymous object of that type
    //(which then gets passed as an argument to std::sort)
}


int main()
{
    std_algos_count();

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
