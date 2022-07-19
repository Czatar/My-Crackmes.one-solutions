// https://crackmes.one/crackme/617581d833c5d4329c3452ce
// C++ Solution by Carlos Zatarain
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
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    size_t keyLength = 1 + (rand() % 20);

    std::string user, key;
    char uChar, kChar;

    for (size_t i = 0; i < keyLength; i++)
    {
        do {
            uChar = 33 + (rand() % 94);
            kChar = (uChar ^ 4) + keyLength;
        } while(kChar < 33 || kChar > 126);

        user += uChar;
        key += kChar;
    }

    std::cout << "user: " << user << std::endl;
    std::cout << "serial: " << key << std::endl;

    return 0;
}
