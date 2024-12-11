#include "Shoes.h"

Shoes::Shoes(string articulNumber, string name, int quantity, double price)
    : m_articulNumber(std::move(articulNumber)), m_name(std::move(name)), m_quantity(quantity), m_price(price) {}

string Shoes::getArticulNumber() const {
    return m_articulNumber;
}

string Shoes::getName() const {
    return m_name;
}

int Shoes::getQuantity() const {
    return m_quantity;
}

double Shoes::getPrice() const {
    return m_price;
}

void Shoes::updateQuantity(int change) {
    m_quantity += change;
}