#include "pch.h"
#include <iostream>
#include "Header.h"
#include <string>
#include <string_view>
#include <cstring> // For std::strlen


void string_view_hello()
{
    std::string_view text1{ "hello" }; // view the text "hello", which is stored in the binary
    std::string_view str1{ text1 }; // view of the same "hello"
    std::string_view more1{ str1 }; // view of the same "hello"
    std::cout << text1 << ' ' << str1 << ' ' << more1 << '\n';

    std::string_view str2{ "Trains are fast!" };
    std::cout << str2.length() << '\n'; // 16
    std::cout << str2.substr(0, str2.find(' ')) << '\n'; // Trains
    std::cout << (str2 == "Trains are fast!") << '\n'; // 1
    // Since C++20
    //std::cout << str2.starts_with("Boats") << '\n'; // 0
    //std::cout << str2.ends_with("fast!") << '\n'; // 1
    std::cout << str2 << '\n'; // Trains are fast!

    char arr3[]{ "Gold" };
    std::string_view str3{ arr3 };
    std::cout << str3 << '\n'; // Gold
    // Change 'd' to 'f' in arr
    arr3[3] = 'f';
    std::cout << str3 << '\n'; // Golf

    std::string_view str4{ "Peach" };
    std::cout << str4 << '\n';
    // Ignore the first characters.
    str4.remove_prefix(1);
    std::cout << str4 << '\n';
    // Ignore the last 2 characters.
    str4.remove_suffix(2);
    std::cout << str4 << '\n';

    // No null-terminator.
    char vowels5[]{ 'a', 'e', 'i', 'o', 'u' };
    // vowels isn't null-terminated. We need to pass the length manually.
    // Because vowels is an array, we can use std::size to get its length.
    std::string_view str5{ vowels5, std::size(vowels5) };
    std::cout << str5 << '\n'; // This is safe. std::cout knows how to print std::string_views.

}

std::string_view ask_for_name()
{
    std::cout << "What's your name?\n";
    // Use a std::string, because std::cin needs to modify it.
    std::string str{};
    std::cin >> str;
    // We're switching to std::string_view for demonstrative purposes only.
    // If you already have a std::string, there's no reason to switch to
    // a std::string_view.
    std::string_view view{ str };
    std::cout << "Hello " << view << '\n';
    return view;
} // str dies, and so does the string that str created.

void ownership_issues()
{
    std::string_view view{ ask_for_name() };
    // view is observing a string that already died.
    std::cout << "Your name is " << view << '\n'; // Undefined behavior
    // Make sure that the underlying string viewed with a std::string_view 
    // does not go out of scope and isn’t modified while using the std::string_view.
}

void print_implicitly_convert_string_view(std::string s)
{
    std::cout << s << '\n';
}

void implicitly_convert_string_view()
{
    std::string_view sv{ "balloon" };
    sv.remove_suffix(3);
    // print(sv); // compile error: won't implicitly convert
    std::string str{ sv }; // explicit conversion
    print_implicitly_convert_string_view(str); // okay
    print_implicitly_convert_string_view(static_cast<std::string>(sv)); // okay
}

void converting_string_view_c_style_string()
{
    std::string_view sv{ "balloon" };
    sv.remove_suffix(3);
    // Create a std::string from the std::string_view
    std::string str{ sv };
    // Get the null-terminated C-style string.
    auto szNullTerminated{ str.c_str() };
    // Pass the null-terminated string to the function that we want to use.
    std::cout << str << " has " << std::strlen(szNullTerminated) << " letter(s)\n";
}

void string_data()
{
    std::string_view str1{ "jimbob" };
    std::cout << str1 << '\n';
    // We use std::strlen because it's simple, this could be any other function
    // that needs a null-terminated string.
    // It's okay to use data() because we haven't modified the view, and the
    // string is null-terminated.
    std::cout << std::strlen(str1.data()) << '\n';

    std::string_view str2{ "balloon" };
    // Remove the "b"
    str2.remove_prefix(1);
    // remove the "oon"
    str2.remove_suffix(3);
    // Remember that the above doesn't modify the string, it only changes
    // the region that str is observing.
    std::cout << str2 << " has " << std::strlen(str2.data()) << " letter(s)\n";
    std::cout << "str.data() is " << str2.data() << '\n';
    std::cout << "str is " << str2 << '\n';
    /*
    Only use std::string_view::data() if the std::string_view‘s view hasn’t been modified and
    the string being viewed is null-terminated.
    Using std::string_view::data() of a non-null-terminated string can cause undefined behavior.
    */
}

