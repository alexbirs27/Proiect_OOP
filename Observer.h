#pragma once

#include <iostream>
#include <string>

class Observer {
public:
    virtual void update(const std::string& message) = 0;
    virtual ~Observer() = default;
};

class Logger : public Observer {
public:
    void update(const std::string& message) override {
        std::cout << "Logger: " << message << std::endl;
    }
};

class UserInterface : public Observer {
public:
    void update(const std::string& message) override {
        std::cout << "UserInterface: " << message << std::endl;
    }
};
