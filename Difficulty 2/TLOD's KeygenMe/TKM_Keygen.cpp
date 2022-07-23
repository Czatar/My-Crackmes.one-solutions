// https://crackmes.one/crackme/609961c633c5d458ce0ec8ff
// C++ Solution by Carlos Zatarain
// Reverse engineered using Ghidra and x32dbg
// 7/22/2022

/*
1. In Ghidra: Search > For Strings... > Search
2. Find "Input name: " and select the match
3. In Listing, go to the XREF to find the main function
4. Note that there are many if statements, we can assume that there are separate
        operations for each length of input up to 9. 10+ performs the same.
5. In x32dbg, it is easy to discern what the operations are since the executable
        continues asking for credentials, so you can just set a breakpoint
        before the checks for length happen and you can test out inputs of
        varying length. For example, I tried "a" then "ab" then "abc" and so on
6. Each time I figured out the operation for a certain length, I wrote its
        algorithm in its corresponding switch case:
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    // Generate random name
    std::string name;
    size_t nameLen = 1 + (rand() % 15);

    for (size_t i = 0; i < nameLen; i++)
    {
        name += 33 + (rand() % 94);
    }

    // Generate key
    int key = 0;

    switch (nameLen)
    {
        case 1:
            key = name[0];
            break;
        case 2:
            key = name[0] * name[1];
            break;
        case 3:
            key = (((name[0] + name[1]) * name[2]) - name[0]) * name[2];
            break;
        case 4:
            key = (name[3] - (name[1] * name[2])) * name[3];
            key -= name[0] * name[0];
            break;
        case 5:
            key = (((name[4] * name[4]) - name[0]) + name[2]) * name[3];
            break;
        case 6:
            key = name[2] + ((name[0] * name[5]) / (name[4] * name[1]));
            key *= name[3];
            break;
        case 7:
            key = (name[3] - (name[0] * name[5] * name[4])) * name[0];
            key += name[5];
            key *= name[6];
            key += name[2];
            break;
        case 8:
            key = ((name[7] / name[5]) * name[6]) - name[0];
            break;
        case 9:
            key = (((name[0] * 2) / name[8]) * name[7]) * name[6];
            break;
        default:
            key = ((name[9] * name[2]) - (name[3] * name[8])) + name[5];
            key *= name[3];
            key *= name[0];
            break;
    }

    // Print out credentials
    std::cout << "name: " << name << std::endl;
    std::cout << "key: " << key << std::endl;

    return 0;
}
