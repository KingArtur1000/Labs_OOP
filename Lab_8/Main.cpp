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
    // Конструктор
    Shoes(string article, string name, int quantity, double price)
        : article(article), name(name), quantity(quantity), price(price) {}

    // Геттеры
    string getArticle() const { return article; }
    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }

    // Сеттеры
    void setQuantity(int newQuantity) { quantity = newQuantity; }

    // Метод для проверки наличия и стоимости обуви
    void checkAvailabilityAndCost() const {
        cout << "Артикул: " << article << '\n';
        cout << "Наличие: " << quantity << " пар(ы)" << '\n';
        cout << "Стоимость одной пары: " << price << " руб." << '\n';
    }

    // Увеличить количество пар на 10
    void increaseQuantity() { quantity += 10; }
};

// Функция для чтения данных из файла
vector<Shoes> readShoesFromFile(const string& filename) {
    ifstream file(filename);
    vector<Shoes> shoesList;

    if (!file.is_open()) {
        cerr << "Не удалось открыть файл!" << '\n';
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

// Функция для вывода ассортимента дамской обуви
void displayWomenShoes(const vector<Shoes>& shoesList) {
    int totalQuantity = 0;
    cout << "Ассортимент дамской обуви:\n";
    for (const auto& shoe : shoesList) {
        if (shoe.getArticle()[0] == 'Д') {
            cout << "Наименование: " << shoe.getName()
                << ", Количество: " << shoe.getQuantity() << " пар" << '\n';
            totalQuantity += shoe.getQuantity();
        }
    }
    cout << "Общее количество дамской обуви: " << totalQuantity << " пар" << '\n';
}

// Функция для обновления количества обуви по артикулу
void updateQuantityByArticle(vector<Shoes>& shoesList, const string& article) {
    for (auto& shoe : shoesList) {
        if (shoe.getArticle() == article) {
            shoe.increaseQuantity();
            cout << "Количество пар обуви по артикулу " << article << " увеличено на 10." << '\n';
            return;
        }
    }
    cout << "Обувь с артикулом " << article << " не найдена." << '\n';
}

int main() {
    system("chcp 1251");
    system("cls");
    setlocale(0, "");


    string filename = "shoes.txt";
    vector<Shoes> shoesList = readShoesFromFile(filename);

    if (shoesList.empty()) {
        cout << "Список обуви пуст или файл не был прочитан." << '\n';
        return 1;
    }

    // Пример использования методов
    string articleToCheck = "Д101";
    cout << "Проверка наличия и стоимости обуви:\n";
    for (const auto& shoe : shoesList) {
        if (shoe.getArticle() == articleToCheck) {
            shoe.checkAvailabilityAndCost();
            break;
        }
    }

    cout << "\nВывод ассортимента дамской обуви:\n";
    displayWomenShoes(shoesList);

    cout << "\nОбновление количества обуви:\n";
    string articleToUpdate;
    cout << "Введите артикул для обновления: ";
    cin >> articleToUpdate;
    updateQuantityByArticle(shoesList, articleToUpdate);

    return 0;
}
