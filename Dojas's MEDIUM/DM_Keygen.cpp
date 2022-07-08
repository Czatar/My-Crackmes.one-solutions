// https://crackmes.one/crackme/6167747a33c5d4329c345148
// C++ Solution by Carlos Zatarain
// Reverse engineered using Ghidra's decompiler and http://demangler.com/
// 7/8/2022

/*
1. In Ghidra: Search > For Strings... > Search
2. Find "password: " and select it
3. In Listing, go to the XREF to find the main function
4. From there, demangle with http://demangler.com/ and rename variables to help
5. You will find that the code essentially does this (with a check at the end):
*/

#include <iostream>
#include <string>

int main()
{
    std::cout << "user: ";

    std::string user;
    std::cin >> user;

    size_t userLength = user.length();

    int realPassword = 0;

    for (size_t i = 0; i < userLength; i++)
    {
        realPassword += user[i] * 4;
    }

    std::cout << "password: " << realPassword << std::endl;

    return 0;
}
