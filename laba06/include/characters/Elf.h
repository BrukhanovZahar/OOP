#pragma once

#include "NPC.h"
#include "Rogue.h"

class Elf : public NPC {
public:
    Elf(const std::string& name, const Coordinates& coords) : NPC(name, coords) {}

    void attack(NPC* target) override {
        std::cout << "Elf " << name << " is attacking ";

        if (dynamic_cast<Rogue*>(target) != nullptr) {
            std::cout << "and kill Rogue " << target->getName() << "!" << std::endl;
            delete target;
        } else {
            std::cout << target->getName();
            target->defend();
        }
    }

    void defend() override {
        std::cout << " and Elf is defending." << std::endl;
    }
};