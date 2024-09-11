#pragma once

#include <iostream>


using std::cout;
using std::cin;


class A {
protected:
    double a;

public:
    A(double a_val = 0) : a{a_val} {}   // Версия со списком инициализации

    /*  Версия с присваиванием в теле конструктора:
    * 
    *   A(double a_val = 0) {
    *       a = a_val;
    *   }
    */

    void show() {
        cout << '\t';

        if (a == 1) cout << "x^2 "; 
        else if (a == -1) cout << "-x^2 ";
        else cout << a << "x^2 ";
    }

    void request() {
        cout << "Введите a --> "; cin >> a;
    }
};


class B : public A {
protected:
    double b;

public:
    B(double a_val = 0, double b_val = 0) : A{ a_val }, b{ b_val } {}

    void show() {
        A::show();

        if (b == 1) cout << "x ";
        else if (b == -1) cout << "-x ";
        else cout << b << "x ";
    }

    void request() {
        A::request();
        cout << "Введите b --> "; cin >> b;
    }
};


class C : public B {
private:
    double c;

public:
    C(double a_val = 0, double b_val = 0, double c_val = 0) : B{ a_val, b_val }, c{ c_val } {}

    void show() {
        B::show();
        cout << c << '\n';
    }

    void request() {
        B::request();
        cout << "Введите c --> "; cin >> c;
    }

    void solve() {
        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            double x1 = (-b + sqrt(discriminant)) / (2 * a);
            double x2 = (-b - sqrt(discriminant)) / (2 * a);

            cout << "Два корня: x1 = " << x1 << ";   x2 = " << x2 << '\n';
        }
        else if (discriminant == 0) {
            double x = -b / (2 * a);

            cout << "Один корень: x = " << x << '\n';
        }
        else {
            cout << "Нет действительных корней" << '\n';
        }
    }
};