#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <memory>
#include "Input_Exception.h"
#include "Mancare.h"
#include "Menu.h"
#include "Restaurant.h"
#include "FastFoodRestaurant.h"
#include "FineDiningRestaurant.h"
#include "FastAndFine.h"
#include "RestaurantFactory.h"
#include "Reservation.h"

using namespace std;

int main() {


    vector<shared_ptr<Restaurant>> restaurante;
    Reservation& reservationManager = Reservation::getInstance();

    Logger logger;
    UserInterface ui;
    reservationManager.addObserver(&logger);
    reservationManager.addObserver(&ui);

    reservationManager.addReservation("Pizza Place", "18:00");
    reservationManager.addReservation("Sushi Bar", "19:00");
    reservationManager.addReservation("Burger Joint", "17:00");
    restaurante.push_back(make_shared<FastFoodRestaurant>("MCDONALDS", "Galati", 100, true));
    FineDiningRestaurant::Increase_Fine();
    FastFoodRestaurant::Increase_Fast();
    restaurante.push_back(make_shared<FineDiningRestaurant>("Bezos", "Galati", 1, "yellow"));

    cout << restaurante[0]->calcul() << '\n';
    cout << restaurante[1]->calcul() << '\n';

    FastAndFine myRestaurant("MCDonalds", "Galati", 15, true, "Smart Casual");
    cout << myRestaurant.calcul() << endl;
    cout << myRestaurant.GetDescription() << endl;

    do {
        cout << "Buna!" << endl;
        cout << "Alege optiunea de mai jos!" << endl;
        cout << "1). Doresti sa faci o rezervare la unul dintre restaurante?" << endl;
        cout << "2). Doresti sa mai adaugi un restaurant in lista celor afisate?" << endl;
        cout << "3). Doresti sa afisezi toate rezervarile?" << endl;
        cout << "0). Doresti sa parasesti?" << endl;

        int caz;
        cin >> caz;
        switch (caz) {
        case 1: {
            Restaurant::MakeReservation(restaurante, reservationManager);
            break;
        }
        case 2: {
            while (true) {
                try {
                    Restaurant::addRestaurant(restaurante);
                    break;
                }
                catch (Input_Exception& e) {
                    cout << "Ai introdus gresit" << '\n';
                    cout << e.what();
                }
            }
            break;
        }
        case 3: {
            reservationManager.displayReservations();
            break;
        }
        case 0: {
            return 0;
        }
        }
    } while (true);

    return 0;
}
