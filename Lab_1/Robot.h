#pragma once

#include <iostream>


class Robot {
private:
    static int objectCount; // ����������� ���� ��� �������� ���������� ��������� �������
    int serialNumber; // ���� ��� �������� ����������� ������ ������

public:
    Robot() {
        objectCount++; // ����������� ������� ��� �������� ������ ������
        serialNumber = objectCount; // ����������� ���������� �����
    }


    ~Robot() {
        objectCount--; // ��������� ������� ��� �������� ������
    }


    void printSerialNumber() {
        std::cout << "� ����� ��� ������� - " << serialNumber << '\n';
    }


    static int getObjectCount() {
        return objectCount;
    }
};


int Robot::objectCount = 0; // ������������� ������������ ����� ������