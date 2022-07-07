// https://crackmes.one/crackme/617581d833c5d4329c3452ce
// C++ Solution by Sokks
// Reverse engineered using Ghidra's decompiler and http://demangler.com/
// 7/7/2022

/*
1. In Ghidra: Search > For Strings... > Search
2. Find "good you are a master hacking" and select it
3. In Listing, go to the XREF to find the main function
4. From there, demangle with http://demangler.com/ and rename variables to help
5. You will find that the code essentially does this (with a check at the end):
*/

#include <iostream>
#include <string>

int main()
{
    std::cout << "user: ";

    std::string key;
    std::cin >> key;

    size_t keyLength = key.length();

    for (size_t i = 0; i < keyLength; i++)
    {
        key[i] ^= 4;
        key[i] += keyLength;
    }

    std::cout << "serial: " << key << std::endl;

    return 0;
}
