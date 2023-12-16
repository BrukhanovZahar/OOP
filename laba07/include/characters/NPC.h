#pragma once

#include <string>
#include <memory>
#include <iostream>
#include <stdexcept>
#include <mutex>
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

    virtual bool canKill(NPC* target) = 0;

    virtual void defend() = 0;

    virtual void accept(Visitor& visitor) = 0;

    const std::string& getName() const {
        std::lock_guard<std::mutex> lock(mutex);
        return name;
    }

    const Coordinates& getCoordinates() const {
        std::lock_guard<std::mutex> lock(mutex);
        return coordinates;
    }

    bool isAlive() const {
        std::lock_guard<std::mutex> lock(mutex);
        return alive;
    }

    int getMoveDistance() const {
        std::lock_guard<std::mutex> lock(mutex);
        return moveDistance;
    }

    void move(int shiftX, int shiftY, int maxX, int maxY) {
        std::lock_guard<std::mutex> lock(mutex);

        coordinates.x = (coordinates.x + shiftX + maxX) % maxX;
        coordinates.y = (coordinates.y + shiftY + maxY) % maxY;
    }

    void must_die() {
        std::lock_guard<std::mutex> lck(mutex);
        alive = false;
    }

    bool isClose(const NPC* other) const {
        if (!other) {
            return false;
        }

        std::lock_guard<std::mutex> lock(mutex);

        int myX = coordinates.x;
        int myY = coordinates.y;
        int otherX = other->getCoordinates().x;
        int otherY = other->getCoordinates().y;

        if ((std::pow(abs(myX - otherX), 2) + std::pow(abs(myY - otherY), 2)) <= std::pow(attackDistance, 2)) {
            return true;
        } else {
            return false;
        }
    }

    virtual std::string getType() const = 0;

    virtual void printInfo() const {
        std::lock_guard<std::mutex> lock(mutex);
        std::cout << "Type: " << getType() << ", Name: " << name
                  << ", Coordinates: (" << coordinates.x << ", " << coordinates.y << ")" << std::endl;
    }

    void addObserver(Observer* observer) {
        std::lock_guard<std::mutex> lock(mutex);
        observers.push_back(observer);
    }

    void removingObserver(Observer* observer) {
        std::lock_guard<std::mutex> lock(mutex);
        auto elem = std::find(observers.begin(), observers.end(), observer);
        if (elem != observers.end()) {
            observers.erase(elem);
        }
    }

protected:
    void notifyObservers(const std::string& message) {
        std::lock_guard<std::mutex> lock(mutex);
        for (Observer* observer: observers) {
            observer->update(message);
        }
    }

    std::string name;
    Coordinates coordinates;
    bool alive = true;
    int moveDistance, attackDistance;
    mutable std::mutex mutex;
    std::vector<Observer*> observers;
};