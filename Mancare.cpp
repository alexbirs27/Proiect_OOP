#include "Mancare.h"
#include <iostream>
using namespace std;
istream& operator>>(istream& f, Mancare& mancare)
{
	f >> mancare.nume;
	f >> mancare.pret;
	f >> mancare.gramaj;
	f >> mancare.kcal;
	return f;
}