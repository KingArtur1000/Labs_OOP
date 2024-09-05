#pragma once

#include <iostream>
#include <string>
#include <regex>


using std::cin;
using std::cout;
using std::string;
using std::to_string;
using std::regex_replace;
using std::regex;


class bMoney {
private:
	long double m_moneyValue;
	string m_money;

public:
	bMoney(long double value = 0) { m_moneyValue = value; }


	long double getMoneyValue() { return m_moneyValue; }


	string getMoney() { return m_money; }


	void setMoney(string money) {
		try {
			m_money = money;

			// Удаляем знак '$' в полученной строке
			if ( money.find("$") != std::string::npos) {
				money.erase(remove(money.begin(), money.end(), '$'), money.end());
			}

			// Заменяем '.' на ',' с помощью regex
			money = regex_replace(money, regex("\\."), ",");

			m_moneyValue = stold(money);
		}
		catch(...) {
			cout << "Произошла ошибка!";
		}
	}


	friend string operator+(const long double &value, const bMoney &money);
	friend string operator+(const bMoney &money, const long double &value);
	friend string operator+(const bMoney &money1, const bMoney& money2);
	friend string operator-(const long double& value, const bMoney& money);
	friend string operator-(const bMoney& money, const long double& value);
	friend string operator-(const bMoney& money1, const bMoney& money2);
	friend string operator*(const long double& value, const bMoney& money);
	friend string operator*(const bMoney& money, const long double& value);
	friend string operator*(const bMoney& money1, const bMoney& money2);
	friend string operator/(const long double& value, const bMoney& money);
	friend string operator/(const bMoney& money, const long double& value);
	friend string operator/(const bMoney& money1, const bMoney& money2);
};


string operator+(const long double& value, const bMoney& money) {
	return to_string( value + money.m_moneyValue ).insert(0, "$");
}

string operator+(const bMoney& money, const long double& value) {
	return to_string( value + money.m_moneyValue ).insert(0, "$");
}

string operator+(const bMoney& money1, const bMoney& money2) {
	return to_string(money1.m_moneyValue + money2.m_moneyValue).insert(0, "$");
}


string operator-(const long double& value, const bMoney& money) {
	return to_string( value - money.m_moneyValue ).insert(0, "$");
}

string operator-(const bMoney& money, const long double& value) {
	return to_string( money.m_moneyValue - value ).insert(0, "$");
}

string operator-(const bMoney& money1, const bMoney& money2) {
	return to_string(money1.m_moneyValue - money2.m_moneyValue).insert(0, "$");
}


string operator*(const long double& value, const bMoney& money) {
	return to_string( value * money.m_moneyValue ).insert(0, "$");
}

string operator*(const bMoney& money, const long double& value) {
	return to_string( value * money.m_moneyValue ).insert(0, "$");
}

string operator*(const bMoney& money1, const bMoney& money2) {
	return to_string(money1.m_moneyValue * money2.m_moneyValue).insert(0, "$");
}


string operator/(const long double& value, const bMoney& money) {
	return to_string( value / money.m_moneyValue ).insert(0, "$");
}

string operator/(const bMoney& money, const long double& value) {
	return to_string( money.m_moneyValue / value ).insert(0, "$");
}

string operator/(const bMoney& money1, const bMoney& money2) {
	return to_string(money1.m_moneyValue / money2.m_moneyValue).insert(0, "$");
}