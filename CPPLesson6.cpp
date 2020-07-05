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

// Our function will return true if the element matches
bool containsNut(std::string_view str)
{
    // std::string_view::find returns std::string_view::npos if it doesn't find
    // the substring. Otherwise it returns the index where the substring occurs
    // in str.
    return (str.find("nut") != std::string_view::npos);
}

void std_algos()
{
    //The functionality provided in the algorithms library generally fall into one of three categories:

    //Inspectors -- Used to view(but not modify) data in a container
    //.Examples include searchingand counting.

    //Mutators -- Used to modify data in a container.
    //Examples include sortingand shuffling.

    //Facilitators -- Used to generate a result based on values of the data members.
    //Examples include objects that multiply values, 
    //or objects that determine what order pairs of elements should be sorted in.

    std::array arr1{ 13, 90, 99, 5, 40, 80 };

    std::cout << "Enter a value to search for and replace with: ";
    int search{};
    int replace{};
    std::cin >> search >> replace;

    // Input validation omitted

    // std::find returns an iterator pointing to the found element (or the end of the container)
    // we'll store it in a variable, using type inference to deduce the type of
    // the iterator (since we don't care)
    auto found1{ std::find(arr1.begin(), arr1.end(), search) };

    // Algorithms that don't find what they were looking for return the end iterator.
    // We can access it by using the end() member function.
    if (found1 == arr1.end())
    {
        std::cout << "Could not find " << search << '\n';
    }
    else
    {
        // Override the found element.
        *found1 = replace;
    }
    for (int i : arr1)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };
    // Scan our array to see if any elements contain the "nut" substring
    auto found{ std::find_if(arr.begin(), arr.end(), containsNut) };

    if (found == arr.end())
    {
        std::cout << "No nuts\n";
    }
    else
    {
        std::cout << "Found " << *found << '\n';
    }
    //If you were to write the above example by hand, 
    //you’d need at least two loops (one to loop through the array,
    //and one to match the substring). 
    //The standard library functions 
    //allow us to do the same thing in just a few lines of code!
}


int main()
{
    std_algos();

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
