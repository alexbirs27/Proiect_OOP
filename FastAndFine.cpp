#include "FastAndFine.h"
string FastAndFine::GetDescription() const {
    cout << Restaurant::GetName() << '\n';
    string description = "Deci la restaurantul meu bagi mare fastfood de la " + nume;
    description += " si te imbraci misto ca esti smemecher in: ";
    description += FineDiningRestaurant::GetDressCode() + ".";
    return description;
}
