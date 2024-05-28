#include "RestaurantFactory.h"
#include "FastAndFine.h"
#include "FastFoodRestaurant.h"
#include "FineDiningRestaurant.h"

std::shared_ptr<Restaurant> FastFoodRestaurantFactory::createRestaurant(const string& name, const string& location, int numar_mese) {
    return std::make_shared<FastFoodRestaurant>(name, location, numar_mese, true);
}

std::shared_ptr<Restaurant> FineDiningRestaurantFactory::createRestaurant(const string& name, const string& location, int numar_mese) {
    return std::make_shared<FineDiningRestaurant>(name, location, numar_mese, "Elegant");
}

std::shared_ptr<Restaurant> FastAndFineRestaurantFactory::createRestaurant(const string& name, const string& location, int numar_mese) {
    return std::make_shared<FastAndFine>(name, location, numar_mese, true, "Smart Casual");
}