void incomplete_implementation()
{
    std::string s{ "hello" };
    std::string_view v{ "world" };
    // Doesn't work
    //std::cout << (s + v) << '\n';
    //std::cout << (v + s) << '\n';
    // Potentially unsafe, or not what we want, because we're treating
    // the std::string_view as a C-style string.
    std::cout << (s + v.data()) << '\n';
    std::cout << (v.data() + s) << '\n';
    // Ok, but ugly and wasteful because we have to construct a new std::string.
    std::cout << (s + std::string{ v }) << '\n';
    std::cout << (std::string{ v } +s) << '\n';
    std::cout << (s + static_cast<std::string>(v)) << '\n';
    std::cout << (static_cast<std::string>(v) + s) << '\n';
}

void ponter_address_operator()
{
    int memory_address{ 5 };
    std::cout << memory_address << '\n'; // print the value of variable 
    std::cout << &memory_address << '\n'; // print the memory address of variable 
    // The dereference operator (*) allows us to access the value at a particular address:
    int x{ 5 };
    std::cout << x << '\n'; // print the value of variable x
    std::cout << &x << '\n'; // print the memory address of variable x
    std::cout << *(&x) << '\n'; /// print the value at the memory address of variable x
                                // (parenthesis not required, but make it easier to read)
    /*
    Pointer variables are declared just like normal variables,
    only with an asterisk between the data type and the variable name.
    Note that this asterisk is not a dereference.
    It is part of the pointer declaration syntax.
    */

    int* iPtr_int{}; // a pointer to an integer value
    double* dPtr_double{}; // a pointer to a double value
    int* iPtr2{}; // also valid syntax (acceptable, but not favored)
    int* iPtr3{}; // also valid syntax (but don't do this, it looks like multiplication)
    int* iPtr4{}, * iPtr5{}; // declare two pointers to integer variables (not recommended)
    //int* do_somthing();This makes it clear that the function is returning a value of type int* and not an int
    // When declaring a pointer variable, put the asterisk next to the variable name
    // When declaring a function, put the asterisk of a pointer return value next to the type
    int v{ 5 };
    int* ptr{ &v }; // initialize ptr with address of variable v
    std::cout << &v << '\n'; // print the address of variable v
    std::cout << ptr << '\n'; // print the address that ptr is holding

    int iValue{ 5 };
    double dValue{ 7.0 };

    int* iPtr{ &iValue }; // ok
    double* dPtr{ &dValue }; // ok
    //iPtr = &dValue; 
    // wrong -- int pointer cannot point to the address of a double variable
    //dPtr = &iValue; 
    // wrong -- double pointer cannot point to the address of an int variable
    //int *ptr{ 5 }; // wrong pointers can only hold addresses
    //double *dPtr{ 0x0012FF7C };// not ok
    //C++ will also not allow you to directly convert literal memory addresses to a pointer
}

void reassign_pointer()
{
    int value1{ 5 };
    int value2{ 7 };
    int* ptr1{};
    ptr1 = &value1; // ponits to value1
    std::cout << "pointer to value 1 " << *ptr1 << '\n';// prints 5
    std::cout << "pointer address 1 " << ptr1 << '\n';// address
    std::cout << "reassign pointer\n";
    ptr1 = &value2;// points to value2
    std::cout << "pointer to value 1 " << *ptr1 << '\n';// prints 7
    std::cout << "pointer address 1 " << ptr1 << '\n';// address

    int value3{ 5 };
    int* ptr2{ &value3 }; // ptr2 points to value3
    *ptr2 = 15; // *ptr2 is the same as value3, which is assigned 15
    std::cout << value3 << '\n'; // prints 15
}

void bang(int*&) // We cover & later. Don't worry about it for now, we're only using it to trick the compiler into thinking that p has a value.
{
    // p is a reference to a pointer.  We'll cover references (and references to pointers) later in this chapter.
    // We're using this to trick the compiler into thinking p could be modified, so it won't complain about p being uninitialized.
    // This isn't something you'll ever want to do intentionally.
}

void crash() {
    int* p; // Create an uninitialized pointer (that points to garbage)
    bang(p); // Trick compiler into thinking we're going to assign this a valid value
    std::cout << *p << '\n'; // Dereference the garbage pointer
}




