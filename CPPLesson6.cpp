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



void for_each_loops_and_references()
{
	// In the following for-each example, our element declarations are declared by value
	std::string array1[]{ "peter", "likes", "frozen", "yogurt" };
	for (auto element : array1)
		std::cout << element << ' ';
	std::cout << '\n';
	// This means each array element iterated over will be copied into variable element. 
	// Copying array elements can be expensive, and most of the time we really 
	// just want to refer to the original element. 
	// Fortunately, we can use references for this
	for (auto &element : array1) 
		std::cout << element << ' ';
	std::cout << '\n';
	// The ampersand makes element a reference to the actual array element, 
	// preventing a copy from being made
	// In the above example, element will be a reference to the 
	// currently iterated array element, avoiding having to make a copy. 
	// Also any changes to element will affect the array being iterated over, 
	// something not possible if element is a normal variable.
	// And, of course, it’s a good idea to make your element const if you’re intending 
	// to use it in a read - only fashion
	for (const auto &element : array1) // element is a const reference to the currently iterated array element
		std::cout << element << ' ';
	// An array that decayed to a pointer cannot be used in a for-each loop
}

void for_each_loops_and_non_arrays()
{
	// note use of std::vector here rather than a fixed array
	std::vector fibonacci{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 }; 
	for (auto number : fibonacci)
		std::cout << number << ' ';
	std::cout << '\n';
	// For-each loops don’t only work with fixed arrays, they work with many kinds of list-like 
	// structures, such as vectors (e.g. std::vector), linked lists, trees, and maps.
	// We haven’t covered any of these yet, so don’t worry if you don’t know what these are. 
	// Just remember that for each loops provide a flexible and generic way to iterate 
	// through more than just arrays
	// For-each doesn’t work with pointers to an array
//#include <iostream>
//
//		int sumArray(int array[]) // array is a pointer
//	{
//		int sum{ 0 };
//
//		for (auto number : array) // compile error, the size of array isn't known
//			sum += number;
//
//		return sum;
//	}
//
//	int main()
//	{
//		int array[]{ 9, 7, 5, 3, 1 };
//
//		std::cout << sumArray(array) << '\n'; // array decays into a pointer here
//
//		return 0;
//	}
	// For-each loops do not provide a direct way to get the array index of the current 
	// element. This is because many of the structures that for-each loops can be used 
	// with (such as linked lists) are not directly indexable!
	// For - each loops provide a superior syntax for iterating through an array when we 
	// need to access all of the array elements in forwards sequential order.
	// It should be preferred over the standard for loop in the cases where it can be used.
	// To prevent making copies of each element, the element declaration should ideally
	// be a reference.
}



int main()
{
	
	for_each_loops_and_non_arrays();
	for_each_loops_and_references();

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
