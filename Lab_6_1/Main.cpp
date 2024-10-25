#include <iostream>
#include <string>
#include "List.h"


using std::string;
using std::cout;


int main() {
    system("chcp 1251");
    system("cls");
    setlocale(0, "");

    // Тестирование списка с числами
    List<double> numbers;


    // Добавляем элементы
    numbers.pushBack(3.14);
    numbers.pushFront(1.41);
    numbers.pushBack(2.71);
    numbers.insert(1, 1.73);


    // Выводим список
    cout << "Список чисел:" << std::endl;
    cout << "В прямом порядке: ";
    numbers.printForward();
    cout << "В обратном порядке: ";
    numbers.printBackward();


    // Сортируем список
    insertionSort(numbers);
    cout << "После сортировки: ";
    numbers.printForward();


    // Тестирование списка со строками
    List<string> words;


    // Добавляем элементы
    words.pushBack("RoSTICK");
    words.pushFront("KingARtur1000");
    words.pushBack("NikitOS");
    words.insert(1, "StASS");


    // Выводим список
    cout << "\nСписок слов:" << std::endl;
    cout << "В прямом порядке: ";
    words.printForward();
    cout << "В обратном порядке: ";
    words.printBackward();


    // Сортируем список
    insertionSort(words);
    cout << "После сортировки: ";
    words.printForward();

    return 0;
}