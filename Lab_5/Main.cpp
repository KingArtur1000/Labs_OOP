#include "Lab_5.h"


int main() {
    system("chcp 1251");
    system("cls");
    setlocale(0, "");


    PublicationCatalog publicationCatalog;

    Book *book1 = new Book("�������������", 2024, "������� �.�.");
    Book *book2 = new Book("����������� C++", 2020, "������� �.�.");
    Book *book3 = new Book("����� �����", 2022, "���");

    publicationCatalog.addPublication(book1);
    publicationCatalog.addPublication(book2);
    publicationCatalog.addPublication(book3);

    Gazeta *gazeta1 = new Gazeta("��� �?", 2023, "��������� ������");
    Gazeta *gazeta2 = new Gazeta("����� - ����� �������!", 2024, "������� �����");
    Gazeta *gazeta3 = new Gazeta("����� �������", 2025, "�����");

    publicationCatalog.addPublication(gazeta1);
    publicationCatalog.addPublication(gazeta2);
    publicationCatalog.addPublication(gazeta3);

    publicationCatalog.deletePublication(gazeta3);
    publicationCatalog.deletePublication(book1);

    publicationCatalog.displayAll();


    return 0;
}