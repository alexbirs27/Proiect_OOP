#pragma once

#include "Restaurant.h"
#include <memory>

class RestaurantFactory {
public:
    virtual std::shared_ptr<Restaurant> createRestaurant(const std::string& name, const std::string& location, int numar_mese) = 0;
    virtual ~RestaurantFactory() = default;
};

class FastFoodRestaurantFactory : public RestaurantFactory {
public:
    std::shared_ptr<Restaurant> createRestaurant(const std::string& name, const std::string& location, int numar_mese) override;
};

class FineDiningRestaurantFactory : public RestaurantFactory {
public:
    std::shared_ptr<Restaurant> createRestaurant(const std::string& name, const std::string& location, int numar_mese) override;
};

class FastAndFineRestaurantFactory : public RestaurantFactory {
public:
    std::shared_ptr<Restaurant> createRestaurant(const std::string& name, const std::string& location, int numar_mese) override;
};
