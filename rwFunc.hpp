#ifndef RWFUNC_HPP
#define RWFUNC_HPP
#include <string>
#include <map>

using std::string;

struct deviceCollection
{
    int id;
    string producer, model;
    int available, type, price;
};

// Количество экземпляров(строк) внутри .db файла
const int items{ 10 };

void read(const string& fileName, deviceCollection* devices);
void write(deviceCollection* devices);
void display(const deviceCollection* const devices);
void info();

#endif // RWFUNC_HPP
