#include "Lab_6.h"


int main() {
    system("chcp 1251");
    system("cls");
    setlocale(0, "");


    Matrix<int> m1(2, 2);
    m1(0, 0) = 1; m1(0, 1) = 2;
    m1(1, 0) = 3; m1(1, 1) = 4;

    Matrix<int> m2(2, 2);
    m2(0, 0) = 5; m2(0, 1) = 6;
    m2(1, 0) = 7; m2(1, 1) = 8;

    cout << "������� 1:" << '\n';
    m1.print();
    cout << '\n';

    cout << "������������ �������: " << m1.findMax() << "\n\n";
    cout << "������� ��������: " << m1.calculateAverage() << "\n\n";

    cout << "������� 2:" << '\n';
    m2.print();
    cout << '\n';

    Matrix<int> sum = m1 + m2;
    cout << "����� ������:" << '\n';
    sum.print();
    cout << '\n';

    cout << "������� 1 < ������� 2?\n";
    if (m1 < m2) cout << "��!\n";
    else cout << "���!\n";


    return 0;
}