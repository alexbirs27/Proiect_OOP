#include "Restaurant.h"
#include "Input_Exception.h"
#include "FastAndFine.h"
#include "FastFoodRestaurant.h"
#include "FineDiningRestaurant.h"
#include "RestaurantFactory.h"
#include "Reservation.h"

using namespace std;

int Restaurant::numar_restaurante = 0; // Definiția membrului static

Restaurant& Restaurant::operator=(const Restaurant& other) {
    if (this != &other) {
        nume = other.nume;
        locatie = other.locatie;
        numar_mese = other.numar_mese;
        meniu = other.meniu;
    }
    return *this;
}

void Restaurant::SetName(const string& newnume) {
    nume = newnume;
}

void Restaurant::SetLocatie(const string& newlocatie) {
    locatie = newlocatie;
}

void Restaurant::SetNumar_Mese(const int& numar_mese_) {
    numar_mese = numar_mese_;
}

void Restaurant::SetMenu(const Menu& menu_) {
    meniu = menu_;
}

Menu Restaurant::GetMenu() const {
    return meniu;
}

string Restaurant::GetName() const {
    return nume;
}

string Restaurant::GetLocatie() const {
    return locatie;
}

int Restaurant::GetNumar_Mese() const {
    return numar_mese;
}

int Restaurant::Get_restaurante() {
    return numar_restaurante;
}

void Restaurant::Increase_Restaurante() {
    numar_restaurante++;
}

ostream& operator<<(ostream& g, const Restaurant& restaurant) {
    g << "Numele Restaurantului: " << restaurant.GetName() << endl;
    g << "Locatia Restaurantului: " << restaurant.GetLocatie() << endl;
    g << "Numarul de mese: " << restaurant.GetNumar_Mese() << endl;
    return g;
}

istream& operator>>(istream& f, Restaurant& restaurant) {
    cout << "Scrie numele restaurantului: ";
    f >> restaurant.nume;
    for (auto x : restaurant.nume)
        if (isdigit(x))
            throw Name_Exception();  // upcast
    cout << "Scrie Adresa: ";
    f >> restaurant.locatie;
    for (auto x : restaurant.locatie)
        if (isdigit(x))
            throw Name_Exception();
    cout << "Scrie Numarul de mese libere: ";
    string sir;
    f >> sir;
    for (auto x : sir)
        if (isalpha(x))
            throw Number_Exception();  // upcast
    restaurant.numar_mese = stoi(sir);
    f >> restaurant.meniu;
    return f;
}

void Restaurant::addRestaurant(vector<shared_ptr<Restaurant>>& restaurante) {
    cout << "Alege tipul de restaurant:\n";
    cout << "1. Fast-Food\n";
    cout << "2. Fine-Dining\n";
    cout << "3. Fast-And-Fine\n";

    int choice;
    cin >> choice;

    RestaurantFactory* factory = nullptr;

    switch (choice) {
    case 1:
        factory = new FastFoodRestaurantFactory();
        FastFoodRestaurant::Increase_Fast();
        break;
    case 2:
        factory = new FineDiningRestaurantFactory();
        FineDiningRestaurant::Increase_Fine();
        break;
    case 3:
        factory = new FastAndFineRestaurantFactory();
        break;
    }

    try {
        shared_ptr<Restaurant> newRestaurant = factory->createRestaurant("", "", 0);
        cin >> *newRestaurant;  // Supraincarcare pentru operatorul >>

        restaurante.push_back(newRestaurant);
        Increase_Restaurante();

    }
    catch (Input_Exception& e) {
        cout << "Ai introdus gresit" << '\n';
        cout << e.what();
    }
    catch (...) {
        cout << "A apărut o eroare neașteptată!" << '\n';
    }

    delete factory;  // Curățarea memoriei
}

void Restaurant::MakeReservation(vector<shared_ptr<Restaurant>>& restaurante, Reservation& reservationManager) {
    cout << "Alege restaurantul la care doresti sa faci rezervare: ";
    string nm;
    cin >> nm;
    string ora;
    cout << "La ce ora ai dori rezervarea? ";
    cin >> ora;

    for (auto& restaurant : restaurante) {
        if (restaurant->GetName() == nm) {
            if (restaurant->GetNumar_Mese() == 0) {
                cout << "Nu avem mese libere!";
                return;
            }
            restaurant->SetNumar_Mese(restaurant->GetNumar_Mese() - 1);
            cout << "Aveti Rezervare la ora " << ora << " la restaurantul : " << nm << '\n';
            reservationManager.addReservation(nm, ora);
            return;
        }
    }

    cout << "Restaurantul nu a fost găsit!\n";
}

void Restaurant::displayMenu(vector<shared_ptr<Restaurant>>& restaurante) {
    cout << "La care restaurant ai dori sa vezi meniul? ";
    string nm;
    cin >> nm;
    for (auto restaurant : restaurante) {
        if (restaurant->GetName() == nm) {
            cout << restaurant->GetMenu();
        }
    }
}

void Restaurant::displayRestaurants(vector<shared_ptr<Restaurant>>& restaurante) {
    for (auto restaurant : restaurante) {
        cout << *restaurant << endl;
    }
    do {
        cout << "1).Doresti sa faci o rezervare la unul dintre aceste restaurante?" << endl;
        cout << "2). Doresti sa vezi meniul la unul dintre aceste restaurante?" << endl;
        cout << "0). Daca doresti sa revii la interfata standard" << endl;
        int caz;
        cin >> caz;
        switch (caz) {
        case 1: {
            break;
        }
        case 2: {
            Restaurant::displayMenu(restaurante);
            break;
        }
        case 0: {
            return;
        }
        }
    } while (true);
}
