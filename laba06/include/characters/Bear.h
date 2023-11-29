#pragma once

#include "NPC.h"
#include "Elf.h"

class Bear : public NPC {
public:
    Bear(const std::string& name, const Coordinates& coords) : NPC(name, coords) {}

    void attack(NPC* target) override {
        std::cout << "Bear " << name << " is attacking ";

        if (dynamic_cast<Elf*>(target) != nullptr) {
            std::cout << "and kill Elf " << target->getName() << "!" << std::endl;
            delete target;
        } else {
            std::cout << target->getName();
            target->defend();
        }
    }

    void defend() override {
        std::cout << " and Bear is defending." << std::endl;
    }
};