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
#include <functional> // std::function
#include <utility>


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
    // variables that are not pointers or fundamental data types (int, double, etc�) 
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
	// It�s assigned the value of the array element for the current loop iteration
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
	// And, of course, it�s a good idea to make your element const if you�re intending 
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
	// For-each loops don�t only work with fixed arrays, they work with many kinds of list-like 
	// structures, such as vectors (e.g. std::vector), linked lists, trees, and maps.
	// We haven�t covered any of these yet, so don�t worry if you don�t know what these are. 
	// Just remember that for each loops provide a flexible and generic way to iterate 
	// through more than just arrays
	// For-each doesn�t work with pointers to an array
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
	//int **array = new int[10][5]; // won�t work!
	//There are two possible solutions here. If the rightmost array dimension is a compile-time 
	// constant, you can do this:
	//int(*array1)[5] = new int[10][5];
	//The parenthesis are required here to ensure proper precedence.In C++11 or newer, 
	//this is a good place to use automatic type deduction :
	//auto array2 = new int[10][5]; // so much simpler!
	//Unfortunately, this relatively simple solution doesn�t work if any non-leftmost array dimension
	//isn�t a compile-time constant. In that case, we have to get a little more complicated.
	//First, we allocate an array of pointers (as per above). Then we iterate through the array of
	//pointers and allocate a dynamic array for each array element. 
	//Our dynamic two-dimensional array is a dynamic one-dimensional array of dynamic one-dimensional
	//arrays!
	//int **array3 = new int *[10]; // allocate an array of 10 int pointers � these are our rows
	//for (int count = 0; count < 10; ++count)
	//    array3[count] = new int[5]; // these are our columns
	//array3[9][4] = 3; // This is the same as (array3[9])[4] = 3;
	//    int **array4 = new int *[10]; // allocate an array of 10 int pointers � these are our rows
	//for (int count = 0; count < 10; ++count)
	//    array[count] = new int[count + 1]; // these are our columns
	//Note that we delete the array in the opposite order that we created it 
	//(elements first, then the array itself). 
	//If we delete array before the array elements, 
	//then we�d have to access deallocated memory to delete the array elements. 
	//And that would result in undefined behavior.
	//for (int count = 0; count < 10; ++count)
	//    delete[] array4[count];
	//delete[] array4; // this needs to be done last
	// Instead of this:
	//int **array5 = new int *[10]; // allocate an array of 10 int pointers � these are our rows
	//for (int count = 0; count < 10; ++count)
	//    array5[count] = new int[5]; // these are our columns
	// Do this 
	//int *array6 = new int[50]; // a 10x5 array flattened into a single array
	// set array[9,4] to 3 using our flattened array
}

