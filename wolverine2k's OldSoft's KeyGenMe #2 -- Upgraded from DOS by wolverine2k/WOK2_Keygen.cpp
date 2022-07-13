// https://crackmes.one/crackme/5c9e187b33c5d4419da55648
// C++ Solution by Carlos Zatarain
// Reverse engineered using x64dbg and Ghidra
// 7/12/2022

/*
1. In Ghidra: Search > For Strings... > Search
2. Find "Enter a serial number:" and select it
3. In Listing, go to the XREF to find the main function
4. From there, notice that there is a function acting on the "name" input String
        which indicates that it scrambles the username before comparing it.
5. Going into the function, some parts of a loop could not be recovered, so I
        took note of that function's address and opened it in x64dbg.
6. To find this address, I went to the memory map and went into the program's
        .text section, then scrolled to 0x401560.
7. From there until the sprintf function call, make sense of the assembly and
        the resulting logic should be roughly as follows:
*/

#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter your name: ";

    std::string name;
    std::cin >> name;

    size_t nameLength = name.length();
    int asciiSum = 0;
    int lVar = nameLength + 3 * (nameLength >> 1);

    for (size_t i = 0; i < nameLength; i++)
    {
        asciiSum += name[i] + i + 4;
    }

    std::cout << "Serial number: " << (lVar) << '-' << asciiSum << std::endl;

    return 0;
}
