#include <iostream>
#include <string>

#include "CApp.h"

int main()
{

    CApp application;

    char str[256];
    std::wcout << L"Enter command: ";

    while (std::cin.getline(str, 256)) {

        std::string inputString(str);
        std::wstring inputStringW(inputString.begin(), inputString.end());

        if (!application.parse(inputStringW))
            return 0;
        std::wcout << L"Enter command: ";
    }

    return 0;
}
