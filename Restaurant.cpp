#include "Restaurant.h"
#include <iostream>
#include "Input_Exception.h"
#include "FastAndFine.h"
#include "FastFoodRestaurant.h"
#include "FineDiningRestaurant.h"
using namespace std;
ostream& operator<<(ostream& g, const Restaurant& restaurant)
{
	g << "Numele Restaurantului: " << restaurant.GetName() << endl;
	g << "Locatia Restaurantului: " << restaurant.GetLocatie() << endl;
	g << "Numarul de mese: " << restaurant.GetNumar_Mese() << endl;
	return g;
}
istream& operator>>(istream& f, Restaurant* restaurant) {
	cout << "Scrie numele restaurantului: ";
	f >> restaurant->nume;
	for (auto x : restaurant->nume)
		if (isdigit(x))
			throw* (new Name_Exception);///upcast
	cout << "Scrie Adresa: ";
	f >> restaurant->locatie;
	for (auto x : restaurant->locatie)
		if (isdigit(x))
			throw* (new Name_Exception);
	cout << "Scrie Numarul de mese libere: ";
	string sir;
	cin >> sir;
	for (auto x : sir)
		if (isalpha(x))
			throw* (new Number_Exception);///upcast
	restaurant->numar_mese = stoi(sir);
	cin >> restaurant->meniu;
	return f;
}
void Restaurant::addRestaurant(vector<Restaurant*>& restaurante)
{
	int tip;
	cout << "De care tip este: 0-Fast, 1-Dinning" << '\n';
	cin >> tip;
	Restaurant* newRestaurant;///upcasting
	if (tip == 0)
	{
		newRestaurant = new FastFoodRestaurant;
		FastFoodRestaurant::Increase_Fast();
	}
	else
	{
		newRestaurant = new FineDiningRestaurant;
		FineDiningRestaurant::Increase_Fine();
	}
	try {
		cin >> newRestaurant;
	}
	catch (Input_Exception& e)
	{
		cout << "Ai introdus gresit" << '\n';
		cout << e.what();
	}
	restaurante.push_back(newRestaurant);
}

void Restaurant::MakeReservation(vector<Restaurant*>& restaurante)
{
	cout << "Alege restaurantul la care doresti sa faci rezervare: ";
	string nm;
	cin >> nm;
	string ora;
	cout << "La ce ora ai dori rezervarea? ";
	cin >> ora;
	for (auto& restaurant : restaurante)
		if ((*restaurant).GetName() == nm)
		{
			if ((*restaurant).GetNumar_Mese() == 0)
			{
				cout << "Nu avem mese libere!";
				return;
			}
			(*restaurant).SetNumar_Mese((*restaurant).GetNumar_Mese() - 1);
			cout << "Aveti Rezervare la ora " << ora << " la restaurantul : " << nm << '\n';
			return;
		}
}

void Restaurant::displayMenu(vector<Restaurant*>& restaurante)
{
	cout << "La care restaurant ai dori sa vezi meniul? ";
	string nm;
	cin >> nm;
	for (auto restaurant : restaurante)
	{
		if ((*restaurant).GetName() == nm)
		{
			cout << (*restaurant).GetMenu();
		}
	}
}




void Restaurant::displayRestaurants(vector<Restaurant*>& restaurante)
{
	for (auto restaurant : restaurante)
		cout << *restaurant << endl;
	do {
		cout << "1).Doresti sa faci o rezervare la unul dintre aceste restaurante?" << endl;
		cout << "2). Doresti sa vezi meniul la unul dintre aceste restaurante?" << endl;
		cout << "0). Daca doresti sa revii la interfata standard" << endl;
		int caz;
		cin >> caz;
		switch (caz)
		{
		case 1: {
			Restaurant::MakeReservation(restaurante);
			break;
		}
		case 2:
		{
			Restaurant::displayMenu(restaurante);
			break;
		}
		case 0:
		{
			return;
		}
		}
	} while (true);
}