// https://crackmes.one/crackme/5ec75e0333c5d449d91ae5c1
// C++ Solution by Carlos Zatarain
// Reverse engineered using Ghidra and x64dbg
// 7/18/2022

/*
Note: Since this application utilizes self remapping code, analysis in x64dbg
        (without plugins) will only be useful up until finding the main function

1. Since strings are obfuscated, open x64dbg and "step over" instructions until
        you come across a call instruction that does not proceed until the user
        inputs something. This function is most likely to lead to main. Sure
        enough, going to that address in Ghidra reveals that main is (0x...0850)

2. Keeping obfuscation in mind, the code has to deobfuscate strings before
        printing them out, so just locate a "puts" function or one that takes in
        a "cin_exref" or "cout_exref" variable, ignoring the rest

3. Notice that a variable is set to 0 before calling a function that passes in
        the variable containing your input regcode and is rechecked afterwards.
        This is likely to be some sort of validation function (0x...06d0).
        Judging by the two cout functions, one can deduce that one of the check
        branches prints out "unregistered" and the other prints "registered,"
        so this is confirmed

4. Rename variables and see that a keygen is possible via brute force:
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    char regcode[16];
    long long helper;
    long long hashed = 0;

    while (hashed != 0xA50B8B0)
    {
        // Produce a key
        for (int i = 0; i < 15; i++)
        {
            regcode[i] = 33 + (rand() % 94);
        }
        regcode[15] = (3 + (rand() % 5)) << 4;

        // Hash it and check its validity
        hashed = 0;
        for (int i = 0; i < 16; i++)
        {
            hashed = (hashed * 16) + regcode[i];
            helper = hashed & 0xF0000000;

            if (helper != 0)
            {
                helper >>= 24;
                hashed = (hashed ^ helper) & 0xFFFFFFF;
            }
        }
    }

    std::cout << "regcode: " << regcode << std::endl;
    return 0;
}
