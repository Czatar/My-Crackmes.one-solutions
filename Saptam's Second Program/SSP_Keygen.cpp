// https://crackmes.one/crackme/60c398f033c5d410b8842d67
// C++ Solution by Carlos Zatarain
// Reverse engineered using Ghidra and x32dbg
// 7/17/2022

/*
1. 1. In Ghidra: Search > For Strings... > Search
2. Find "Welcome" and select it
3. In Listing, go to the XREF to find the main function
4. Every calculation is made in the main function so it's easier to follow than
        other challenges. Renaming variables should help
5. Note that there is a for loop that reverses the digits, not copy them.
        (It took a disappointing amount of time for me using x32dbg to
        realize that it doesn't just copy digits into another variable)
6. The name does not affect the program, so a random string is produced.
        The rest of the program mimicks the program.
*/

#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    // Set random name
    std::string name = "";
    size_t nameLen = 1 + (rand() % 20);

    for (size_t i = 0; i < nameLen; i++)
    {
        name += 33 + (rand() % 94);
    }

    // Set random number and helper variables
    int num = rand() | 1;

    int firstDigit;
    int lastDigit = num % 10;
    for (int i = num; i > 0; i /= 10)
    {
        firstDigit = i % 10;
    }

    // Calculate password
    int digits = (num - lastDigit) + firstDigit * lastDigit;
    int reversed = 0;
    for (; digits > 0; digits /= 10)
    {
        reversed = (reversed * 10) + (digits % 10);
    }

    reversed += firstDigit + lastDigit;

    // Cut down the result
    int log2 = (int) log10((double) reversed);
    for (int i = log2; i > 3; i--)
    {
        reversed /= 10;
    }

    // Print keys
    std::cout << "name: " << name << std::endl;
    std::cout << "number: " << num << std::endl;
    std::cout << "password: " << reversed << std::endl;

    return 0;
}
