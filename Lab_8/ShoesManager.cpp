#include "ShoesManager.h"


void ShoesManager::addShoes(const Shoes& newShoe) {
    bool found = false;
    for (auto& shoe : m_shoes) {
        if (shoe.getArticulNumber() == newShoe.getArticulNumber()) {
            // ��������� ������������ �����
            shoe = newShoe;
            cout << "������ ����� ���������: " << shoe.getArticulNumber() << " " << shoe.getName() << " " << shoe.getPrice() << '\n';
            found = true;
            break;
        }
    }

    if (!found) {
        // ��������� ����� �����
        m_shoes.push_back(newShoe);
        std::cout << "����� ���������: " << newShoe.getArticulNumber() << " " << newShoe.getName() << " " << newShoe.getPrice() << '\n';
    }
}


void ShoesManager::getInfo(const Shoes& shoe) {
    cout << "�������: " << shoe.getArticulNumber() << ", ������������: " << shoe.getName() << ", ����������: " << shoe.getQuantity() << '\n';
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
        if (shoe.getArticulNumber()[0] == '�') {
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
        cout << "\t���� �� ������!";
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