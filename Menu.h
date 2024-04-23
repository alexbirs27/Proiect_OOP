#pragma once
#include <iostream>
#include <vector>
#include "Mancare.h"
using namespace  std;
class Menu
{
private:
	int numar_dishes;
	vector<Mancare>dishes;
public:
	Menu() = default;
	~Menu() = default;
	void SetNumar(const int& nr_)
	{
		numar_dishes = nr_;
	}
	int GetNumar() const {
		return numar_dishes;
	}
	Mancare GetMancare(int poz) const {
		return dishes[poz];
	}
	friend istream& operator>>(istream& f, Menu& meniu);
	friend ostream& operator<<(ostream& g, const Menu& meniu);
};