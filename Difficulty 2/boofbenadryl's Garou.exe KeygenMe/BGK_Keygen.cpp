// https://crackmes.one/crackme/5e9e18d033c5d47611746396
// C++ Solution by Carlos Zatarain
// Reverse engineered using Ghidra
// 7/26/2022

/*
1. In Ghidra: Search > For Strings... > Search
2. Find "Name: " and select the match
3. In Listing, go to the XREF to find the main function
4. Between the call to some sort of scanf and the comparison of strings, there
        are 5 functions, of which we can eliminate 2 since one function sets
        the variable to check if it's equal to '0' (maybe strcmp), and another
        that happens afterwards
5. Upon inspection, the 2nd and 3rd mentioned functions have interesting
        features. Both feature loops, the second of which checks if something is
        equal to 1 or 0, then sets some variable to be the opposite character,
        which feels like a bit flip
6. The function before the bit flips seems to increment a loop variable and
        calls a function in the form of "func(char, string, 0, 1)"
7. This function contains a loop that iterates 8 times, each time concatenating
        the string with a 1 or a 0, depending on the value of a char anded with
        1 << i. Clearly, the function converts each char to its ascii string
8. Put together, the following code produces a key like so:
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <bitset>
#include <time.h>

int main()
{
    srand(time(NULL));

    // Generate credentials
    std::string name, key;
    std::bitset<8> bits;
    size_t nLen = 1 + (rand() % 10);

    for (size_t i = 0; i < nLen; i++)
    {
        name += 33 + (rand() % 94);
        bits = name[i];
        key += bits.flip().to_string();
    }

    // Print credentials
    std::cout << "Name: " << name << std::endl;
    std::cout << "Key: " << key << std::endl;

    return 0;
}
