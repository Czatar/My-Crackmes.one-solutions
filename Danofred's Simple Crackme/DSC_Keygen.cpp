// https://crackmes.one/crackme/624700c033c5d42a191a5a7e
// C++ Solution by Carlos Zatarain
// Reverse engineered using Ghidra
// 7/16/2022

/*
NOTE: Despite the algorithm to get the correct serial is guessable without even
        opening it in x64dbg or Ghidra, but the actual workings are different
        than what it seems. If you use x64dbg, you should patch the dbg checks.

1. In Ghidra: Search > For Strings... > Search
2. Find "Enter your name: " and select it
3. In Listing, go to the XREF to find the main function
4. Since names of functions were not mangled, the flow is easy to follow, and
        the workings of the program work as I have written below, except it does
        not mean to hardcode "hijkl" in there.
5. The obfuscation leading to "hijkl" is that it starts with the string
        "abcdefghijklmopqrstuvwxyz" and it takes the first 5 characters, "abcde"
        and xors their value with a hardcoded value 0x58, then mods it with the
        length of the string, which is 25 (sneaky, because I assumed 26 first).
        Then it performs alphabet[modded value] to get each letter in "hijkl".
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    std::string user = "";
    std::string key;
    size_t userLen = 5 + (rand() % 6);

    for (size_t i = 0; i < userLen; i++) {
        user += 33 + (rand() % 94);
    }

    key = user.substr(0, 5);
    key += "hijkl";

    std::cout << "name: " << user << std::endl;
    std::cout << "serial key: " << key << std::endl;

    return 0;
}
