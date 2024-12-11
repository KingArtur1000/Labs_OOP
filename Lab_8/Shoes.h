#pragma once

#ifndef SHOES_H
#define SHOES_H

#include <string>


using std::string;


class Shoes {
public:
    Shoes(string articulNumber, string name, int quantity, double price);
    string getArticulNumber() const;
    string getName() const;
    int getQuantity() const;
    double getPrice() const;
    void updateQuantity(int change);

private:
    string m_articulNumber;
    string m_name;
    int m_quantity;
    double m_price;
};

#endif // SHOES_H