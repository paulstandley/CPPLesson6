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

//Manually indexing std::array via size_type
void std_array_wrong()
{
    //Pop quiz: What’s wrong with the following code?
    std::array myArray{ 7, 3, 1, 9, 5 };
    // Iterate through the array and print the value of the elements
    for (int i{ 0 }; i < myArray.size(); ++i)
        std::cout << myArray[i] << ' ';
    std::cout << '\n';
    //The answer is that there’s a likely signed/unsigned mismatch
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


int main()
{
	std_array_wrong();

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
