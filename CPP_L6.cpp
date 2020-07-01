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
#include <array>


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

void for_each_loops_and_the_auto_keyword()
{
	constexpr int fibonacci[]{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
	for (auto number : fibonacci) // type is auto, so number has its type deduced from the fibonacci array
		std::cout << number << ' ';
	std::cout << '\n';
}

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
	for (auto& element : array1)
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
	for (const auto& element : array1) // element is a const reference to the currently iterated array element
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
/*

void void_pointer()
{
	void* void_ptr;
	// A void pointer can point to objects of any data type
	int n_val;
	float f_val;
	struct Something
	{
		int n;
		float f;
	};
	Something s_val;
	void_ptr = &n_val;
	void_ptr = &f_val;
	void_ptr = &s_val;
	int value1{ 5 };
	void* void_ptr1{ &value1 };
	// std::cout << *voidPtr << '\n'; // illegal: cannot dereference a void pointer
	int* intPtr1{ static_cast<int*>(void_ptr1) }; // however, if we cast our void pointer to an int pointer...
	std::cout << *intPtr1 << '\n'; // then we can dereference it like normal
	void* ptr2{ nullptr }; // ptr is a void pointer that is currently a null pointer
	// A void pointer is a pointer that can point to any type of object, but does not know
	// what type of object it points to.
	// A void pointer must be explicitly cast into another type of pointer to be dereferenced.
	// A null pointer is a pointer that does not point to an address.
	// A void pointer can be a null pointer.
}

enum class Type
{
	INT,
	FLOAT,
	CSTRING,
};

void print_void_pointer_value(void* ptr, Type type)
{
	switch (type)
	{
	case Type::INT:
		std::cout << *static_cast<int*>(ptr) << '\n'; // cast to int pointer and dereference
		break;
	case Type::FLOAT:
		std::cout << *static_cast<float*>(ptr) << '\n'; // cast to float pointer and dereference
		break;
	case Type::CSTRING:
		std::cout << static_cast<char*>(ptr) << '\n'; // cast to char pointer (no dereference)
		// std::cout knows to treat char* as a C-style string
		// if we were to dereference the result, then we'd just print the single char that ptr is pointing to
		break;
	}
}

void void_pointer_value()
{
	int n_value{ 5 };
	float f_value{ 7.5f };
	char sz_value[]{ "Mollie" };
	print_void_pointer_value(&n_value, Type::INT);
	print_void_pointer_value(&f_value, Type::FLOAT);
	print_void_pointer_value(sz_value, Type::CSTRING);
}

*/

void pointer_to_pointer_c()
{
	// C
	int var = 789;
	// pointer for var 
	int *ptr2;
	// double pointer for ptr2 
	int **ptr1;
	// storing address of var in ptr2 
	ptr2 = &var;
	// Storing address of ptr2 in ptr1 
	ptr1 = &ptr2;
	// Displaying value of var using 
	// both single and double pointers 
	printf("Value of var = %d\n", var);
	printf("Value of var using single pointer = %d\n", *ptr2);
	printf("Value of var using double pointer = %d\n", **ptr1);
	std::cout << ptr1 << " ptr1 " << **ptr1 << " **ptr1 " << ptr2 << " ptr2 " << *ptr2 << " *ptr2\n";
}

void pointers()
{
	int value{ 5 };
	int* ptr = &value;
	std::cout << *ptr << '\n';
	int** ptrptr = &ptr;
	std::cout << **ptrptr;
}

/*Pointers to pointers and dynamic multidimensional arrays*/


void array_of_poniters()
{
	// allocate an array of 10 int pointers
	//int **array = new int *[10];
	//int **array = new int[10][5]; // won’t work!
	//There are two possible solutions here. If the rightmost array dimension is a compile-time 
	// constant, you can do this:
	//int(*array1)[5] = new int[10][5];
	//The parenthesis are required here to ensure proper precedence.In C++11 or newer, 
	//this is a good place to use automatic type deduction :
	//auto array2 = new int[10][5]; // so much simpler!
	//Unfortunately, this relatively simple solution doesn’t work if any non-leftmost array dimension
	//isn’t a compile-time constant. In that case, we have to get a little more complicated.
	//First, we allocate an array of pointers (as per above). Then we iterate through the array of
	//pointers and allocate a dynamic array for each array element. 
	//Our dynamic two-dimensional array is a dynamic one-dimensional array of dynamic one-dimensional
	//arrays!
	//int **array3 = new int *[10]; // allocate an array of 10 int pointers — these are our rows
	//for (int count = 0; count < 10; ++count)
	//    array3[count] = new int[5]; // these are our columns
	//array3[9][4] = 3; // This is the same as (array3[9])[4] = 3;
	//    int **array4 = new int *[10]; // allocate an array of 10 int pointers — these are our rows
	//for (int count = 0; count < 10; ++count)
	//    array[count] = new int[count + 1]; // these are our columns
	//Note that we delete the array in the opposite order that we created it 
	//(elements first, then the array itself). 
	//If we delete array before the array elements, 
	//then we’d have to access deallocated memory to delete the array elements. 
	//And that would result in undefined behavior.
	//for (int count = 0; count < 10; ++count)
	//    delete[] array4[count];
	//delete[] array4; // this needs to be done last
	// Instead of this:
	//int **array5 = new int *[10]; // allocate an array of 10 int pointers — these are our rows
	//for (int count = 0; count < 10; ++count)
	//    array5[count] = new int[5]; // these are our columns
	// Do this 
	//int *array6 = new int[50]; // a 10x5 array flattened into a single array
	// set array[9,4] to 3 using our flattened array
}

void std_array()
{
	//Introduced in C++11, std::array provides fixed array functionality that won’t decay 
	//when passed into a function. std::array is defined in the <array> header, 
	//inside the std namespace
	// declare an integer array with length 3
	std::array<int, 3> my_array1;
	std::array<int, 5> myArray2 = { 9, 7, 5, 3, 1 }; // initializer list
	std::array<int, 5> myArray3{ 9, 7, 5, 3, 1 }; // uniform initialization
	//Just like the native implementation of fixed arrays, 
	//the length of a std::array must be known at compile time.
	//std::array<int, > myArray{ 9, 7, 5, 3, 1 }; // illegal, array length must be provided
	//std::array<int> myArray{ 9, 7, 5, 3, 1 }; // illegal, array length must be provided
	//However, since C++17, it is allowed to omit the type and size. 
	//They can only be omitted together, but not one or the other, 
	//and only if the array is explicitly initialized.
	std::array myArray4{ 9, 7, 5, 3, 1 }; // The type is deduced to std::array<int, 5>
	std::array myArray5{ 9.7, 7.31 }; // The type is deduced to std::array<double, 2>
	std::array<int, 5> myArray6;
	myArray6 = { 0, 1, 2, 3, 4 }; // okay
	myArray6 = { 9, 8, 7 }; // okay, elements 3 and 4 are set to zero!
	//myArray6 = { 0, 1, 2, 3, 4, 5 }; // not allowed, too many elements in initializer list!
	std::cout << myArray6[1] << '\n';
	myArray6[2] = 6;
	//Just like built-in fixed arrays, the subscript operator does not do any bounds-checking.
	//If an invalid index is provided, bad things will probably happen.
	//std::array supports a second form of array element access 
	//(the at() function) that does bounds checking:
	std::array myArray7{ 9, 7, 5, 3, 1 };
	myArray7.at(1) = 6; // array element 1 is valid, sets array element 1 to value 6
	myArray7.at(9) = 10; // array element 9 is invalid, will throw an error
}

void size_and_sorting(const std::array<double, 5> &myArray)
{
	//note that we passed std::array by (const) reference. 
	//This is to prevent the compiler from making a copy of the std::array 
	//when the std::array was passed to the function (for performance reasons).
}

void display_std_array()
{
	std::array myArray{ 9.0, 7.2, 5.4, 3.6, 1.8 };
	std::cout << "length: " << myArray.size() << '\n';
	//Always pass std::array by reference or const reference
	std::sort(myArray.begin(), myArray.end()); // sort the array forwards
	//std::sort(myArray.rbegin(), myArray.rend()); // sort the array backwards
	for (int element : myArray)
		std::cout << element << ' ';
	std::cout << '\n';
	size_and_sorting(myArray);
}


