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


bool isVowel(char ch)
{
    switch (ch)
    {
    case 'A':
    case 'a':
    case 'E':
    case 'e':
    case 'I':
    case 'i':
    case 'O':
    case 'o':
    case 'U':
    case 'u':
        return true;
    default:
        return false;
    }
}

void pointer_iterate_array()
{
    char name1[]{ "Louise" };
    int arrayLength{ static_cast<int>(std::size(name1)) };
    int numVowels{ 0 };
    for (char *ptr1{ name1 }; ptr1 < (name1 + arrayLength); ++ptr1)
    {
        if (isVowel(*ptr1))
        {
            ++numVowels;
        }
    }
    std::cout << name1 << " has " << numVowels << " vowels.\n";
    numVowels =  0;
    char name2[]{ "Dollie" };
    auto numVowels{ std::count_if(std::begin(name2), std::end(name2), isVowel) };
    std::cout << name2 << " has " << numVowels << " vowels.\n";

    /*
    int arr[]{ 1, 2, 3 };
    std::cout << 2[arr] << '\n';
    arr[2]
    // same as
    *(arr + 2)
    // same as
    *(2 + arr)
    // same as
    2[arr]

#include <iostream>
#include <iterator>

int* find(int* begin, int* end, int value)
{
    for (int* p{ begin }; p != end; ++p)
    {
        if (*p == value)
        {
            return p;
        }
    }

    return end;
}

int main()
{
    int arr[]{ 2, 5, 4, 10, 8, 20, 16, 40 };

    int* found{ find(std::begin(arr), std::end(arr), 20) };

    if (found != std::end(arr))
    {
        std::cout << *found << '\n';
    }

    return 0;
}
    */
    int arr[]{ 2, 5, 4, 10, 8, 20, 16, 40 };

    // Note: std::find returns an iterator.
    auto found{ std::find(std::begin(arr), std::end(arr), 20) };

    if (found != std::end(arr))
    {
        std::cout << *found << '\n';
    }

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
