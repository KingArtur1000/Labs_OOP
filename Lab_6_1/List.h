#pragma once
#include <iostream>


using std::cout;


// Шаблонный класс узла списка
template<typename T>
class Node {
public:
    T data;           // Данные узла
    Node* prev;       // Указатель на предыдущий узел
    Node* next;       // Указатель на следующий узел


    // Конструктор узла
    Node(const T& value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};


// Шаблонный класс двусвязного списка
template<typename T>
class List {
private:
    Node<T>* head;    // Указатель на начало списка
    Node<T>* tail;    // Указатель на конец списка
    int size;         // Размер списка

public:
    // Конструктор списка
    List() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Деструктор списка
    ~List() {
        // Удаляем все узлы
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Добавление элемента в начало списка
    void pushFront(const T& value) {
        Node<T>* newNode = new Node<T>(value);

        if (head == nullptr) {  // Если список пуст
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    // Добавление элемента в конец списка
    void pushBack(const T& value) {
        Node<T>* newNode = new Node<T>(value);

        if (tail == nullptr) {  // Если список пуст
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    // Удаление первого элемента
    void popFront() {
        if (head == nullptr) return;  // Если список пуст

        Node<T>* temp = head;

        if (head == tail) {  // Если в списке один элемент
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
        size--;
    }

    // Удаление последнего элемента
    void popBack() {
        if (tail == nullptr) return;  // Если список пуст

        Node<T>* temp = tail;

        if (head == tail) {  // Если в списке один элемент
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete temp;
        size--;
    }

    // Вставка элемента по индексу
    void insert(int index, const T& value) {
        if (index < 0 || index > size) return;  // Проверка корректности индекса

        if (index == 0) {
            pushFront(value);
            return;
        }

        if (index == size) {
            pushBack(value);
            return;
        }

        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        Node<T>* newNode = new Node<T>(value);
        newNode->prev = current->prev;
        newNode->next = current;
        current->prev->next = newNode;
        current->prev = newNode;
        size++;
    }

    // Удаление элемента по индексу
    void remove(int index) {
        if (index < 0 || index >= size) return;  // Проверка корректности индекса

        if (index == 0) {
            popFront();
            return;
        }

        if (index == size - 1) {
            popBack();
            return;
        }

        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size--;
    }

    // Печать списка в прямом порядке
    void printForward() {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << '\n';
    }

    // Печать списка в обратном порядке
    void printBackward() {
        Node<T>* current = tail;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << '\n';
    }

    // Получение головы списка (нужно для сортировки)
    Node<T>* getHead() { return head; }

    // Установка головы списка (нужно для сортировки)
    void setHead(Node<T>* newHead) { head = newHead; }

    // Получение размера списка
    int getSize() { return size; }
};

// Функция сортировки вставками
template<typename T>
void insertionSort(List<T>& list) {
    if (list.getSize() <= 1) return;  // Если список пустой или из 1 элемента

    Node<T>* sorted = nullptr;  // Указатель на сортированную часть
    Node<T>* current = list.getHead();  // Указатель на текущий элемент

    while (current != nullptr) {
        Node<T>* next = current->next;  // Сохраняем следующий элемент

        // Если отсортированная часть пуста или текущий элемент меньше первого
        if (sorted == nullptr || sorted->data >= current->data) {
            current->next = sorted;
            current->prev = nullptr;
            if (sorted != nullptr) {
                sorted->prev = current;
            }
            sorted = current;
        }
        else {
            // Ищем место для вставки
            Node<T>* search = sorted;

            while (search->next != nullptr && search->next->data < current->data) {
                search = search->next;
            }

            current->next = search->next;
            if (search->next != nullptr) {
                search->next->prev = current;
            }
            search->next = current;
            current->prev = search;
        }

        current = next;  // Переходим к следующему элементу
    }

    list.setHead(sorted);  // Обновляем голову списка
}