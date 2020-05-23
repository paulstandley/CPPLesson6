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

