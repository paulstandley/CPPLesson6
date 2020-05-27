#include "pch.h"
#include <iostream>
#include "Header.h"
#include <string>
#include <string_view>
#include <cstring> // For std::strlen
#include <cstddef> // for NULL
#include <iterator> // for std::size std::begin and std::end
#include <algorithm>



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

void size_of_pointer()
{
    char* chPtr{}; // chars are 1 byte
    int* iPtr{}; // ints are usually 4 bytes
    struct Something
    {
        int x{};
        int y{};
        int z{};
    };
    Something* somethingPtr{}; // Something is probably 12 bytes
    std::cout << sizeof(chPtr) << '\n'; // prints 4
    std::cout << sizeof(iPtr) << '\n'; // prints 4
    std::cout << sizeof(somethingPtr) << '\n'; // prints 4
    /*
    Pointers are variables that hold a memory address.
    They can be dereferenced using the dereference operator (*)
    to retrieve the value at the address they are holding.
    Dereferencing a garbage pointer may crash your application.
    */
}

void null_pointers()
{
    float* ptr1{ 0 };  // ptr is now a null pointer
    float* ptr2; // ptr2 is uninitialized
    ptr2 = 0; // ptr2 is now a null pointer
    double* ptr3{ 0 };
    // pointers convert to boolean false if they are null, and boolean true if they are non-null
    if (ptr3)
        std::cout << "ptr is pointing to a double value.";
    else
        std::cout << "ptr is a null pointer.";
    double* ptr4{ NULL }; // ptr is a null pointer
    int* ptr5{ nullptr };
    // note: ptr is still an integer pointer, just set to a null value
}

void print(int x)
{
    std::cout << "print(int): " << x << '\n';
}

void print(int* x)
{
    if (!x)
        std::cout << "print(int*): null\n";
    else
        std::cout << "print(int*): " << *x << '\n';
}
void call_print()
{
    int* x1{ NULL };
    print(x1); // calls print(int*) because x has type int*
    print(0); // calls print(int) because 0 is an integer literal
    print(NULL); // likely calls print(int), although we probably wanted print(int*)
    int* x2{ nullptr };
    print(x2); // calls print(int*)
    print(nullptr); // calls print(int*) as desired
}

void doSomething(std::nullptr_t ptr)
{
    std::cout << "in doSomething()\n";
}

void array_decay_to_address()
{
    int array[5]{ 9, 7, 5, 3, 1 };
    // print address of the array's first element
    std::cout << "Element 0 has address: " << &array[0] << '\n';
    // print the value of the pointer the array decays to
    std::cout << "The array decays to a pointer holding address: " << array << '\n';
}

void dereference_array_to_get_value_of_first_element()
{
    int array0[5]{ 9, 7, 5, 3, 1 };
    // dereferencing an array returns the first element (element 0)
    std::cout << "Dereferencing an array returns the first element " << *array0 << '\n'; // will print 9!
    char name[]{ "Paul" }; // C-style string (also an array)
    std::cout << "Char array first element dereference " << *name << '\n'; // will print 'P'
    /*
    Note that we’re not actually dereferencing the array itself.
    The array (of type int[5]) gets implicitly converted into a pointer (of type int *),
    and we dereference the pointer to get the value at the memory address the pointer
    is holding (the value of the first element of the array).
    */
    int array1[5]{ 9, 7, 5, 3, 1 };
    std::cout << "Dereferencing an array returns the first element " << *array1 << '\n'; // will print 9
    int* ptr1{ array1 };
    std::cout << "Array1 decays into a pointer of type int * and our pointer(also of type int*) " << *ptr1 << '\n'; // will print 9
    /*
    This works because the array1 decays into a pointer of type int *,
    and our pointer (also of type int *) has the same type
    */
    int array2[5]{ 9, 7, 5, 3, 1 };
    std::cout << "Sizeof(int) * array length " << sizeof(array2) << '\n'; // will print sizeof(int) * array length
    int* ptr2{ array2 };
    std::cout << "Size of a pointer " << sizeof(ptr2) << '\n'; // will print the size of a pointer
    /*
    The primary difference occurs when using the sizeof() operator.
    When used on a fixed array, sizeof returns the size of the entire
    array (array length * element size).
    When used on a pointer, sizeof returns the size of a memory address (in bytes)
    A fixed array knows how long the array it is pointing to is. A pointer to the array does not

    The second difference occurs when using the address-of operator (&).
    Taking the address of a pointer yields the memory address of the pointer variable.
    Taking the address of the array returns a pointer to the entire array.
    This pointer also points to the first element of the array, but the type information is different
    (in the above example, the type of &array is int(*)[5]).
    It’s unlikely you’ll ever need to use this.
    */
}

