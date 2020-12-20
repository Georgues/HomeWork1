#include "rwFunc.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>

using namespace std;

void read(const std::string &fileName, deviceCollection *devices)
{

    ifstream in(fileName); //�������� ����� ��� ���������� ������
    if (!in.is_open()){
        cerr << "\n ������ ��� �������� ����� " << fileName << endl;
        return;
    }
    for(int i = 0; i < items; i++){
        in >> devices[i].id;
        in.ignore(1); //���������� ����� � ������� (;) �� �����

        getline (in, devices[i].producer, ';');

        getline (in, devices[i].model, ';');

        in >> devices[i].available;
        in.ignore(1);

        in >> devices[i].type;
        in.ignore(1);

        in >> devices[i].price;
        in.ignore(1);
    }
    cout << "\n ��� ������ ���� �������" << endl;
    in.close();
}

void write(deviceCollection *devices)
{
    // ������� ��� �������� �������� ������ �� ���� � ���������
    map <int, string> availability = {{0, "��� � �������"}, {1, "���� � �������"}};

    map <int, string> deviceType = {{0, "��������"}, {1, "���������"}};

    cout << "������� �������� �����: ";
    string fileName;
    cin >> fileName;

    ofstream out(fileName);
    if (!out.is_open()){
        cerr << "\n ������ ��� �������� ����� " << fileName << endl;
        return;
    }
    for(int i = 0; i < items; i++){
        out << devices[i].id << ";"
            << devices[i].producer << ";"
            << devices[i].model << ";"
            << availability[devices[i].available] << ";"
            << deviceType[devices[i].type] << ";"
            << devices[i].price << ";"<< endl;

    }
    cout << "\n ��� ������ ���� �������� � ���� " << fileName << endl;
    out.close();
}

void display(const deviceCollection * const devices)
{
    map <int, string> availability = {{0, "��� � �������"}, {1, "���� � �������"}};

    map <int, string> deviceType = {{0, "��������"}, {1, "��������"}, {2, "���������"}};

    for(int i = 0; i < items; i++){
        cout << devices[i].id << ";"
             << devices[i].producer << ";"
             << devices[i].model << ";"
             << availability[devices[i].available] << ";"
             << deviceType[devices[i].type] << ";"
             << devices[i].price << ";"<< endl;
    }
}

void info()
{
    cout << " ������ ���������:"
         << "\n ��������� ����� 2-5"
         << "\n �������� ��������" << endl;
}
