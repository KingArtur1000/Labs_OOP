#include "Lab_4.h"


int main() {
    system("chcp 1251");
    system("cls");
    setlocale(0, "");


    Shop shop1("Жодино");
    Shop shop2("Борисов");
    Shop shop3("Минск");

    shop1.add_product("Мороженое", 2.00, 2);
    shop1.add_product("Молоко", 2.50, 5);
    shop1.add_product("Хлеб", 1.00, 7);
    shop2.add_product("Одежда", 10, 3);
    shop3.add_product("Ноутбук", 1000, 2);

    vector<Shop::Product>& products_all_1 = shop1.get_products();
    vector<Shop::Product>& products_all_2 = shop2.get_products();
    vector<Shop::Product>& products_all_3 = shop3.get_products();

    Pokupatel pokupatel1("Жодино", 12345, 200.50);
    Pokupatel pokupatel2("Борисов", 54321, 100.50);
    Pokupatel pokupatel3("Минск", 35142, 300.50);


    pokupatel1.pokupka(products_all_1);
    pokupatel1.show(shop1);

    pokupatel1.pokupka(products_all_1);
    pokupatel1.show(shop1);

    pokupatel2.pokupka(products_all_2);
    pokupatel2.show(shop2);

    pokupatel3.pokupka(products_all_3);
    pokupatel3.show(shop3);

    return 0;
}