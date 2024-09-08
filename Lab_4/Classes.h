#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using std::string;
using std::cout;
using std::vector;
using std::find_if;
using std::to_string;
using std::iter_swap;



class Town {
protected:
	string m_name;

public:
	Town(string name) : m_name(name) {}

	void show();

};


class Bank : virtual public Town {
protected:
	unsigned int m_account_number;
	double m_account_money;

public:
	Bank(string town_name, unsigned int account_number, double account_money) :
		Town(town_name),
		m_account_number(account_number),
		m_account_money(account_money) {
	}

	void show();

	void popolnenie_scheta(double value);
};


class Shop : virtual public Town {
public:
	struct Product {
		unsigned int id = 0;
		string name = "";
		double price = 0.00;
		unsigned int amount = 0;
	};

protected:
	vector<Shop::Product> products;


public:
	Shop(string town_name) : Town(town_name) {}

	void add_product(string name, double price, unsigned int amount);

	vector<Product>& get_products();

	void show();

	friend bool operator==(Product product1, Product product2) {
		return product1.id == product2.id;
	}
};


class Pokupatel : public Shop, public Bank {
private:
	double m_check_amount = 0;

public:
	Pokupatel(string town_name, unsigned int account_number, double account_money) :
		Town(town_name),
		Bank(town_name, account_number, account_money),
		Shop(town_name) {
	}

	void show(Shop shop);

	vector<Product> products_to_buy;

	void pokupka(vector<Product> &products);
};