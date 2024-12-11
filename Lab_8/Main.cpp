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

    // Добавление обуви в ассортимент
    cout << "\tДобавление обуви:\n";
    manager.addShoes(Shoes("Д101", "Туфли", 100, 450.0));
    manager.addShoes(Shoes("М202", "Ботинки", 80, 250.0));
    manager.addShoes(Shoes("П303", "Сандалии", 50, 150.0));

    cout << '\n';

    // Поиск обуви по артикулу
    cout << "\tПоиск обуви по артикулу Д101\n";
    Shoes shoeC = manager.findShoesByArticul("Д101");
    cout << "Артикул: " << shoeC.getArticulNumber() << ", Наименование: " << shoeC.getName() << ", Количество: " << shoeC.getQuantity() << ", Стоимость: " << shoeC.getPrice() << '\n';

    cout << '\n';

    // Получение списка дамской обуви
    vector<Shoes> ladiesShoes = manager.findLadiesShoes();
    cout << "\tАссортимент дамской обуви:" << '\n';
    for (const auto& shoe : ladiesShoes) {
        manager.getInfo(shoe);
    }
    cout << "Общее количество пар дамской обуви: " << ladiesShoes.size() << '\n';


    // Обновление количества пар обуви
    cout << "\tОбновление кол-ва пар обуви:\n";
    string articulToUpdate;
    cout << "Введите артикул обуви для обновления количества --> ";
    cin >> articulToUpdate;
    int quantityChange = 0;
    cout << "Введите на сколько изменить количество --> ";
    cin >> quantityChange;
    manager.updateShoeQuantity(articulToUpdate, quantityChange);

    // Сохранение изменений в файл
    manager.saveToFile("shoes.txt");

    return 0;
}