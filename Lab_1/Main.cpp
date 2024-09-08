#include "Lab_1.h"


int main() {
    system("chcp 1251");
    system("cls");
    setlocale(0, "");


    Robot robot1;
    Robot robot2;
    Robot robot3;
    Robot robot4;
    Robot robot7(7);


    robot1.printSerialNumber();
    robot2.printSerialNumber();
    robot3.printSerialNumber();
    robot4.printSerialNumber();
    robot7.printSerialNumber();

    cout << "\nКол-во роботов: " << Robot::getCount() << '\n';

    return 0;
}