#pragma once

#include <vector>
#include <string>
#include <set>
template <typename T>
class Notifier {
private:
    std::set<T*> observers;

public:
    void addObserver(T* observer) {
        observers.insert(observer);
    }

    void removeObserver(T* observer) {
        observers.erase(observer);
       // observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers(const std::string& message) {
        for (T* observer : observers) {
            observer->update(message);
        }
    }
};
