#include "Menu.h"
#include <iostream>
#include "Input_Exception.h"
using namespace std;
ostream& operator<<(ostream& g, const Menu& meniu)
{
	for (int i = 0; i < meniu.GetNumar(); i++)
		g << meniu.GetMancare(i).GetNume() << endl;
	return g;
}

istream& operator>>(istream& f, Menu& meniu)
{
	cout << "Introdu numarul de mancaruri: ";
	string nr;
	f >> nr;
	for (auto x : nr)
		if (isalpha(x))
			throw* (new Number_Exception);
	meniu.numar_dishes = stoi(nr);
	cout << "Introdu tipurile de mancare sub forma:nume, pret, gramaj si kcal" << '\n';
	for (int i = 0; i < meniu.numar_dishes; i++)
	{
		cout << "Introdu al " << i + 1 << " fel de mancare:";
		Mancare nouMancare;
		f >> nouMancare;
		meniu.dishes.push_back(nouMancare);
	}
	return f;
}