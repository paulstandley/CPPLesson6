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

void member_selection_with_pointersand_references()
{
	struct Person
	{
		int age;
		double weight;
	};
	Person person;
	// Member selection using actual struct variable
	person.age = 5;
	person.weight = 10;
	std::cout << person.age << '\t' << person.weight << '\n';
	Person person1;
	// Member selection using pointer to struct
	Person *ptr1 = &person1;
	(*ptr1).age = 4;
	(*ptr1).weight = 9;
	std::cout << person1.age << '\t' << person1.weight << '\n';
	// Note that the pointer dereference must be enclosed in parentheses, 
	// because the member selection operator has a higher precedence than the dereference operator
	// Because the syntax for access to structs and class members through a pointer is awkward,
	// C++ offers a second member selection operator (->) for doing member selection from pointers. 
	// The following two lines are equivalent
	(*ptr1).age = 725;
	ptr1->age = 12.2;
	// This is not only easier to type, but is also much less prone to error because the dereference 
	// is implicitly done for you, so there are no precedence issues to worry about. 
	// Consequently, when doing member access through a pointer,
	// always use the -> operator instead of the . operator.
	// Rule: When using a pointer to access the value of a member, 
	// use operator-> instead of operator. (the . operator)
	std::cout << person1.age << '\t' << person1.weight << '\n';
}


int main()
{
	member_selection_with_pointersand_references();

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
