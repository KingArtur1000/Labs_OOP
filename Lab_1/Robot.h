#pragma once

#include <iostream>


class Robot {
private:
    static int robotsCount; // Статическое поле для хранения количества созданных роботов
    int serialNumber; // Поле для хранения порядкового номера робота

public:
    Robot() {
        robotsCount++; // Увеличиваем счетчик при создании нового робота
        serialNumber = robotsCount; // Присваиваем порядковый номер
    }

    Robot(int serialNumber) {
        robotsCount++; // Увеличиваем счетчик при создании нового робота
        this->serialNumber = serialNumber; // Присваиваем индивидуальный порядковый номер
    }


    ~Robot() {
        robotsCount--; // Уменьшаем счетчик при удалении робота
    }


    void printSerialNumber() {
        std::cout << "Я робот под номером - " << serialNumber << '\n';
    }


    static int getCount() {
        return robotsCount;
    }
};


int Robot::robotsCount = 0; // Инициализация статического члена класса