void print_size_of1(int* array)
{
    // array is treated as a pointer here
    std::cout << sizeof(array) << '\n';
    // prints the size of a pointer, not the size of the array!
}

// C++ will implicitly convert parameter array[] to *array
void print_size_of2(int array[])
{
    // array is treated as a pointer here, not a fixed array
    std::cout << sizeof(array) << '\n';
    // prints the size of a pointer, not the size of the array!
}

void passing_fixed_arrays_to_functions()
{
    int array[]{ 1, 1, 2, 3, 5, 8, 13, 21 };
    std::cout << sizeof(array) << '\n'; // will print sizeof(int) * array length
    print_size_of1(array); // the array argument decays into a pointer here
    print_size_of2(array); // the array argument decays into a pointer here
}

// parameter ptr contains a copy of the array's address
void change_array(int* ptr)
{
    *ptr = 5; // so changing an array element changes the _actual_ array
}

void print_change_array()
{
    int array[]{ 1, 1, 2, 3, 5, 8, 13, 21 };
    std::cout << "Element 0 has value: " << array[0] << '\n';
    change_array(array);
    std::cout << "Element 0 has value: " << array[0] << '\n';
    // Arrays in structs and classes don’t decay
}

void pointer_arithmetic()
{
    int value1{ 7 };
    int* ptr1{ &value1 };
    std::cout << ptr1 << '\n';
    std::cout << ptr1 + 1 << '\n';
    std::cout << ptr1 + 2 << '\n';
    std::cout << ptr1 + 3 << '\n';
    short value2{ 7 };
    short* ptr2{ &value2 };
    std::cout << ptr2 << '\n';
    std::cout << ptr2 + 1 << '\n';
    std::cout << ptr2 + 2 << '\n';
    std::cout << ptr2 + 3 << '\n';
    int array1[]{ 9, 7, 5, 3, 1 };
    std::cout << "Element 0 is at address: " << &array1[0] << '\n';
    std::cout << "Element 1 is at address: " << &array1[1] << '\n';
    std::cout << "Element 2 is at address: " << &array1[2] << '\n';
    std::cout << "Element 3 is at address: " << &array1[3] << '\n';
    int array[]{ 9, 7, 5, 3, 1 };
    std::cout << &array[1] << '\n'; // print memory address of array element 1
    std::cout << array + 1 << '\n'; // print memory address of array pointer + 1 
    std::cout << array[1] << '\n'; // prints 7
    std::cout << *(array + 1) << '\n'; // prints 7 (note the parenthesis required here)
}

bool isVowel(char ch)
{
    switch (ch)
    {
    case 'A':
    case 'a':
    case 'E':
    case 'e':
    case 'I':
    case 'i':
    case 'O':
    case 'o':
    case 'U':
    case 'u':
        return true;
    default:
        return false;
    }
}

