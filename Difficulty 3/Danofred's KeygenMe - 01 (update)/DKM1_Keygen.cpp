// https://crackmes.one/crackme/6214dd6233c5d46c8bcbff61
// C++ Solution by Carlos Zatarain
// Reverse engineered using Ghidra and x64dbg
// 7/20/2022

/*
1. In Ghidra: Search > For Strings... > Search
2. Find "password" and select any option
3. In Listing, go to the XREF to find the main function
4. We see that function names were not obscured and the flow is pretty clear, so
        it is reasonable that "getEncryptKey" generates the correct key
5. Ghidra's decompilation may be hard to read, so I used x64dbg to make sense
        out of that funciton's for loop.
6. Reading the assembly, you can see that some additions in Ghidra correspond to
        string indexing which makes much more sense.
7. The final string comparison is simply comparing your input to this algorithm:
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    // Generate username
    std::string user;
    size_t userLen = 4 + (rand() % 17);

    for (size_t i = 0; i < userLen; i++)
    {
        user += (33 + (rand() % 94));
    }

    // Generate password
    std::string password = user;
    for (size_t i = 0; i < userLen; i++) {
        password[i] = user[(user[i] ^ 26) % userLen];
    }

    // Print credentials
    std::cout << "username: " << user << std::endl;
    std::cout << "password: " << password << std::endl;

    return 0;
}
