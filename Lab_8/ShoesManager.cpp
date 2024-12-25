#include "ShoesManager.h"


void ShoesManager::addShoes(const Shoes& newShoe) {
    bool found = false;
    for (auto& shoe : m_shoes) {
        if (shoe.getArticulNumber() == newShoe.getArticulNumber()) {
            // Обновляем существующую обувь
            shoe = newShoe;
            cout << "Данные обуви обновлены: " << shoe.getArticulNumber() << " " << shoe.getName() << " " << shoe.getPrice() << '\n';
            found = true;
            break;
        }
    }

    if (!found) {
        // Добавляем новую обувь
        m_shoes.push_back(newShoe);
        std::cout << "Обувь добавлена: " << newShoe.getArticulNumber() << " " << newShoe.getName() << " " << newShoe.getPrice() << '\n';
    }
}


void ShoesManager::getInfo(const Shoes& shoe) {
    cout << "Артикул: " << shoe.getArticulNumber() << ", Наименование: " << shoe.getName() << ", Количество: " << shoe.getQuantity() << '\n';
}


Shoes ShoesManager::findShoesByArticul(const string& articulNumber) const {
    for (const auto& shoe : m_shoes) {
        if (shoe.getArticulNumber() == articulNumber) {
            return shoe;
        }
    }
    return Shoes("", "", 0, 0.0);
}


vector<Shoes> ShoesManager::findLadiesShoes() const {
    vector<Shoes> ladiesShoes;
    for (const auto& shoe : m_shoes) {
        if (shoe.getArticulNumber()[0] == 'Д') {
            ladiesShoes.push_back(shoe);
        }
    }
    return ladiesShoes;
}


void ShoesManager::updateShoeQuantity(const string& articulNumber, int change) {
    for (auto& shoe : m_shoes) {
        if (shoe.getArticulNumber() == articulNumber) {
            shoe.updateQuantity(change);
            break;
        }
    }
}


void ShoesManager::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (std::getline(file, line)) {
            istringstream iss(line);
            string articulNumber, name;
            int quantity;
            double price;
            iss >> articulNumber >> name >> quantity >> price;
            m_shoes.emplace_back(articulNumber, name, quantity, price);
        }
        file.close();
    }
    else {
        cout << "\tФайл не найден!";
    }
}


void ShoesManager::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& shoe : m_shoes) {
            file << shoe.getArticulNumber() << " " << shoe.getName() << " " << shoe.getQuantity() << " " << shoe.getPrice() << "\n";
        }
        file.close();
    }
}