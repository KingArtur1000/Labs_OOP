#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <exception>


using std::vector;
using std::exception;
using std::cout;
using std::cerr;


class CustomException : public exception {
public:
    const char* what() const override {
        return "Произошло пользовательское исключение (^-^)";
    }
};


class ArrayManager {
public:
    vector<double> createArrayA(int n1) {
        vector<double> a(n1);
        for (int i = 0; i < n1; i++) {
            double x = -1.0 + i * 0.2;
            if (x < -1.0 || x > 3.0) {
                a[i] = 0.0;
            }
            else {
                try {
                    a[i] = log(1.0 - x);
                }
                catch (const exception& e) {
                    cerr << "Произошло исключение: " << e.what() << '\n';
                    a[i] = 0.0;
                }
            }
        }
        return a;
    }


    vector<double> createArrayB(int n2) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-10.0, 10.0);

        vector<double> b(n2);

        for (int i = 0; i < n2; i++) {
            b[i] = dis(gen);
        }

        return b;
    }


    vector<double> createArrayC(const vector<double>& a, const vector<double>& b) {
        vector<double> c(a.size());

        for (size_t i = 0; i < a.size(); i++) {
            try {
                if (b[i] == 0.0) {
                    throw CustomException();
                }
                if (i + 1 < a.size()) {
                    c[i] = a[i + 1] - 1.0 / b[i];
                }
                else {
                    c[i] = 0.0;
                }
            }
            catch (const CustomException& e) {
                cerr << "Произошло исключение: " << e.what() << '\n';
                c[i] = 0.0;
            }
            catch (const exception& e) {
                cerr << "Произошло исключение: " << e.what() << '\n';
                c[i] = 0.0;
            }
        }
        return c;
    }
};


int main() {
    system("chcp 1251");
    system("cls");
    setlocale(0, "");


    int n1 = 10, n2 = 15, n3 = 12;


    ArrayManager manager;
    vector<double> a = manager.createArrayA(n1);
    vector<double> b = manager.createArrayB(n2);
    vector<double> c = manager.createArrayC(a, b);

    // Вывод массивов
    cout << "Массив a: ";
    for (double value : a) {
        cout << value << " ";
    }
    cout << '\n';

    cout << "Массив b: ";
    for (double value : b) {
        cout << value << " ";
    }
    cout << '\n';

    cout << "Массив c: ";
    for (double value : c) {
        cout << value << " ";
    }
    cout << '\n';

    return 0;
}