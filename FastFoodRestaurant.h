#pragma once
#include "Restaurant.h"

class FastFoodRestaurant : virtual public Restaurant {
private:
    bool hasDriveThru;
    static int numar;

public:
    FastFoodRestaurant(const string& name_, const string& locatie_, int numar_mese_, bool hasDriveThru_)
        : Restaurant(name_, locatie_, numar_mese_), hasDriveThru(hasDriveThru_) {
        Increase_Restaurante();
    }

    bool HasDriveThru() const {
        return hasDriveThru;
    }
    FastFoodRestaurant() {
        Increase_Restaurante();
    };
    ~FastFoodRestaurant() {};
    int calcul() override {
        return Restaurant::locatie.size();
    }
    void SetName(const string& newnume) {
        nume = newnume;
    }
    void SetDriveThru(bool hasDriveThru_) {
        hasDriveThru = hasDriveThru_;
    }
    static void Increase_Fast() {
        numar++;
    }
    static int Get_count() {
        return numar;
    }
};
