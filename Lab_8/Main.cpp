#include <iostream>
#include "ShoesManager.h"


using std::cout;
using std::cin;
using std::vector;


int main() {
    system("chcp 1251");
    system("cls");
    setlocale(0, "");


    ShoesManager manager;
    manager.loadFromFile("shoes.txt");

    // ���������� ����� � �����������
    cout << "\t���������� �����:\n";
    manager.addShoes(Shoes("�101", "�����", 100, 450.0));
    manager.addShoes(Shoes("�202", "�������", 80, 250.0));
    manager.addShoes(Shoes("�303", "��������", 50, 150.0));

    cout << '\n';

    // ����� ����� �� ��������
    cout << "\t����� ����� �� �������� �101\n";
    Shoes shoeC = manager.findShoesByArticul("�101");
    cout << "�������: " << shoeC.getArticulNumber() << ", ������������: " << shoeC.getName() << ", ����������: " << shoeC.getQuantity() << ", ���������: " << shoeC.getPrice() << '\n';

    cout << '\n';

    // ��������� ������ ������� �����
    vector<Shoes> ladiesShoes = manager.findLadiesShoes();
    cout << "\t����������� ������� �����:" << '\n';
    for (const auto& shoe : ladiesShoes) {
        manager.getInfo(shoe);
    }
    cout << "����� ���������� ��� ������� �����: " << ladiesShoes.size() << '\n';


    // ���������� ���������� ��� �����
    cout << "\t���������� ���-�� ��� �����:\n";
    string articulToUpdate;
    cout << "������� ������� ����� ��� ���������� ���������� --> ";
    cin >> articulToUpdate;
    int quantityChange = 0;
    cout << "������� �� ������� �������� ���������� --> ";
    cin >> quantityChange;
    manager.updateShoeQuantity(articulToUpdate, quantityChange);

    // ���������� ��������� � ����
    manager.saveToFile("shoes.txt");

    return 0;
}