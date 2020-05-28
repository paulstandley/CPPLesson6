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