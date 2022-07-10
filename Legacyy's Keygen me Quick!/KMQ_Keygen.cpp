// https://crackmes.one/crackme/60d65d0833c5d410b8843014
// C++ Solution by Carlos Zatarain
// Reverse engineered using Ghidra's decompiler
// 7/9/2022

/*
1. In Ghidra: Search > For Strings... > Search
2. Find "Congrats, you did it!" and select it
3. In Listing, go to the XREF to find the main function
4. From there, note that a certain variable gets passed into various functions
        which indicates that it's the input string. The return value is put into
        a variable which is later checked various times, indicating that it is
        some sort of 'valid' flag.
5. You will find that the code requires an input in this format:
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

int main()
{
    std::string key = "";
    srand(time(NULL));

    for (int i = 0; i < 4; i++)
    {
        key += (char) (48 + rand() % 10);
    }

    key += '-';

    for (int i = 0; i < 4; i++)
    {
        key += (char) ((33 + rand() % 95) & 0b1111110);
    }

    key += "-R";
    key += (char) (33 + rand() % 95);
    key += (char) (33 + rand() % 95);
    if (rand() % 2) key += (char) (33 + rand() % 95);

    std::cout << "key: " << key << std::endl;

    return 0;
}
