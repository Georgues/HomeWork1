#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <cctype>
#include <rwFunc.hpp>

using namespace std;

int main()
{
    // Смена кодировки консоли
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    return 0;
}

