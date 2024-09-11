#include "Lab_3.h"


int main() {
    system("chcp 1251");
    system("cls");
    setlocale(0, "");


    C equation;

    cout << "Введите коэффициенты квадратного уравнения ax^2 + bx + c = 0" << '\n';
    equation.request();

    cout << "\nВведенное уравнение:" << '\n';
    equation.show();

    cout << "\nРешение:" << '\n';
    equation.solve();


    return 0;
}