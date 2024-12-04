#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using std::vector;
using std::cerr;
using std::cout;
using std::cin;
using std::ifstream;
using std::string;


class Shoes {
private:
    string article;
    string name;
    int quantity;
    double price;

public:
    // �����������
    Shoes(string article, string name, int quantity, double price)
        : article(article), name(name), quantity(quantity), price(price) {}

    // �������
    string getArticle() const { return article; }
    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }

    // �������
    void setQuantity(int newQuantity) { quantity = newQuantity; }

    // ����� ��� �������� ������� � ��������� �����
    void checkAvailabilityAndCost() const {
        cout << "�������: " << article << '\n';
        cout << "�������: " << quantity << " ���(�)" << '\n';
        cout << "��������� ����� ����: " << price << " ���." << '\n';
    }

    // ��������� ���������� ��� �� 10
    void increaseQuantity() { quantity += 10; }
};

// ������� ��� ������ ������ �� �����
vector<Shoes> readShoesFromFile(const string& filename) {
    ifstream file(filename);
    vector<Shoes> shoesList;

    if (!file.is_open()) {
        cerr << "�� ������� ������� ����!" << '\n';
        return shoesList;
    }

    string article, name;
    int quantity;
    double price;
    while (file >> article >> name >> quantity >> price) {
        shoesList.emplace_back(article, name, quantity, price);
    }

    file.close();
    return shoesList;
}

// ������� ��� ������ ������������ ������� �����
void displayWomenShoes(const vector<Shoes>& shoesList) {
    int totalQuantity = 0;
    cout << "����������� ������� �����:\n";
    for (const auto& shoe : shoesList) {
        if (shoe.getArticle()[0] == '�') {
            cout << "������������: " << shoe.getName()
                << ", ����������: " << shoe.getQuantity() << " ���" << '\n';
            totalQuantity += shoe.getQuantity();
        }
    }
    cout << "����� ���������� ������� �����: " << totalQuantity << " ���" << '\n';
}

// ������� ��� ���������� ���������� ����� �� ��������
void updateQuantityByArticle(vector<Shoes>& shoesList, const string& article) {
    for (auto& shoe : shoesList) {
        if (shoe.getArticle() == article) {
            shoe.increaseQuantity();
            cout << "���������� ��� ����� �� �������� " << article << " ��������� �� 10." << '\n';
            return;
        }
    }
    cout << "����� � ��������� " << article << " �� �������." << '\n';
}

int main() {
    system("chcp 1251");
    system("cls");
    setlocale(0, "");


    string filename = "shoes.txt";
    vector<Shoes> shoesList = readShoesFromFile(filename);

    if (shoesList.empty()) {
        cout << "������ ����� ���� ��� ���� �� ��� ��������." << '\n';
        return 1;
    }

    // ������ ������������� �������
    string articleToCheck = "�101";
    cout << "�������� ������� � ��������� �����:\n";
    for (const auto& shoe : shoesList) {
        if (shoe.getArticle() == articleToCheck) {
            shoe.checkAvailabilityAndCost();
            break;
        }
    }

    cout << "\n����� ������������ ������� �����:\n";
    displayWomenShoes(shoesList);

    cout << "\n���������� ���������� �����:\n";
    string articleToUpdate;
    cout << "������� ������� ��� ����������: ";
    cin >> articleToUpdate;
    updateQuantityByArticle(shoesList, articleToUpdate);

    return 0;
}
