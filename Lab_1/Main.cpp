#include "Lab_1.h"


int main() {
    system("chcp 1251");
    system("cls");
    setlocale(0, "");


    Robot robot1;
    Robot robot2;
    Robot robot3;
    Robot robot4;
    Robot robot5;

    robot1.printSerialNumber();
    robot2.printSerialNumber();
    robot3.printSerialNumber();
    robot4.printSerialNumber();
    robot5.printSerialNumber();

    cout << "Кол-во роботов: " << Robot::getObjectCount() << '\n';

    return 0;
}