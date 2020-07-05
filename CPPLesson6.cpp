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


void iterators()
{
    // The type is automatically deduced to std::array<int, 7> (Requires C++17).
    // Use the type std::array<int, 7> if your compiler doesn't support C++17.
    std::array data{ 0, 1, 2, 3, 4, 5, 6 };
    std::size_t length{ std::size(data) };

    // while-loop with explicit index
    std::size_t index{ 0 };
    while (index != length)
    {
        std::cout << data[index] << ' ';
        ++index;
    }
    std::cout << '\n';

    // for-loop with explicit index
    for (index = 0; index < length; ++index)
    {
        std::cout << data[index] << ' ';
    }
    std::cout << '\n';

    // for-loop with pointer (Note: ptr can't be const, because we increment it)
    for (auto ptr{ &data[0] }; ptr != (&data[0] + length); ++ptr)
    {
        std::cout << *ptr << ' ';
    }
    std::cout << '\n';

    // ranged-based for loop
    for (int i : data)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    //The simplest kind of iterator is a pointer, 
    //which (using pointer arithmetic) works for data stored sequentially in memory.
    //Let’s revisit a simple array traversal using a pointer and pointer arithmetic
    auto begin{ &data[0] };
    // note that this points to one spot beyond the last element
    auto end{ begin + std::size(data) };
    // for-loop with pointer
    for (auto ptr{ begin }; ptr != end; ++ptr) // ++ to move to next element
    {
        std::cout << *ptr << ' '; // dereference to get value of current element
    }
    std::cout << '\n';
    //defined two variables: begin (which points to the beginning of our container),
    //and end (which marks an end point). For arrays, 
    //the end marker is typically the place in memory where the last element
    //would be if the container contained one more element.
    //The pointer then iterates between begin and end, 
    //and the current element can be accessed by dereferencing the pointer.

    //int* end{ &array[std::size(array)] };
    //But this causes undefined behavior, because array[std::size(array)] 
    //accesses an element that is off the end of the array.
    //int *end{ &array[0] + std::size(array) };
    
    std::array array2{ 1, 2, 3 };
    // Ask our array for the begin and end points 
    //(via the begin and end member functions).
    auto begin1{ array2.begin() };
    auto end1{ array2.end() };
    for (auto p{ begin1 }; p != end1; ++p) // ++ to move to next element.
    {
        std::cout << *p << ' '; // dereference to get value of current element.
    }
    std::cout << '\n';

    std::array array3{ 1, 2, 3 };

    // Use std::begin and std::end to get the begin and end points.
    auto begin3{ std::begin(array3) };
    auto end3{ std::end(array3) };

    for (auto p{ begin3 }; p != end3; ++p) // ++ to move to next element
    {
        std::cout << *p << ' '; // dereference to get value of current element
    }
    std::cout << '\n';

    // This does exactly the same as the loop we used before.
    for (int i : array3)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    //Behind the scenes, 
    //the range-based for-loop calls begin() and end() 
    //of the type to iterate over. std::array has begin and end member functions, 
    //so we can use it in a range-based loop. 
    //C-style fixed arrays can be used with std::begin and std::end functions,
    //so we can loop through them with a range-based loop as well.
    //Dynamic arrays don’t work though, 
    //because there is no std::end function for them 
    //(because the type information doesn’t contain the array’s length)

    //Much like pointers and references, 
    //iterators can be left “dangling” if the elements being iterated over 
    //change address or are destroyed. 
    //When this happens, we say the iterator has been invalidated. 
    //Accessing an invalidated iterator produces undefined behavior.

    std::vector v{ 1, 2, 3, 4, 5, 6, 7 };
    auto it{ v.begin() };
    ++it; // move to second element
    std::cout << *it << '\n'; // ok: prints 2
    v.erase(it); // erase the element currently being iterated over
    // erase() invalidates iterators to the erased element (and subsequent elements)
    // so iterator "it" is now invalidated
    ++it; // undefined behavior
    std::cout << *it << '\n'; // undefined behavior
}


int main()
{
    iterators();

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
