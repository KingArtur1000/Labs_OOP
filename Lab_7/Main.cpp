#include "Lab_7.h"


int main() {
    system("chcp 1251");
    system("cls");
    setlocale(0, "");


    const int n1 = 21; // Для массива a
    const int n2 = 25; // Для массива b
    const int n3 = 19; // Для массива c

    vector<double> a;
    a.resize(n1);
    vector<double> b;
    b.resize(n2);
    vector<double> c;
    c.resize(n3);


    // Заполнение массива a
    cout << "Заполнение массива a:\n";
    double x = -1.0;
    for (int i = 0; i < n1; ++i, x += 0.2) {
        try {
            a[i] = function(x);
            cout << "a[" << i << "] = " << a[i] << '\n';
        }
        catch (const LogarithmException& e) {
            cerr << "Ошибка: " << e.what() << " для x = " << x << '\n';
            a[i] = 0;
        }
    }


    // Заполнение массива b псевдослучайными числами
    cout << "\nЗаполнение массива b:\n";
    srand(0); // Инициализация генератора случайных чисел
    const int range = 200; // Для диапазона от -100 до 100
    for (int i = 0; i < n2; ++i) {
        // Генерируем случайное число от -10 до 10
        int randomInt = rand() % (range + 1) - 100;
        b[i] = static_cast<double>(randomInt) / 10.0;
        cout << "b[" << i << "] = " << b[i] << '\n';
    }


    // Формирование массива c
    cout << "\nФормирование массива c:\n";
    for (int i = 1; i < n3; ++i) {
        try {
            if (b[i - 1] == 0) {
                throw DivisionByZeroException();
            }
            c[i] = a[i + 1] - 1 / b[i - 1];
            cout << "c[" << i << "] = " << c[i] << '\n';
        }
        catch (const DivisionByZeroException& e) {
            cerr << "Ошибка при вычислении c[" << i << "]: " << e.what() << '\n';
            c[i] = 0;
        }
    }


    return 0;
}