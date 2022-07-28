// https://crackmes.one/crackme/5c9ce65c33c5d4419da5562d
// C++ Solution by Carlos Zatarain
// Reverse engineered using Ghidra
// 7/28/2022

/*
1. In Ghidra: Search > For Strings... > Search
2. Find "ENTER LICENSE: " and select the match
3. In Listing, go to the XREF to find the main function
4. Rename printf/scanf functions, the input variable, and notice that local_18
        is set to the first character of the input
5. The following checks ensure that 42 < input[0] < 72 and input[0] % 60 = 3,
        which can only be '?' and the rest of the string can be anything:
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    // Generte random license
    std::string license = "?";
    size_t lSize = 1 + (rand() % 15);

    for (size_t i = 1; i < lSize; i++)
    {
        license += 33 + (rand() % 94);
    }

    // Print license
    std::cout << "LICENSE: " << license << std::endl;

    return 0;
}