void pointer_iterate_array()
{
    /*
    int arr[]{ 1, 2, 3 };
    std::cout << 2[arr] << '\n';
    arr[2]
    // same as
    *(arr + 2)
    // same as
    *(2 + arr)
    // same as
    2[arr]

#include <iostream>
#include <iterator>

int* find(int* begin, int* end, int value)
{
    for (int* p{ begin }; p != end; ++p)
    {
        if (*p == value)
        {
            return p;
        }
    }

    return end;
}

int main()
{
    int arr[]{ 2, 5, 4, 10, 8, 20, 16, 40 };

    int* found{ find(std::begin(arr), std::end(arr), 20) };

    if (found != std::end(arr))
    {
        std::cout << *found << '\n';
    }

    return 0;
}

       char name1[]{ "Louise" };
    int arrayLength{ static_cast<int>(std::size(name1)) };
    int numVowels{ 0 };
    for (char* ptr1{ name1 }; ptr1 < (name1 + arrayLength); ++ptr1)
    {
        if (isVowel(*ptr1))
        {
            ++numVowels;
        }
    }
    std::cout << name1 << " has " << numVowels << " vowels.\n";
    numVowels = 0;
    char name2[]{ "Dollie" };
    auto numVowels{ std::count_if(std::begin(name2), std::end(name2), isVowel) };
    std::cout << name2 << " has " << numVowels << " vowels.\n";
        int arr[]{ 2, 5, 4, 10, 8, 20, 16, 40 };
    // Note: std::find returns an iterator.
    auto found{ std::find(std::begin(arr), std::end(arr), 20) };
    if (found != std::end(arr))
    {
        std::cout << *found << '\n';
    }
    */

}

void pointer_to_symbolic_constant()
{
    const char* my_name1{ "Kerrin" }; // pointer to symbolic constant
    std::cout << my_name1 << '\n';
    const char* my_name_2{ "Louise" };
    const char* my_name_3{ "Louise" };
    std::cout << &my_name_2 << '\t' << &my_name_3 << '\n';
    std::cout << get_pointer_to_array() << '\n';
    char c{ 'Q' };
    std::cout << &c << '\n';
    // std::cout assumed &c (which has type char*)
    // was a string. So it printed the ‘Q’, and then kept going
}

const char* get_pointer_to_array()
{
    int nArray[5]{ 9, 7, 5, 3, 1 };
    char cArray[]{ "Hello!" };
    const char* name{ "Alex" };
    std::cout << "nArray will decay to type int* " << nArray << '\n'; // nArray will decay to type int*
    std::cout << "cArray will decay to type char* " << cArray << '\n'; // cArray will decay to type char*
    std::cout << "name is already type char* " << name << '\n'; // name is already type char*
    return "Melissa";
}

void dynamic_memory_allocation()
{
    int* ptr{ new int };
    // dynamically allocate an integer and assign the address to ptr so we can access it later
    *ptr = 7; // assign value of 7 to allocated memory
    int* ptr1{ new int(5) }; // use direct initialization
    int* ptr2{ new int { 6 } }; // use uniform initialization
    std::cout << ptr << '\t' << ptr1 << '\t' << ptr2 << '\n';
    // assume ptr has previously been allocated with operator new
    // return the memory pointed to by ptr to the operating system
    // set ptr to be a null pointer (use nullptr instead of 0 in C++11)
    delete ptr, delete ptr1, delete ptr2;
    ptr = 0;
    ptr1 = 0;
    ptr2 = 0;
}