void std_array()
{
	//Introduced in C++11, std::array provides fixed array functionality that won�t decay 
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

//Manually indexing std::array via size_type
void std_array_wrong()
{
	//Pop quiz: What�s wrong with the following code?
	std::array myArray{ 7, 3, 1, 9, 5 };
	// Iterate through the array and print the value of the elements
	for (int i{ 0 }; i < myArray.size(); ++i)
		std::cout << myArray[i] << ' ';
	std::cout << '\n';
	//The answer is that there�s a likely signed/unsigned mismatch
	//in this code! Due to a curious decision, the size() 
	//function and array index parameter to operator[] use a type called size_type,
	//which is defined by the C++ standard as an unsigned integral type.

	//Our loop counter/index (variable i) is a signed int. 
	//Therefore both the comparison i < myArray.size() 
	//and the array index myArray[i] have type mismatches.
	std::array myArray1{ 7, 3, 1, 9, 5 };
	// std::array<int, 5>::size_type is the return type of size()!
	for (std::array<int, 5>::size_type i{ 0 }; i < myArray1.size(); ++i)
		std::cout << myArray1[i] << ' ';
	std::cout << '\n';
	//That's not very readable. Fortunately, std::array::size_type is just an 
	//alias for std::size_t, so we can use that instead.
	std::array myArray2{ 7, 3, 1, 9, 5 };
	for (std::size_t i{ 0 }; i < myArray2.size(); ++i)
		std::cout << myArray2[i] << ' ';
	std::cout << '\n';
	//A better solution is to avoid manual indexing of std::array in the first place.
	//Instead, use range-based for-loops (or iterators) if possible.

	//Keep in mind that unsigned integers wrap around when you reach their limits.
	//A common mistake is to decrement an index that is 0 already, 
	//causing a wrap - around to the maximum value.

	//std::array myArray{ 7, 3, 1, 9, 5 };
	// Print the array in reverse order.
	// We can use auto, because we're not initializing i with 0.
	// Bad:
	//for (auto i{ myArray.size() - 1 }; i >= 0; --i)
	//    std::cout << myArray[i] << ' ';
	//std::cout << '\n';

	//This is an infinite loop, producing undefined behavior once i wraps around.
	//There are two issues here. If `myArray` is empty, ie. 
	//size() returns 0 (which is possible with std::array), 
	//myArray.size() - 1 wraps around. 
	//The other issue occurs no matter how many elements there are. 
	//i >= 0 is always true, because unsigned integers cannot be less than 0.

	std::array myArray3{ 7, 3, 1, 9, 5 };
	// Print the array in reverse order.
	for (auto i{ myArray3.size() }; i-- > 0; )
		std::cout << myArray3[i] << ' ';
	std::cout << '\n';
	//Suddenly we decrement the index in the condition, and we use the postfix-- operator.
	//The condition runs before every iteration, including the first.
	//In the first iteration, i is myArray.size() - 1, 
	//because i was decremented in the condition.
	//When i is 0 and about to wrap around,
	//the condition is no longer true and the loop stops.
	//i actually wraps around when we do i-- for the last time, 
	//but it's not used afterwards.
}

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
	//It's efficient, in that it doesn�t use any more memory than built-in fixed arrays.
	//The only real downside of a std::array over a built-in fixed 
	//array is a slightly more awkward syntax, 
	//that you have to explicitly specify the array length 
	//(the compiler won�t calculate it for you from the initializer, 
	//unless you also omit the type, which isn't always possible),
	//and the signed/unsigned issues with size and indexing. 
	//But those are comparatively minor quibbles � we recommend using 
	//std::array over built-in fixed arrays for any non-trivial array use.
}

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
	//but don�t know the values of the elements at the point of declaration, 
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
	//you don�t want to initialize it with a list, use direct initialization.
	//std::vector has another cool trick up its sleeves. There is a special implementation 
	//for std::vector of type bool that will compact 8 booleans into a byte!
	//This happens behind the scenes, and doesn�t change how you use the std::vector
	std::vector<bool> array6{ true, false, false, true, true };
	std::cout << "The length is: " << array6.size() << '\n';
	for (int i : array6)
		std::cout << i << ' ';
	std::cout << '\n';
}

