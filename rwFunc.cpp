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
    ifstream in(fileName); //файловый поток для считывания данных
    if (!in.is_open()){
        cerr << "\n Ошибка при открытии файла " << fileName << endl;
        return;
    }
    for(int i = 0; i < items; i++){
        in >> devices[i].id;
        in.ignore(1); //пропускаем точку с запятой (;) из файла

        getline (in, devices[i].producer, ';');

        getline (in, devices[i].model, ';');

        in >> devices[i].available;
        in.ignore(1);

        in >> devices[i].type;
        in.ignore(1);

        in >> devices[i].price;
        in.ignore(1);
    }
    cout << "\n Все данные были считаны" << endl;
    in.close();
}

void write(deviceCollection *devices)
{
    cout << "Введите названия файла: ";
    string fileName;
    cin >> fileName;

    ofstream out(fileName);
    if (!out.is_open()){
        cerr << "\n Ошибка при открытии файла " << fileName << endl;
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
    cout << "\n Все данные были записаны в файл " << fileName << endl;
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
    cout << " Работа выполнена:"
         << "\n Студентом ИЭУИС 2-5"
         << "\n Гостевым Георгием" << endl;
}
