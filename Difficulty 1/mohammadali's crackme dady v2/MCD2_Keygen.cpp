// https://crackmes.one/crackme/5feff9b233c5d4264e5901c7
// C++ Solution by Carlos Zatarain
// Reverse engineered using Ghidra
// 7/24/2022

/*
1. In Ghidra: Search > For Strings... > Search
2. Find "Press enter" and select the match
3. In Listing, go to the XREF to find the main function
4. Functions are demangled for you, so it's easy to rename username/password
        variables as well as loop variables.
5. The for loop in the decompilation pane operates on the input username, which
        essentially does the following:
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    // Generate random name and password
    std::string name, password;
    size_t nameLen = 1 + (rand() % 15);

    for (size_t i = 0; i < nameLen; i++)
    {
        name += (33 + nameLen) + (rand() % (94 - nameLen));
        password += name[i] - nameLen;
    }

    // Print out credentials
    std::cout << "username: " << name << std::endl;
    std::cout << "password: " << password << std::endl;

    return 0;
}
