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


void vector_array()
{
	std::cout << "std::vector" << '\n';
	// Self-cleanup prevents memory leaks
	// no need to specify length at the declaration
	std::vector<int> array0;
	std::vector<int> array1;
	std::vector<int> array2 = { 9, 7, 5, 3, 1 }; 
	// use initializer list to initialize array (Before C++11)
	std::vector<int> array3{ 9, 7, 5, 3, 1 }; 
	// use uniform initialization to initialize array
	// as with std::array, the type can be omitted since C++17
	std::vector array4{ 9, 7, 5, 3, 1 }; 
	// deduced to std::vector<int>
	for (int i : array4)
		std::cout << i << ' ';
	std::cout << '\n';
	array2[4] = 2; // no bounds checking
	array3.at(2) = 3; // does bounds checking
	array0 = { 0, 1, 2, 3, 4 }; // okay, array length is now 5
	std::cout << "The length is: " << array0.size() << '\n';
	array1 = { 9, 8, 7 }; // okay, array length is now 3
	std::cout << "The length is: " << array1.size() << '\n';
	array1.resize(5); // set size to 5
	std::cout << "The length is: " << array1.size() << '\n';
	for (int i : array1)
		std::cout << i << ' ';
	std::cout << '\n';
	//Resizing a vector is computationally expensive, 
	//so you should strive to minimize the number of times you do so. 
	//If you need a vector with a specific number of elements
	//but don’t know the values of the elements at the point of declaration, 
	//you can create a vector with default elements like so
	// Using direct initialization, we can create a vector with 5 elements,
	// each element is a 0. If we use brace initialization, the vector would
	// have 1 element, a 5.
	std::vector<int> array5(5);
	std::cout << "The length is: " << array5.size() << '\n';
	for (int i : array5)
		std::cout << i << ' ';
	std::cout << '\n';
	//A rule of thumb is, if the type is some kind of list and 
	//you don’t want to initialize it with a list, use direct initialization.
	//std::vector has another cool trick up its sleeves. There is a special implementation 
	//for std::vector of type bool that will compact 8 booleans into a byte!
	//This happens behind the scenes, and doesn’t change how you use the std::vector
	std::vector<bool> array6{ true, false, false, true, true };
	std::cout << "The length is: " << array6.size() << '\n';
	for (int i : array6)
		std::cout << i << ' ';
	std::cout << '\n';
}


int main()
{
	vector_array();

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
