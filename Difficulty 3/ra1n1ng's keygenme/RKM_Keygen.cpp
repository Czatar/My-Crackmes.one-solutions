// https://crackmes.one/crackme/614b55d433c5d458fcb36575
// C++ Solution by Carlos Zatarain
// Reverse engineered using Ghidra and x32dbg
// 7/21/2022

/*
1. In Ghidra: Search > For Strings... > Search
2. Find "enter name: " and select the match
3. In Listing, go to the XREF to find the main function
4. Unfortunately, Ghidra cannot help past identifying the addresses of key
        comparisons and function calls
5. Set breakpoints at key functions and comparisons in x32dbg and make comments
        on the assembly. There is (sadly) a TON of useless code in both main
        and the function at 0x...1238
6. Instead of reading from top to bottom, I found it easier to decompile the
        assembly myself line by line starting from the bottom and managed to
        avoid having to sift through tons of code, which I assume is there
        solely to cause confusion (i.e. a lot of calls to libm_sse2_pow_precise)
7. Despite the fairly tricky code to sift through, the calculation itself was
        rather simple:
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    // Generate random name and precalculate character sum
    std::string name;
    size_t nameLen = 1 + (rand() % 19);
    int charSum = 0;

    for (size_t i = 0; i < nameLen; i++)
    {
        name += 33 + (rand() % 94);
        charSum += name[i];
    }

    // Perform operations and print out credentials
    int serial = (((charSum ^ 6) * 0x498) ^ 7) * 0xE5B0;

    std::cout << "name: " << name << std::endl;
    std::cout << "serial: " << serial << std::endl;

    return 0;
}
