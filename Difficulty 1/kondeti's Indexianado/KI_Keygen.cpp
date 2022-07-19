// https://crackmes.one/crackme/61aa430533c5d413767c9ceb
// C++ Solution by Carlos Zatarain
// Reverse engineered using x32dbg
// 7/15/2022

/*
1. This challenge was pretty straightforward albiet time consuming
2. Essentially, it takes your username using the GetUserNameA function and
        performs the following operation on it
3. Each character in your username is set based on certain conditions then is
        mapped to a character in the hidden string
*/

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <Lmcons.h>

int main()
{
    char username[UNLEN+1];
    DWORD username_len = UNLEN+1;
    GetUserNameA(username, &username_len);

    std::string key = std::string(username);
    std::string map = "ThisIsAStringOfLength26MW2";

    int keyLen = key.length();

    // Convert username into desired key
    for (int i = 0; i < keyLen; i++)
    {
        key[i] = (key[i] >= 'a') ? (key[i] - 32) : key[i];
        key[i] = map[key[i] - 'A'];
    }

    std::cout << "Key: " << key << std::endl;

    return 0;
}
