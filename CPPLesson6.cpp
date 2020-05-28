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


/*
Declare a fixed array with the following names: Alex, Betty, Caroline, Dave, Emily, 
Fred, Greg, and Holly. Ask the user to enter a name. Use a for each loop to see if the name 
the user entered is in the array.
*/

std::string quiz_get_name_string()
{
	while (true)
	{
		std::string name{};
		std::cout << "Enter a name: ";
		std::getline(std::cin, name);// get full string from cin
		if (std::cin.fail())
		{
			std::cin.clear();// reset cin
			std::cin.ignore(32767, '\n');// remove input
		}
		else
		{
			std::cin.ignore(32767, '\n');// remove input
			return name;
		}
	}
}

void quiz_array_for_each()
{
	const std::string string_array[]{ "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };
	bool in_array{ false };
	std::string name{ quiz_get_name_string() };
	std::cout << name << '\n';
	for (std::string elements : string_array)
	{
		if (elements == name)
		{
			std::cout << name << " was found." << '\n';
			in_array = true;
			break;
		}
	}
	if (in_array)
	{
		std::cout << name << " was found." << '\n';
	}
	else
	{
		std::cout << name << " was ont found." << '\n';
	}
}


int main()
{
	quiz_array_for_each();
	
	


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
