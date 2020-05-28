#include "pch.h"
#include <iostream>
#include "Header.h"
#include <string>
#include <string_view>
#include <cstring> // For std::strlen
#include <cstddef> // for NULL std::nullptr_t
#include <iterator> // for std::size std::begin and std::end
#include <algorithm>

void const_ref()
{
    int value = 5;
    const int& ref = value; // create const reference to variable value
    value = 6; // okay, value is non-const
    // ref = 7; // illegal -- ref is const
    std::cout << ref << '\n';// 6    
    const int& ref1 = 2 + 3; // normally the result of 2+3 has expression scope and is destroyed at the end of this statement
    // but because the result is now bound to a reference to a const value...
    std::cout << ref1 << '\n';  // we can use it here
    // and the lifetime of the r-value is extended to here, when the const reference dies
}

// ref is a const reference to the argument passed in, not a copy
void const_function(const int& ref)
{
    //ref = 6; // not allowed, ref is const
    std::cout << ref << '\n';
}

void print_it(const int& x)
{
    std::cout << x << '\n';
}

void print_const_function()
{
    // References to const values are particularly useful as function parameters because of their versatility. 
    // A const reference parameter allows you to pass in a non-const l-value argument, 
    // a const l-value argument, a literal, or the result of an expression
    int a = 1;
    print_it(a); // non-const l-value
    const int b = 2;
    print_it(b); // const l-value
    print_it(3); // literal r-value
    print_it(2 + b); // expression r-value
    // To avoid making unnecessary, potentially expensive copies, 
    // variables that are not pointers or fundamental data types (int, double, etc…) 
    // should be generally passed by (const) reference. 
    // Fundamental data types should be passed by value, 
    // unless the function needs to change them.
    //Rule: Pass non - pointer, non - fundamental data type variables(such as structs) by(const) reference.
}

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
	Person* ptr1 = &person1;
	(*ptr1).age = 4;
	(*ptr1).weight = 9;
	std::cout << person1.age << '\t' << person1.weight << '\n';
	// Note that the pointer dereference must be enclosed in parentheses, 
	// because the member selection operator has a higher precedence than the dereference operator
	// Because the syntax for access to structs and class members through a pointer is awkward,
	// C++ offers a second member selection operator (->) for doing member selection from pointers. 
	// The following two lines are equivalent
	(*ptr1).age = 725;
	ptr1->weight = 12.2;
	// This is not only easier to type, but is also much less prone to error because the dereference 
	// is implicitly done for you, so there are no precedence issues to worry about. 
	// Consequently, when doing member access through a pointer,
	// always use the -> operator instead of the . operator.
	// Rule: When using a pointer to access the value of a member, 
	// use operator-> instead of operator. (the . operator)
	std::cout << person1.age << '\t' << person1.weight << '\n';
}

void for_each_loops()
{
	// When this statement is encountered, the loop will iterate through each element in array,
	// assigning the value of the current array element to the variable declared in element_declaration.
	// For best results, element_declaration should have the same type as the array elements, 
	// otherwise type conversion will occur
	constexpr int fribonacci[]{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
	for (int number : fribonacci)// iterate over array fibonacci
	{
		std::cout << number << ' ';
		// we access the array element for this iteration through variable number
	}
	std::cout << '\n';
	// Note that variable number is not an array index. 
	// It’s assigned the value of the array element for the current loop iteration
}



