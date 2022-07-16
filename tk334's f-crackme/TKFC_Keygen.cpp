// https://crackmes.one/crackme/6194f35633c5d44c61906fe6
// C++ Solution by Carlos Zatarain
// Reverse engineered using x64dbg and Ghidra
// 7/14/2022

/*
1. In Ghidra: Search > For Strings... > Search
2. Find "Type your username: " and select it
3. In Listing, go to the XREF to find the main function
4. Functions are nicely named for you, and you can notice that the correct
        password differs when the length of the username is less than 8 or not,
        as shown in the "checkpassword" function. Also, scanf allows for a
        maximum username length of 20.
5. From the main function's logic, you can see that, depending on the length,
        a string concatenate function is called, which is later compared to
        determine if the input password is correct. In Ghidra, it may not be
        obvious to see what is being concatenated, so x64dbg is used to see.
6. Place breakpoints right after each concatenate function and see that the
        registers store a pointer to the concatenated string. It then becomes
        easy to check that the strings being concatenated are those below:
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    std::string name = "";
    size_t nameLength = 2 + (rand() % 19);

    for (size_t i = 0; i < nameLength; i++)
    {
        name += 33 + (rand() % 94);
    }

    std::cout << "username: " << name << std::endl;

    if (nameLength <= 7)
    {
        std::cout << "password: " << name << "@fsociety" << std::endl;
    }
    else
    {
        std::cout << "password: " << "Mr." << name << std::endl;
    }

    return 0;
}
