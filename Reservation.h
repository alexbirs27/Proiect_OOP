#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Notifier.h"
#include "Observer.h"

class Reservation {
private:
    std::vector<std::unique_ptr<std::string>> reservations;
    Notifier<Observer> notifier;

    // Private constructor for Singleton
    Reservation() = default;

public:
    // Delete copy constructor and assignment operator to prevent copies
    Reservation(const Reservation&) = delete;
    Reservation& operator=(const Reservation&) = delete;

    static Reservation& getInstance() {
        static Reservation instance;
        return instance;
    }

    void addReservation(const std::string& restaurantName, const std::string& time);
    void displayReservations() const;

    void addObserver(Observer* observer) {
        notifier.addObserver(observer);
    }

    void removeObserver(Observer* observer) {
        notifier.removeObserver(observer);
    }
};

// Definirea func?iei ?ablon
template <typename Container>
void printList(const Container& container) {
    for (const auto& item : container) {
        std::cout << *item << std::endl; // Presupunem c? item-ul este un pointer inteligent
    }
}
