#include "rwFunc.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>

using namespace std;

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
    // Словари для перевода числовых данных из базы в текстовые
    map <int, string> availability = {{0, "Нет в наличии"}, {1, "Есть в наличии"}};

    map <int, string> deviceType = {{0, "Смартфон"}, {1, "Смартчасы"}};

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
            << availability[devices[i].available] << ";"
            << deviceType[devices[i].type] << ";"
            << devices[i].price << ";"<< endl;

    }
    cout << "\n Все данные были записаны в файл " << fileName << endl;
    out.close();
}

void display(const deviceCollection * const devices)
{
    map <int, string> availability = {{0, "Нет в наличии"}, {1, "Есть в наличии"}};

    map <int, string> deviceType = {{0, "Смартфон"}, {1, "Наушники"}, {2, "Смартчасы"}};

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
    cout << " Работа выполнена:"
         << "\n Студентом ИЭУИС 2-5"
         << "\n Гостевым Георгием" << endl;
}
