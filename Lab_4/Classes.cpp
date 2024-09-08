#include "Classes.h"


// Town
void Town::show() {
	cout << "Название города - " << m_name << "\n\n";
}


// Bank
void Bank::show() {
	cout << "\t\t*** Информация о банке: ***\n\n";

	Town::show();
	cout << "Номер счёта - " << m_account_number << '\n';
	cout << "Сумма на счёте - " << m_account_number << "\n\n";
}


void Bank::popolnenie_scheta(double value) {
	m_account_money += value;
}


// Shop
void Shop::add_product(string name, double price, unsigned int amount) {
	Product product;

	product.id = products.size();
	product.name = name;
	product.price = price;
	product.amount = amount;

	products.push_back(product);
}


vector<Shop::Product>& Shop::get_products() {
	return products;
}


void Shop::show() {
	cout << "\t\t*** Информация о магазине: ***\n\n";
	Town::show();

	for (size_t i = 0; i < products.size(); i++) {
		if (products[i].amount >= 1) {
			cout << "\tПродукт №" << (i + 1) << ":\n";
			cout << "Название - " << products[i].name << '\n';
			cout << "Цена - " << products[i].price << '\n';
			cout << "Кол-во - " << products[i].amount << '\n';
			cout << "Индекс - " << products[i].id << "\n";
		}
	}
}


void Pokupatel::show(Shop shop) {
	cout << "\t\tИнформация о покупателе:\n\n";
	Bank::show();
	shop.show();

	cout << "Сумма чека: " << m_check_amount << "\n\n";
}


void Pokupatel::pokupka(vector<Product> &products) {
	cout << "\tПроцесс покупки товаров:\n";

	for (auto i = 0; i < products.size(); i++) {
		m_check_amount += products[i].price;
	}

	if (m_check_amount > this->m_account_money) {
		cout << "\tОшибка при покупке: \"Недостаточно средств!\"\n\n";
		m_check_amount = 0;
		return;
	}

	for (auto i = 0; i < products.size(); i++) {
		products[i].amount -= 1;
		if (products.at(i).amount <= 0) {
			auto this_product = find(products.begin(), products.end(), products.at(i));	// Получаем позицию нужного продукта в векторе
			products.erase(this_product);
		}
	}

	cout << "\tУспешно!\n\n";

}