#include "menu.hpp"
#include <iostream>
#include "rwFunc.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::cerr;

int menu(const std::string filename, deviceCollection* devices){

    string currentName;
    currentName = filename;

    while (true) {
        //���������� ������������� ����
        cout << "1. ������� ����" << endl;
        cout << "2. ��������� ����" << endl;
        cout << "3. ������� �� ����� ������" << endl;
        cout << "4. �������� �������� ����� � �������" << endl;
        cout << "5. � ���������" << endl;
        cout << "6. �����" << endl;
        cout << "\n ������� ����� �������� : ";

        int chosen;
        // ���������� ������ ���������� ��������
        cin >> chosen;

        //����� ������� � ����������� �� ������ ������������(chosen)
        switch (chosen) {
                case 1:
                    read(currentName, devices);
                    system("pause");
                    system("cls"); break;
                case 2:
                    write(devices);
                    system("pause");
                    system("cls"); break;
                case 3:
                    display(devices);
                    system("pause");
                    system("cls"); break;
                case 4:
                    cout << "������� ����� �������� �����:" << endl;
                    cin >> currentName;
                    system("pause");
                    system("cls"); break;
                case 5:
                    info();
                    system("pause");
                    system("cls"); break;
                    return 0;
                case 6:
                    return EXIT_SUCCESS;
                default:
                    cerr << "\n �� ����� �� ������������ ����� ��������."
                    << endl << "����������, ��������� ����." << endl;
                    system("pause");
                    system("cls");
                }

    }
}
