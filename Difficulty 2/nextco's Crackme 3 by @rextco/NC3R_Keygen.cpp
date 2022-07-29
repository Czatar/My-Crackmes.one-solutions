// https://crackmes.one/crackme/5b7dd53233c5d441d87ccbef
// C++ Solution by Carlos Zatarain
// Reverse engineered using Ghidra
// 7/29/2022

/*
1. In Ghidra: Search > For Strings... > Search
2. Find "Target: " and select the match
3. In Listing, go to the XREF to find a function that prints out usage
4. I rename this function to "correctUsage" and check the crosslisting to see
        what calls this. While I do that, I also rename functions within this to
        "printf"
5. Going back, I find the main function, which checks for the argc value and
        calls a function with argv[1], which holds the input password. I can
        retype and rename these parameters in main.
6. The "passwordChecker" function first checks if the length is 16. We need to
        follow the flow to ensure that the return variable is set to "1," which
        requires a few values summed through loops to result in specific values
7. Notice that if you treat the 16-length password as a grid, the loops are
        actually checking for a magic square (with both diagonals) with the
        magic number 450
8. If you take the numbers 1-16 and add 104, the magic number will be 450 and
        a keygen can be made with this:
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    std::string password;

    /*
    Note: this is just some valid starting magic square that is to be
            permutated. Other starting permutations exist, so I will probably
            touch on this keygen later and allow the program to generate a wider
            variety of strings
    */

    char mSquare[4][4] = {  {105, 119, 118, 108},
                            {116, 110, 111, 113},
                            {112, 114, 115, 109},
                            {117, 107, 106, 120}};

    int rows[4] = {0, 1, 2, 3};
    int cols[4] = {0, 1, 2, 3};

    int rVal = rand() % 5;

    switch (rVal)
    {
        case 0:
            rows[0] = 3;
            rows[3] = 0;
            break;
        case 1:
            cols[3] = 0;
            cols[0] = 3;
            break;
        case 2:
            rows[1] = 2;
            rows[2] = 1;
            break;
        case 3:
            cols[1] = 2;
            cols[2] = 1;
        default:
            break;
    }

    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            password += mSquare[rows[r]][cols[c]];
        }
    }

    std::cout << rVal << " password: " << password << std::endl;

    return 0;
}