void dangling_pointer()
{
    int* ptr_1{ new int };
    // dynamically allocate an integer
    *ptr_1 = 7;
    // put a value in that memory location
    delete ptr_1;
    // return the memory to the operating system.  ptr is now a dangling pointer.
    //std::cout << *ptr_1; 
    // Dereferencing a dangling pointer will cause undefined behavior
    // trying to deallocate the memory again will also lead to undefined behavior.

    int* ptr{ new int{} }; // dynamically allocate an integer
    int* other_ptr{ ptr }; // otherPtr is now pointed at that same memory location
    delete ptr; // return the memory to the operating system.  ptr and otherPtr are now dangling pointers.
    ptr = nullptr; // ptr is now a nullptr
    // however, otherPtr is still a dangling pointer!
    std::cout << other_ptr << '\n';

    int* value1{ new (std::nothrow) int{} }; // ask for an integer's worth of memory
    if (!value1) // handle case where new returned null
    {
        // Do error handling here
        std::cout << "Could not allocate memory";
    }
    int value2 = 5;
    int* ptr2{ new int{} }; // allocate memory
    ptr2 = &value2; // old address lost, memory leak results
    int value3 = 5;
    int* ptr3{ new int{} }; // allocate memory
    delete ptr3; // return memory back to operating system
    ptr3 = &value3; // reassign pointer to address of value
    int* ptr4{ new int{} };
    ptr4 = new int{}; // old address lost, memory leak results
    delete other_ptr;
    other_ptr = nullptr;
    delete value1;
    value1 = nullptr;
    delete ptr2;
    ptr2 = nullptr;
    delete ptr3;
    ptr3 = nullptr;
    delete ptr4;
    ptr4 = nullptr;
}
/*
Write a program that:
* Asks the user how many names they wish to enter.
* Dynamically allocates a std::string array.
* Asks the user to enter each name.
* Calls std::sort to sort the names
(See 6.4 -- Sorting an array using selection sort
and 6.8a -- Pointer arithmetic and array indexing)
* Prints the sorted list of names.
std::string supports comparing strings via the comparison operators < and >.
You don’t need to implement string comparison by hand.
*/
/*
void dynamically_allocate_arrays_of_variables()
{
    std::cout << "Enter a postitive integer: ";
    int length{};
    std::cin >> length;
    // use array new.  Note that length does not need to be constant!
    int* array{ new int[length] };
    std::cout << "I just allocated an array of integers of length " << length << '\n';
    array[0] = 5;
    int* array1{ new int[5]{ 9, 7, 5, 3, 1 } }; // initialize a dynamic array in C++11
    delete[] array;
    array = nullptr;
    delete[] array1;
}

int get_number_for_array()
{
    while (true)
    {
        int num{};
        std::cout << "How many names would you like to enter? ";
        std::cin >> num;
        if (std::cin.fail()) // has a previous extraction failed?
        {
            // yep, so let's handle the failure
            std::cin.clear(); // put us back in 'normal' operation mode
            std::cin.ignore(32767, '\n'); // and remove the bad input
            break;
        }
        else // else our extraction succeeded
        {
            std::cin.ignore(32767, '\n'); // clear (up to 32767) characters out of the buffer until a '\n' character is removed
            return num; // so return the value we extracted
        }
    }
}

std::string get_names_from_user(int num)
{
    while (true)
    {
        std::cout << "Enter name # " << num + 1 << " ";
        std::string name{};
        std::getline(std::cin, name);
        if (std::cin.fail()) // has a previous extraction failed?
        {
            // yep, so let's handle the failure
            std::cin.clear(); // put us back in 'normal' operation mode
            std::cin.ignore(32767, '\n'); // and remove the bad input
            break;
        }
        else // else our extraction succeeded
        {
            std::cin.ignore(32767, '\n'); // clear (up to 32767) characters out of the buffer until a '\n' character is removed
            return name; // so return the value we extracted
        }
    }
}

void print_user_names(std::string* name, int num)
{
    std::cout << "Here is your sorted list\n\n";
    for (int index = 0; index < num; index++)
    {
        std::cout << "Name #" << index + 1 << ": " << name[index] << '\n';
    }
}

void make_dynamic_array()
{
    int length{ get_number_for_array() };
    // Allocate an array to hold the names
    auto* names{ new std::string[static_cast<std::size_t>(length)]{} };
    for (int index = 0; index < length; ++index)
    {
        names[index] = get_names_from_user(index);
    }
    std::sort(names, names + length);
    print_user_names(names, length);
    delete[] names;
    names = nullptr;
}

void pointer_to_const()
{
    int value1 = 5;
    const int* ptr1 = &value1; // ptr points to a const int
    int value2 = 6;
    ptr1 = &value2; // okay, ptr now points at some other const int
    // A const pointer is a pointer whose value can not be changed after initialization
    int value3 = 5;
    int* const ptr3 = &value3;
    // because the value being pointed to is still non-const, it is
    // possible to change the value being pointed to via dereferencing the const pointer:
    int value4 = 5;
    int* const ptr4 = &value4; // ptr4 will always point to value4
    *ptr4 = 6; // allowed, since ptr4 points to a non-const int
    // Const pointer to a const value
    // Finally, it is possible to declare a const pointer to a const value by using the 
    // const keyword both before the typeand before the variable name :
    int value5 = 5;
    const int* const ptr5 = &value5;
    // A const pointer to a const value can not be set to point to another address, 
    // nor can the value it is pointing to be changed through the pointer.
    
    //1) A non-const pointer can be redirected to point to other addresses.

    //2) A const pointer always points to the same address,
    //and this address can not be changed.

    //3) A pointer to a non-const value can change the value it is pointing to.
    //These can not point to a const value.

    //4) A pointer to a const value treats the value as const (even if it is not),
    //and thus can not change the value it is pointing to.
    
    int value5 = 5;
    const int* ptr5 = &value5;
    // ptr1 points to a "const int", so this is a pointer to a const value.
    int* const ptr6 = &value5;
    // ptr2 points to an "int", so this is a const pointer to a non-const value.
    const int* const ptr7 = &value5;
    // ptr3 points to a "const int", so this is a const pointer to a const value.
}
*/

