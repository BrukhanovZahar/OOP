#pragma once

#include <string>
#include <memory>
#include <iostream>
#include <stdexcept>
#include "../observers/ConsoleObserver.h"
#include "../observers/FileObserver.h"

class Visitor;

enum class NPCType {
    Bear,
    Elf,
    Rogue
};

struct Coordinates {
    int x;
    int y;

    Coordinates(int x, int y) : x(x), y(y) {}
};

class NPC {
public:
    NPC(const std::string& name, const Coordinates& coords) : name(name), coordinates(coords) {}

    virtual ~NPC() {
        notifyObservers("NPC " + name + " is dead.");
    };

    virtual void attack(NPC* target) = 0;

    virtual void defend() = 0;

    virtual void accept(Visitor& visitor) = 0;

    const std::string& getName() const { return name; }

    const Coordinates& getCoordinates() const { return coordinates; }

    virtual std::string getType() const = 0;

    virtual void printInfo() const {
        std::cout << "Type: " << getType() << ", Name: " << name
                  << ", Coordinates: (" << coordinates.x << ", " << coordinates.y << ")" << std::endl;
    }

    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void rempvingObserver(Observer* observer) {
        auto elem = std::find(observers.begin(), observers.end(), observer);
        if (elem != observers.end()) {
            observers.erase(elem);
        }
    }

protected:
    void notifyObservers(const std::string& message) {
        for (Observer* observer: observers) {
            observer->update(message);
        }
    }

    std::string name;
    Coordinates coordinates;
    std::vector<Observer*> observers;
};