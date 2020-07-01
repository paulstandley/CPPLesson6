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

struct House
{
	int number{};
	int stories{};
	int roomsPerStory{};
};

struct ArrayStruct
{
	int value[3]{};
};

struct ArrayHouse
{
	// This is now an array of House
	House value[3]{};
};

void array_of_struct()
{
	std::array<House, 3> houses{};
	houses[0] = { 13, 4, 30 };
	houses[1] = { 14, 3, 10 };
	houses[2] = { 15, 3, 40 };

	for (const auto& house : houses)
	{
		std::cout << "House number " << house.number
			<< " has " << (house.stories * house.roomsPerStory)
			<< " rooms\n";
	}
	//However, things get a little weird when we try to initialize the array.
	// Doesn't work.
	//std::array<House, 3> houses{
	//	{ 13, 4, 30 },
	//	{ 14, 3, 10 },
	//	{ 15, 3, 40 }
	//};

	//Although we can initialize std::array like this if its elements are simple types, 
	//like int or std::string, 
	//it doesn't work with types that need multiple values to be created.
	//Let's have a look at why this is the case.
	//std::array is an aggregate type, just like House.There is no special function for
	//the creation of a std::array.Rather, 
	//its internal array gets initialized like any other member variable of a struct.
	//To make this easier to understand, we'll implement a simple array type ourselves.
	ArrayStruct array1{
		11,
		12,
		13
	};
	//As expected, this works. So does std::array if we use it with int elements. 
	//When we instantiate a struct, we can initialize all of its members. 
	//If we try to create an Array of Houses, we get an error.
	// If we try to initialize the array, we get an error.
	ArrayHouse houses1{
	{ 13, 4, 30 }, // value[0]
	//{ 14, 3, 10 }, // value[1] ?????
	//{ 15, 3, 40 }  // value[2] ?????
	};
	//The first pair of inner braces initializes value, 
	//because value is the first member of Array.Without the other two pairs of braces,
	//there would be one house with number 13, 4 stories, and 30 rooms per story.

	//Braces can be omitted during aggregate initialization:
	//struct S
	//{
	//	int arr[3]{};
	//	int i{};
	//};

	// These two do the same
	//S s1{ { 1, 2, 3 }, 4 };
	//S s2{ 1, 2, 3, 4 };

	//To initialize all houses, we need to do so in the first pair of braces.
	ArrayHouse houses2{
	{ 13, 4, 30, 14, 3, 10, 15, 3, 40 }, // value
	};
	//This works, but it's very confusing. 
	//So confusing that your compiler might even warn you about it. 
	//If we add braces around each element of the array, 
	//the initialization is a lot easy to read.
	// With braces, this works.
	ArrayHouse houses3{
		{ { 13, 4, 30 }, { 14, 3, 10 }, { 15, 3, 40 } }
	};
	for (const auto& house : houses3.value)
	{
		std::cout << "House number " << house.number
			<< " has " << (house.stories * house.roomsPerStory)
			<< " rooms\n";
	}
	//This is why you'll see an extra pair of braces in initializations of std::array.
	//std::array is a great replacement for built-in fixed arrays. 
	//It's efficient, in that it doesn’t use any more memory than built-in fixed arrays.
	//The only real downside of a std::array over a built-in fixed 
	//array is a slightly more awkward syntax, 
	//that you have to explicitly specify the array length 
	//(the compiler won’t calculate it for you from the initializer, 
	//unless you also omit the type, which isn't always possible),
	//and the signed/unsigned issues with size and indexing. 
	//But those are comparatively minor quibbles — we recommend using 
	//std::array over built-in fixed arrays for any non-trivial array use.
}


int main()
{
	array_of_struct();

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