void references_to_non_const_values()
{
    int value1{ 5 };// normal integer
    int& ref1{ value1 };// referance to variable value
    // In this context, the ampersand does not mean “address of”, it means “reference to”
    value1 = 6;
    std::cout << ref1 << '\n';
    --ref1;
    std::cout << ref1 << ' ' << value1 << '\n';
    std::cout << &ref1 << ' ' << &value1 << '\n';// same address
    // r value
    int y;      // define y as an integer variable
    y = 4;      // 4 evaluates to 4, which is then assigned to y
    y = 2 + 5;  // 2 + 5 evaluates to 7, which is then assigned to y

    int x;      // define x as an integer variable
    x = y;      // y evaluates to 7 (from before), which is then assigned to x.
    x = x;      // x evaluates to 7, which is then assigned to x (useless!)
    x = x + 1;  // x + 1 evaluates to 8, which is then assigned to x.
    // In this statement, the variable x is being used in two different contexts. 
    // On the left side of the assignment operator, “x” is being used as an l-value 
    // (variable with an address). 
    // On the right side of the assignment operator, x is being used as an r-value, 
    // and will be evaluated to produce a value (in this case, 7).
    //Unlike pointers, which can hold a null value, there is no such thing as a null reference.
    // References to non - const values can only be initialized with non - const l - values.
    // They can not be initialized with const l - values or r - values.
    //const int y{ 7 };
    //int& ref2{ y }; // not okay, y is a const l-value
    //int& ref3{ 6 }; // not okay, 6 is an r-value
    int value2{ 5 };
    int value3{ 6 };
    int &ref2{ value2 }; // okay, ref is now an alias for value1
    ref2 = value3; // assigns 6 (the value of value2) to value1 
    //-- does NOT change the reference it assigns the value of value2 to value3
}

std::string ref_tester(std::string &ref)
{
    ref = ref + "what you looking at";
    return ref;
}

void print_ref_tester()
{
    std::string thing{ "Hay " };
    std::cout << ref_tester(thing) << '\n';
    thing = thing + " yes you :-(";
    std::cout << thing << '\n';
    // When argument n is passed to the function, 
    // the function parameter ref is set as a reference to argument thing. 
    // This allows the function to change the value of thing through ref! 
    // Note that thing does not need to be a reference itself.
    // The primary downside of using non-const references 
    // as function parameters is that the argument must be a non-const l-value
}



