#pragma once

#include <iostream>
#include <cmath>
#include <string>


using std::string;


// ������� ����� ��� ���������������� ����������
class CustomException {
protected:
    string message;
public:
    CustomException(string msg) : message(msg) {}
    string what() const { return message; }
};


// ���������������� ����� ���������� ��� ���������
class LogarithmException : public CustomException {
public:
    LogarithmException() : CustomException("�������� �� ��������� ��� x >= 1") {}
};


// ���������������� ����� ���������� ��� ������� �� ����
class DivisionByZeroException : public CustomException {
public:
    DivisionByZeroException() : CustomException("������� ������� �� ����") {}
};


// ������� ��� ���������� f(x) = ln(1-x)
double function(double x) {
    if (x >= 1) {
        throw LogarithmException();
    }

    return log(1 - x);
}