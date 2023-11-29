#pragma once

#include "NPC.h"

class Rogue : public NPC {
public:
    Rogue(const std::string& name, const Coordinates& coords) : NPC(name, coords) {}

    void attack(NPC* target) override {
        std::cout << "Rogue " << name << " is attacking ";

        if (dynamic_cast<Rogue*>(target) != nullptr) {
            std::cout << "and kill Rogue " << target->getName() << "!" << std::endl;
            delete target;
        } else {
            std::cout << target->getName();
            target->defend();
        }
    }

    void defend() override {
        std::cout << " and Rogue is defending" << std::endl;
    }

};