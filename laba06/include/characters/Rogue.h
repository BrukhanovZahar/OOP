#pragma once

#include "NPC.h"

class Rogue : public NPC {
public:
    Rogue(const std::string& name, const Coordinates& coords) : NPC(name, coords) {}

    void attack(NPC* target) override {
        if (dynamic_cast<Rogue*>(target) != nullptr) {
            notifyObservers(name + " is attacking and kill " + target->getName() + "!");
            delete target;
        } else {
            notifyObservers(name + " is attacking " + target->getName());
            target->defend();
        }
    }

    void defend() override {
        notifyObservers("and " + name + " is defending.");
    }

};