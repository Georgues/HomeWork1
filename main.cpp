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
    // ����� ��������� �������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //�������� ������� ��������
    deviceCollection devices[10];

    //�������� �������� �����
    string filename;
    cout << "������� �������� ����� � ������� ��� ������ ������:" << endl;

    cin >> filename;

    return  menu(filename, devices);
}

