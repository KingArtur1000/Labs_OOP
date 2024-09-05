#include "Lab_2.h"


int main() {
    system("chcp 1251");
    system("cls");
    setlocale(0, "");


    bMoney money1(0);
    bMoney money2(0);
    string money = "";
    string number_temp = "";
    string result = "";


    cout << "Введите первое денежное значение (в качестве валюты разрешен '$') --> "; getline(cin, money); cout << '\n';
    money1.setMoney(money);
    cout << "Введите второе денежное значение (в качестве валюты разрешен '$') --> "; getline(cin, money); cout << '\n';
    money2.setMoney(money);
    cout << "Введите число с плавающей запятой --> "; getline(cin, number_temp); cout << "\n\n";
    long double number = stold(number_temp);


    result = number + money1;
    cout << "\tОперация #1:\n";
    cout << number << " + " << "money1 = " << result << "\n\n";

    result = money1 + number;
    cout << "\tОперация #2:\n";
    cout << "money1 + " << number << " = " << result << "\n\n";

    result = money1 + money2;
    cout << "\tОперация #3:\n";
    cout << "money1 + money2 = " << result << "\n\n";


    result = number - money1;
    cout << "\tОперация #5:\n";
    cout << number << " - " << "money1 = " << result << "\n\n";

    result = money1 - number;
    cout << "\tОперация #6:\n";
    cout << "money1 - " << number << " = " << result << "\n\n";

    result = money1 - money2;
    cout << "\tОперация #7:\n";
    cout << "money1 - money2 = " << result << "\n\n";


    result = number * money1;
    cout << "\tОперация #8:\n";
    cout << number << " * " << "money1 = " << result << "\n\n";

    result = money1 * number;
    cout << "\tОперация #9:\n";
    cout << "money1 * " << number << " = " << result << "\n\n";

    result = money1 * money2;
    cout << "\tОперация #10:\n";
    cout << "money1 * money2 = " << result << "\n\n";


    result = number / money1;
    cout << "\tОперация #11:\n";
    cout << number << " / " << "money1 = " << result << "\n\n";

    result = money1 / number;
    cout << "\tОперация #12:\n";
    cout << "money1 / " << number << " = " << result << "\n\n";

    result = money1 / money2;
    cout << "\tОперация #6:\n";
    cout << "money1 / money2 = " << result << "\n\n";

    return 0;
}