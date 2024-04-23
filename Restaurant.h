#pragma once

#include <iostream>
#include "Menu.h"
using namespace std;


class Restaurant
{
protected:
	string locatie;
	string nume;
private: 
	int numar_mese;
	Menu meniu;
	static int numar_restaurante;
	
public:
	Restaurant(const string& name_, const string& locatie_, int numar_mese_)
		: nume(name_), locatie(locatie_), numar_mese(numar_mese_) {}

	Restaurant(const Restaurant& other)
		: nume(other.nume), locatie(other.locatie), numar_mese(other.numar_mese), meniu(other.meniu) {}///cpy constructor
	Restaurant() = default;
	virtual ~Restaurant() = default;


	Restaurant& operator=(const Restaurant& other) {
		if (this != &other) {
			nume = other.nume;
			locatie = other.locatie;
			numar_mese = other.numar_mese;
			meniu = other.meniu;
		}
		return *this;
	}

	virtual void SetName(const string& newnume)
	{
		nume = newnume;
	}
	void SetLocatie(const string& newlocatie)
	{
		locatie = newlocatie;
	}
	void SetNumar_Mese(const int& numar_mese_)
	{
		numar_mese = numar_mese_;
	}
	void SetMenu(const Menu& menu_)
	{
		meniu = menu_;
	}
	virtual int calcul() = 0;///activeaza polimorfismul
	Menu GetMenu() const {
		return meniu;
	}
	string GetName() const {
		return nume;
	}
	string GetLocatie() const {
		return locatie;
	}
	int GetNumar_Mese() const {
		return numar_mese;
	}
	friend istream& operator>>(istream& f, Restaurant* restaurant);
	friend ostream& operator<<(ostream& g, const Restaurant& restaurant);
	static int Get_restaurante()
	{
		return numar_restaurante;
	}

	static void addRestaurant(vector<Restaurant*>& restaurante);
	static void MakeReservation(vector<Restaurant*>& restaurante);
	static void displayMenu(vector<Restaurant*>& restaurante);
	static void displayRestaurants(vector<Restaurant*>& restaurante);
protected:
	static void Increase_Restaurante()
	{
		numar_restaurante++;
	}
};