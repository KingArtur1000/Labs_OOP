#ifndef SHOESMANAGER_H
#define SHOESMANAGER_H

#include <iostream>
#include <vector>
#include "Shoes.h"
#include <fstream>
#include <sstream>


using std::cout;
using std::vector;
using std::string;
using std::istringstream;
using std::ifstream;
using std::ofstream;


class ShoesManager {
public:
    void addShoes(const Shoes& shoe);
    void getInfo(const Shoes& shoe);
    Shoes findShoesByArticul(const std::string& articulNumber) const;
    std::vector<Shoes> findLadiesShoes() const;
    void updateShoeQuantity(const std::string& articulNumber, int change);

    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename) const;

private:
    std::vector<Shoes> m_shoes;
};

#endif // SHOESMANAGER_H