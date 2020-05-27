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


// Note: You need to specify the array size in the function declaration
void print_elements(int(&arr)[4])
{
    // Note that in order for this to work, 
    // you explicitly need to define the array size in the parameter
    int length{ static_cast<int>(std::size(arr)) }; 
    // we can now do this since the array won't decay
    for (int i{ 0 }; i < length; ++i)
    {
        std::cout << arr[i] << '\n';
    }
}

void using_references_to_pass_c_style_arrays_to_functions()
{
    // One of the most annoying issues with C-style arrays is that in most cases they decay
    // to pointers when evaluated. 
    // However, if a C-style array is passed by reference, this decaying does not happen
    int arr[]{ 99, 20, 14, 80 };
    print_elements(arr);
}

// reference for short cuts
struct Something
{
    int value1;
    float value2;
};

struct Other
{
    Something something;
    int otherValue;
};

void ref_as_shotcut()
{
    Other other;
    int& ref{ other.something.value1 };
    // ref can now be used in place of other.something.value1
}

void references_vs_pointers() 
{
    // If a given task can be solved with either a reference or a pointer, 
    // the reference should generally be preferred.
    // Pointers should only be used in situations where references are not sufficient
    // (such as dynamically allocating memory)
    int value{ 5 };
    int *const ptr{ &value };
    int &ref{ value };
    *ptr = 5;
    ref = 5;
    // References allow us to define aliases to other objects or values. 
    // References to non-const values can only be initialized with non-const l-values. 
    // References can not be reassigned once initialized.
    // References are most often used as function parameters when we either want to modify
    // the value of the argument, 
    // or when we want to avoid making an expensive copy of the argument.
}

int main()
{
    

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
