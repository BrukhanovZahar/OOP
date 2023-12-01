#pragma once

#include "NPC.h"
#include "Elf.h"

class Bear : public NPC {
public:
    Bear(const std::string& name, const Coordinates& coords) : NPC(name, coords) {}

    void attack(NPC* target) override {
        if (dynamic_cast<Elf*>(target) != nullptr) {
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