void iterators()
{
	// The type is automatically deduced to std::array<int, 7> (Requires C++17).
	// Use the type std::array<int, 7> if your compiler doesn't support C++17.
	std::array data{ 0, 1, 2, 3, 4, 5, 6 };
	std::size_t length{ std::size(data) };

	// while-loop with explicit index
	std::size_t index{ 0 };
	while (index != length)
	{
		std::cout << data[index] << ' ';
		++index;
	}
	std::cout << '\n';

	// for-loop with explicit index
	for (index = 0; index < length; ++index)
	{
		std::cout << data[index] << ' ';
	}
	std::cout << '\n';

	// for-loop with pointer (Note: ptr can't be const, because we increment it)
	for (auto ptr{ &data[0] }; ptr != (&data[0] + length); ++ptr)
	{
		std::cout << *ptr << ' ';
	}
	std::cout << '\n';

	// ranged-based for loop
	for (int i : data)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';

	//The simplest kind of iterator is a pointer, 
	//which (using pointer arithmetic) works for data stored sequentially in memory.
	//Let�s revisit a simple array traversal using a pointer and pointer arithmetic
	auto begin{ &data[0] };
	// note that this points to one spot beyond the last element
	auto end{ begin + std::size(data) };
	// for-loop with pointer
	for (auto ptr{ begin }; ptr != end; ++ptr) // ++ to move to next element
	{
		std::cout << *ptr << ' '; // dereference to get value of current element
	}
	std::cout << '\n';
	//defined two variables: begin (which points to the beginning of our container),
	//and end (which marks an end point). For arrays, 
	//the end marker is typically the place in memory where the last element
	//would be if the container contained one more element.
	//The pointer then iterates between begin and end, 
	//and the current element can be accessed by dereferencing the pointer.

	//int* end{ &array[std::size(array)] };
	//But this causes undefined behavior, because array[std::size(array)] 
	//accesses an element that is off the end of the array.
	//int *end{ &array[0] + std::size(array) };

	std::array array2{ 1, 2, 3 };
	// Ask our array for the begin and end points 
	//(via the begin and end member functions).
	auto begin1{ array2.begin() };
	auto end1{ array2.end() };
	for (auto p{ begin1 }; p != end1; ++p) // ++ to move to next element.
	{
		std::cout << *p << ' '; // dereference to get value of current element.
	}
	std::cout << '\n';

	std::array array3{ 1, 2, 3 };

	// Use std::begin and std::end to get the begin and end points.
	auto begin3{ std::begin(array3) };
	auto end3{ std::end(array3) };

	for (auto p{ begin3 }; p != end3; ++p) // ++ to move to next element
	{
		std::cout << *p << ' '; // dereference to get value of current element
	}
	std::cout << '\n';

	// This does exactly the same as the loop we used before.
	for (int i : array3)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';
	//Behind the scenes, 
	//the range-based for-loop calls begin() and end() 
	//of the type to iterate over. std::array has begin and end member functions, 
	//so we can use it in a range-based loop. 
	//C-style fixed arrays can be used with std::begin and std::end functions,
	//so we can loop through them with a range-based loop as well.
	//Dynamic arrays don�t work though, 
	//because there is no std::end function for them 
	//(because the type information doesn�t contain the array�s length)

	//Much like pointers and references, 
	//iterators can be left �dangling� if the elements being iterated over 
	//change address or are destroyed. 
	//When this happens, we say the iterator has been invalidated. 
	//Accessing an invalidated iterator produces undefined behavior.

	std::vector v{ 1, 2, 3, 4, 5, 6, 7 };
	auto it{ v.begin() };
	++it; // move to second element
	std::cout << *it << '\n'; // ok: prints 2
	v.erase(it); // erase the element currently being iterated over
	// erase() invalidates iterators to the erased element (and subsequent elements)
	// so iterator "it" is now invalidated
	++it; // undefined behavior
	std::cout << *it << '\n'; // undefined behavior
}

// Our function will return true if the element matches
bool containsNut(std::string_view str)
{
	// std::string_view::find returns std::string_view::npos if it doesn't find
	// the substring. Otherwise it returns the index where the substring occurs
	// in str.
	return (str.find("nut") != std::string_view::npos);
}


void std_algos()
{
	//The functionality provided in the algorithms library generally fall into one of three categories:

	//Inspectors -- Used to view(but not modify) data in a container
	//.Examples include searchingand counting.

	//Mutators -- Used to modify data in a container.
	//Examples include sortingand shuffling.

	//Facilitators -- Used to generate a result based on values of the data members.
	//Examples include objects that multiply values, 
	//or objects that determine what order pairs of elements should be sorted in.

	std::array arr1{ 13, 90, 99, 5, 40, 80 };

	std::cout << "Enter a value to search for and replace with: ";
	int search{};
	int replace{};
	std::cin >> search >> replace;

	// Input validation omitted

	// std::find returns an iterator pointing to the found element (or the end of the container)
	// we'll store it in a variable, using type inference to deduce the type of
	// the iterator (since we don't care)
	auto found1{ std::find(arr1.begin(), arr1.end(), search) };

	// Algorithms that don't find what they were looking for return the end iterator.
	// We can access it by using the end() member function.
	if (found1 == arr1.end())
	{
		std::cout << "Could not find " << search << '\n';
	}
	else
	{
		// Override the found element.
		*found1 = replace;
	}
	for (int i : arr1)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';

	std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };
	// Scan our array to see if any elements contain the "nut" substring
	auto found{ std::find_if(arr.begin(), arr.end(), containsNut) };

	if (found == arr.end())
	{
		std::cout << "No nuts\n";
	}
	else
	{
		std::cout << "Found " << *found << '\n';
	}
	//If you were to write the above example by hand, 
	//you�d need at least two loops (one to loop through the array,
	//and one to match the substring). 
	//The standard library functions 
	//allow us to do the same thing in just a few lines of code!
}



