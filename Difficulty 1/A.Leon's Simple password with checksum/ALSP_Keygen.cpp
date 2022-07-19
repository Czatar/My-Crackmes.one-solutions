// https://crackmes.one/crackme/621a478533c5d46c8bcc0004
// C++ Solution by Carlos Zatarain
// Reverse engineered using Ghidra and x64dbg
// 7/13/2022

/*
1. In Ghidra: Search > For Strings... > Search
2. Find "Valid Password" and select it
3. In Listing, go to the XREF to find the print function, rename this
4. This function has another XREF, which leads to the main function
5. Take note of the function addresses and look for them in x64dbg
6. Place breakpoints at print or scan calls in the main and run the program.
7. Notice that rax is loaded with a value to check, and rdx is the password base
8. Notice three cmp instructions in particular:
        cmp byte ptr ds:[rdx + x], al
        which means, input[x] == al
        al = '4', '8', and '\0'
        x = 4, 8, 9
9. Using this pattern, the keygen can be created as follows:
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    std::string key = "";

    for (int i = 0; i < 8; i++)
    {
        key += (char) (33 + rand() % 95);
    }

    key[4] = '4';
    key += '0';

    std::cout << "key: " << key << std::endl;

    return 0;
}
