#pragma once

#include <iostream>
#include <string>
#include <vector>


using std::cout;
using std::cin;
using std::string;
using std::vector;


class PrintPublication {
protected:
    string m_title;
    int m_year;

public:
    PrintPublication(string title, int year)
        : m_title(title), m_year(year) {}


    virtual void show_info() const = 0;
};


class Book : public PrintPublication {
private:
    string m_author;

public:
    Book(string title, int year, string author)
        : PrintPublication(title, year), m_author(author) {}



    void show_info() const override {
        cout << "�������� �����: " << m_title << "\n�����: " << m_author << "\n��� ����������: " << m_year << "\n\n";
    }
};


class Gazeta : public PrintPublication {
private:
    string m_publisher;

public:
    Gazeta(string title, int year, string publisher)
        : PrintPublication(title, year), m_publisher(publisher) {}


    void show_info() const override {
        cout << "��������� ������: " << m_title << "\n������������: " << m_publisher << "\n��� ����������: " << m_year << "\n\n";
    }
};


class PublicationCatalog {
private:
    vector<PrintPublication*> publications;

public:
    void addPublication(PrintPublication* publication) {
        publications.push_back(publication);
    }


    void deletePublication(PrintPublication* publication) {
        auto position = find(publications.begin(), publications.end(), publication);
        publications.erase(position);
    }


    void displayAll() {
        for (auto &publication : publications) {
            publication->show_info();
        }
    }


    ~PublicationCatalog() {
        for (auto pub : publications) {
            delete pub;
        }
    }
};