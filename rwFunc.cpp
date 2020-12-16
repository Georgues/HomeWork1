#include "rwFunc.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>

using std::string;
using std::endl;
using std::ifstream;
using std::cerr;
using std::getline;
using std::cout;
using std::cin;
using std::ofstream;
using std::left;
using std::right;
using std::setw;
using std::setfill;

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
            << devices[i].available << ";"
            << devices[i].type << ";"
            << devices[i].price << ";"<< endl;

    }
    cout << "\n ��� ������ ���� �������� � ���� " << fileName << endl;
    out.close();
}

void display(const deviceCollection * const devices)
{
    for(int i = 0; i < items; i++){
        cout << devices[i].id << ";"
             << devices[i].producer << ";"
             << devices[i].model << ";"
             << devices[i].available << ";"
             << devices[i].type << ";"
             << devices[i].price << ";"<< endl;
    }
}

void info()
{
    cout << " ������ ���������:"
         << "\n ��������� ����� 2-5"
         << "\n �������� ��������" << endl;
}
