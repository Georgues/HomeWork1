#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <cctype>
#include <rwFunc.hpp>
#include <menu.hpp>
#include <map>

using namespace std;

int main()
{
    // —мена кодировки консоли
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //—оздание массива структур
    deviceCollection devices[10];

    //”казание названи€ файла
    string filename;
    cout << "¬ведите название файла с данными дл€ начала работы:" << endl;

    cin >> filename;

    return  menu(filename, devices);
}

