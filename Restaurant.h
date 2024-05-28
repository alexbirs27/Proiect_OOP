#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "Menu.h"
#include "Input_Exception.h"
#include "Reservation.h"

using namespace std;

class Restaurant {
protected:
    string locatie;
    string nume;
    int numar_mese;
    Menu meniu;
    static int numar_restaurante;

public:
    Restaurant(const string& name_, const string& locatie_, int numar_mese_)
        : nume(name_), locatie(locatie_), numar_mese(numar_mese_) {
        Increase_Restaurante();
    }

    Restaurant(const Restaurant& other)
        : nume(other.nume), locatie(other.locatie), numar_mese(other.numar_mese), meniu(other.meniu) {}

    Restaurant() = default;
    virtual ~Restaurant() = default;

    Restaurant& operator=(const Restaurant& other);

    virtual void SetName(const string& newnume);
    void SetLocatie(const string& newlocatie);
    void SetNumar_Mese(const int& numar_mese_);
    void SetMenu(const Menu& menu_);
    virtual int calcul() = 0;

    Menu GetMenu() const;
    string GetName() const;
    string GetLocatie() const;
    int GetNumar_Mese() const;

    friend istream& operator>>(istream& f, Restaurant& restaurant);
    friend ostream& operator<<(ostream& g, const Restaurant& restaurant);

    static int Get_restaurante();
    static void addRestaurant(vector<shared_ptr<Restaurant>>& restaurante);
    static void MakeReservation(vector<shared_ptr<Restaurant>>& restaurante, Reservation& reservationManager);
    static void displayMenu(vector<shared_ptr<Restaurant>>& restaurante);
    static void displayRestaurants(vector<shared_ptr<Restaurant>>& restaurante);

protected:
    static void Increase_Restaurante();
};
