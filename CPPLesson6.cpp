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


/*
Write a program that:
* Asks the user how many names they wish to enter.
* Dynamically allocates a std::string array.
* Asks the user to enter each name.
* Calls std::sort to sort the names 
(See 6.4 -- Sorting an array using selection sort 
and 6.8a -- Pointer arithmetic and array indexing)
* Prints the sorted list of names.
std::string supports comparing strings via the comparison operators < and >.
You don’t need to implement string comparison by hand.
*/

int get_number_for_array()
{
    while (true)
    {
        int num{};
        std::cout << "How many names would you like to enter? ";
        std::cin >> num;
        if (std::cin.fail()) // has a previous extraction failed?
        {
            // yep, so let's handle the failure
            std::cin.clear(); // put us back in 'normal' operation mode
            std::cin.ignore(32767, '\n'); // and remove the bad input
            break;
        }
        else // else our extraction succeeded
        {
            std::cin.ignore(32767, '\n'); // clear (up to 32767) characters out of the buffer until a '\n' character is removed
            return num; // so return the value we extracted
        }
    }
}

std::string get_names_from_user(int num)
{
    while (true)
    {
        std::cout << "Enter name # " << num + 1 << " " ;
        std::string name{};
        std::getline(std::cin, name);
        if (std::cin.fail()) // has a previous extraction failed?
        {
            // yep, so let's handle the failure
            std::cin.clear(); // put us back in 'normal' operation mode
            std::cin.ignore(32767, '\n'); // and remove the bad input
            break;
        }
        else // else our extraction succeeded
        {
            std::cin.ignore(32767, '\n'); // clear (up to 32767) characters out of the buffer until a '\n' character is removed
            return name; // so return the value we extracted
        }
    }
}

void print_user_names(std::string *name, int num)
{
    std::cout << "Here is your sorted list\n\n";
    for (int index = 0; index < num; index++)
    {
        std::cout << "Name #" << index + 1 << ": " << name[index] << '\n';
    }
}

void make_dynamic_array()
{
    int length{ get_number_for_array() };
    // Allocate an array to hold the names
    auto *names{ new std::string[static_cast<std::size_t>(length)]{} };
    for (int index = 0; index < length; ++index)
    {
        names[index] = get_names_from_user(index);
    }
    std::sort(names, names + length);
    print_user_names(names, length);
    delete[] names;
    names = nullptr;
}


int main()
{
    make_dynamic_array();

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
