#pragma once
#include <iostream>
#include "Restaurant.h"
using namespace std;

class FineDiningRestaurant : virtual public Restaurant {
private:
	string dressCode;
	static int numar;

public:
	FineDiningRestaurant(const string& name_, const string& locatie_, int numar_mese_, const string& dressCode_)
		: Restaurant(name_, locatie_, numar_mese_), dressCode(dressCode_) {
		Increase_Restaurante();
	}

	string GetDressCode() const {
		return dressCode;
	}
	FineDiningRestaurant() {
		Increase_Restaurante();
	}
	~FineDiningRestaurant() {};
	int calcul()
	{
		return Restaurant::locatie.size() * 10;
	}
	void SetDressCode(const string& dressCode_) {
		dressCode = dressCode_;
	}
	static void Increase_Fine()
	{
		numar++;
	}
	static int Get_count()
	{
		return numar;
	}
};