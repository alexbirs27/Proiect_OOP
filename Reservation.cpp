#include "Reservation.h"

void Reservation::addReservation(const std::string& restaurantName, const std::string& time) {
    std::unique_ptr<std::string> reservation = std::make_unique<std::string>("Reservation at " + restaurantName + " at " + time);
    reservations.push_back(std::move(reservation));
    notifier.notifyObservers("New reservation at " + restaurantName + " at " + time);
}

void Reservation::displayReservations() const {
    std::cout << "Current Reservations:\n";
    printList(reservations); // Utiliz?m func?ia ?ablon pentru a afi?a rezerv?rile
}
