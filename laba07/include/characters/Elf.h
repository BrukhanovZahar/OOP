#pragma once

#include "NPC.h"
#include "Rogue.h"

class Elf : public NPC {
public:
    Elf(const std::string& name, const Coordinates& coords) : NPC(name, coords) {
        moveDistance = 10;
    }

    void attack(NPC* target) override;

    void defend() override;

    void accept(Visitor& visitor) override;

    std::string getType() const override;
};