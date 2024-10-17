#include <iostream>


using std::cin;
using std::cout;


int main() {
    system("chcp 1251");
    system("cls");
    setlocale(0, "");


    float salary = 0;
    int experience = 0;
    float bonus = 0;
    float k = 0;
    int choice = 0;


    cout << "Введите зарплату работника --> "; cin >> salary; cout << "\n\n";
    cout << "Введите стаж работника --> "; cin >> experience; cout << "\n\n";


    if (experience > 0 && experience <= 5) {
        choice = 1;
    }
    else if (experience > 5 && experience <= 10) {
        choice = 2;
    }
    else if (experience > 10 && experience <= 15) {
        choice = 3;
    }
    else if (experience > 15) {
        choice = 4;
    }


    switch (choice) {
    case 1: k = 0.03; break;
    case 2: k = 0.05; break;
    case 3: k = 0.07; break;
    case 4: k = 0.10; break;
    default: cout << "Что-то пошло не так! Попробуйте ещё раз!";
    }


    bonus += salary * k;


    cout << "\tРазмер премии = " << bonus << "\n\n";

} 
