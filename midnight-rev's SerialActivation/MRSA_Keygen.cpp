// https://crackmes.one/crackme/610899ff33c5d42814fb369e
// C++ Solution by Carlos Zatarain
// Reverse engineered using Ghidra and x32dbg
// 7/19/2022

/*
1. In Ghidra: Search > For Strings... > Search
2. Find "Enter your name: " and select it
3. In Listing, go to the XREF to find the main function
4. From here, Ghidra makes it relatively tough to follow, so find the main
        function in x32dbg instead. Note that you must patch the instruction at
        0xD41019 to jmp to bypass the debugger check.
5. The main function (acting on the input serial) performs a for loop and takes
        one of two branches. Using cmp and jump instrucitons, section off the
        for loop and each if branch accordingly and make comments to assist in
        figuring out what it does.
6. You will find that mysterious variables shown in Ghidra actually correspond
        to certain characters in the serial. Also, Ghidra's decompiler
        incorrectly parenthesized the operations inside the for/if bodies, so
        you will have to verify parenthesis placement yourself by reading asm.
7. The following code is essentially identical to what the assembly does to
        generate an activation key:
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    // Generate a random serial
    std::string srl = "";

    for (int i = 0; i < 9; i++)
    {
        srl += 33 + (rand() % 94);
    }
    srl[4] = '-';

    // Generate the activation key
    int var1 = 0;
    int var2 = 0;

    for (int i = 0; i < 100; i++)
    {
        var1 += ( (srl[0] + srl[5]) ^ (srl[2] | srl[6]) ) & 0xF;
        var2 += ( (srl[1] + srl[7] + srl[8]) ^ var1) & 0xF0;
    }

    int key = var1 + var2;

    if (var2 % 2 == 0)
    {
        key += srl[8] + var2 + (srl[3] >> (var1 & 0x1));
    }
    else
    {
        key += (( srl[3] << (var1 & 0x2) ) + srl[8] + 2) | var2;
    }

    // Output serial and key
    std::cout << "serial number: " << srl << std::endl;
    std::cout << "activation key: " << key << std::endl;

    return 0;
}
