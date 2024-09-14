#pragma once

#include <iostream>
#include <cmath>
#include <string>


using std::string;


// Базовый класс для пользовательских исключений
class CustomException {
protected:
    string message;
public:
    CustomException(string msg) : message(msg) {}
    string what() const { return message; }
};


// Пользовательский класс исключения для логарифма
class LogarithmException : public CustomException {
public:
    LogarithmException() : CustomException("Логарифм не определен для x >= 1") {}
};


// Пользовательский класс исключения для деления на ноль
class DivisionByZeroException : public CustomException {
public:
    DivisionByZeroException() : CustomException("Попытка деления на ноль") {}
};


// Функция для вычисления f(x) = ln(1-x)
double function(double x) {
    if (x >= 1) {
        throw LogarithmException();
    }

    return log(1 - x);
}