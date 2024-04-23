#pragma once
#include <iostream>
#include "FineDiningRestaurant.h"
#include "FastFoodRestaurant.h"
using namespace std;
class FastAndFine : public FastFoodRestaurant, public FineDiningRestaurant
{

public:
	FastAndFine(const string& name_, const string& locatie_, int numar_mese_, bool drive, string dress) :
		Restaurant(name_, locatie_, numar_mese_), FastFoodRestaurant(name_, locatie_, numar_mese_, drive), FineDiningRestaurant(name_, locatie_, numar_mese_, dress) {};
	int calcul() override
	{
		return FastFoodRestaurant::calcul() + FineDiningRestaurant::calcul();
	}
	string GetDescription() const;
};