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
        //Визуальное представление меню
        cout << "1. Открыть файл" << endl;
        cout << "2. Сохранить файл" << endl;
        cout << "3. Вывести на экран список" << endl;
        cout << "4. Изменить название файла с данными" << endl;
        cout << "5. О программе" << endl;
        cout << "6. Выход" << endl;
        cout << "\n Введите номер действия : ";

        int chosen;
        // Считывание номера выбранного действия
        cin >> chosen;

        //Вызов функции в зависимости от выбора пользователя(chosen)
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
                    cout << "Введите новое название файла:" << endl;
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
                    cerr << "\n Вы ввели не сущетсвующий номер действия."
                    << endl << "Пожалуйста, повторите ввод." << endl;
                    system("pause");
                    system("cls");
                }

    }
}
