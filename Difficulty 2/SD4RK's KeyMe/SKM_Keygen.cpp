// https://crackmes.one/crackme/5ed3735f33c5d449d91ae6a9
// C++ Solution by Carlos Zatarain
// Reverse engineered using Ghidra and x32dbg
// 7/25/2022

/*
1. In Ghidra: Search > For Strings... > Search
2. Find "Enter the key:" and select the match
3. In Listing, go to the XREF to find the main function
4. In Ghidra's decompiled view, some variables are split awkwardly, so find the
        main function address in x32dbg and set breakpoints after scanf
5. Run the program multiple times, building up the correct key each run like so:
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    std::string key;

    // key[0] - key[5] must have an ascii less than 64
    for (size_t i = 0; i < 6; i++)
    {
        key += 33 + (rand() % 31);
    }

    // Sum of key[6] - key[8] should be > 256. Simply, each will be > 86
    for (size_t i = 6; i < 9; i++)
    {
        key += 86 + (rand() % 41);
    }

    // key[9] = 0x40 = '@'
    key += '@';

    // key[10] - key[12]: 2*key[n] % 3 = 0
    for (size_t i = 10; i < 13; i++)
    {
        key += 36 + (rand() % 91);
        key[i] -= key[i] % 6;
    }

    // For key[13] - key[15], (key[n] >> 1) & FFFFFF0 = 0x20 = ascii 64 - 95
    for (size_t i = 13; i < 16; i++)
    {
        key += 64 + (rand() % 32);
    }

    // Print key
    std::cout << "key: " << key << std::endl;

    return 0;
}
