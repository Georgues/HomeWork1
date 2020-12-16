#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <cctype>

using namespace std;

int main()
{
    // Смена кодировки консоли
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Дз 1" << endl;

    return 0;
}

