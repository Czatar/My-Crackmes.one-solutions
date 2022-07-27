// https://crackmes.one/crackme/5cbac94633c5d4419da55881
// C++ Solution by Carlos Zatarain
// Reverse engineered using Ghidra
// 7/27/2022

/*
1. In Ghidra: Search > For Strings... > Search
2. Find "Enter" and select the match
3. In Listing, go to the XREF to find the main function
4. Notice that the majority of the main function is loading strings and
        functions from msvcrt.dll, and see that [EBP - 0x24] is
        printf and [EBP - 0x20] is scanf
5. The calls at 0x....1618 and 0x....1625 generate integers (as shown in the
        code below) and the following functions check for equality
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <time.h>

int main()
{
    srand(time(NULL));

    // Generate name and calculate serial
    std::string username;
    size_t nameLen = 1 + (rand() % 32);
    int serial = 0;

    for (size_t i = 0; i < nameLen; i++)
    {
        username += 33 + (rand() % 94);
        serial += (int) pow((double) username[i], 3.0);
    }

    serial *= 5;

    // Print credentials
    std::cout << "username: " << username << std::endl;
    std::cout << "Serial: " << serial << std::endl;

    return 0;
}
