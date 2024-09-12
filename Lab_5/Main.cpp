#include "Lab_5.h"


int main() {
    system("chcp 1251");
    system("cls");
    setlocale(0, "");


    PublicationCatalog publicationCatalog;

    Book *book1 = new Book("Политэкономия", 2024, "Курегян С.В.");
    Book *book2 = new Book("Самоучитель C++", 2020, "Романко С.Ю.");
    Book *book3 = new Book("Закон Божий", 2022, "Бог");

    publicationCatalog.addPublication(book1);
    publicationCatalog.addPublication(book2);
    publicationCatalog.addPublication(book3);

    Gazeta *gazeta1 = new Gazeta("Кто я?", 2023, "Жодинские навины");
    Gazeta *gazeta2 = new Gazeta("БЕЛАЗ - новые вершины!", 2024, "Новости БЕЛАЗ");
    Gazeta *gazeta3 = new Gazeta("Итоги выборов", 2025, "БелТа");

    publicationCatalog.addPublication(gazeta1);
    publicationCatalog.addPublication(gazeta2);
    publicationCatalog.addPublication(gazeta3);

    publicationCatalog.deletePublication(gazeta3);
    publicationCatalog.deletePublication(book1);

    publicationCatalog.displayAll();


    return 0;
}