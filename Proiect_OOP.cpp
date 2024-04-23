#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include "Input_Exception.h"
#include "Mancare.h"
#include "Menu.h"
#include "Restaurant.h"
#include "FastFoodRestaurant.h"
#include "FineDiningRestaurant.h"
#include "FastAndFine.h"
using namespace std;

int Restaurant::numar_restaurante = 0;///
int FastFoodRestaurant::numar = 0;

int FineDiningRestaurant::numar = 0;
int main()
{
	vector<Restaurant*>restaurante;
	///e upcasting vector cu restaurant*
	restaurante.push_back(  new FastFoodRestaurant("MCDONALDS", "Galati",100,1) );
	FineDiningRestaurant::Increase_Fine();
	FastFoodRestaurant::Increase_Fast();
	restaurante.push_back(new FineDiningRestaurant("Bezos", "galati", 1, "yellow"));
	cout << restaurante[0]->calcul()<<'\n';
	cout << restaurante[1]->calcul()<<'\n';
	


	FastAndFine myRestaurant("MCDonalds", "Galati", 15 ,true, "Smart Casual");
	cout << myRestaurant.calcul() << endl;
	cout << myRestaurant.GetDescription() << endl;
	do
	{
		cout << "Buna!" << endl;
		cout << "Alege optiunea de mai jos!" << endl;
		cout << "1). Doresti sa faci o rezervare la unul dintre restaurante?" << endl;
		cout << "2). Doresti sa mai adaugi un restaurant in lista celor afisate?" << endl;
		cout << "0). Doresti sa parasesti?"<<endl;
		int caz;
		cin >> caz;
		switch (caz) {
		case 1:
			cout << "Numarul de restaurante: " << Restaurant::Get_restaurante() << '\n';
			cout << "Numar Restaurante FineDining:" << FineDiningRestaurant::Get_count() << "   "<< "Numar Restaurante FastFood: " << FastFoodRestaurant::Get_count() << '\n';
			Restaurant::displayRestaurants(restaurante);
			break;
		case 2:
			while (true)
			{
				try
				{
					Restaurant::addRestaurant(restaurante);
					break;
				}
				catch (Input_Exception& e)
				{
					cout << "Ai introdus gresit" << '\n';
					cout << e.what();
				}
				
			}
			break;
		case 0:
			return 0;
		}
	} while (true);
	return 0;
}