#pragma once

#include <iostream>


class Robot {
private:
    static int objectCount; // Статическое поле для хранения количества созданных роботов
    int serialNumber; // Поле для хранения порядкового номера робота

public:
    Robot() {
        objectCount++; // Увеличиваем счетчик при создании нового робота
        serialNumber = objectCount; // Присваиваем порядковый номер
    }


    ~Robot() {
        objectCount--; // Уменьшаем счетчик при удалении робота
    }


    void printSerialNumber() {
        std::cout << "Я робот под номером - " << serialNumber << '\n';
    }


    static int getObjectCount() {
        return objectCount;
    }
};


int Robot::objectCount = 0; // Инициализация статического члена класса