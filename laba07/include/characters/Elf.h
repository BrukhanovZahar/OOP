#pragma once

#include "NPC.h"
#include "Rogue.h"

class Elf : public NPC {
public:
    Elf(const std::string& name, const Coordinates& coords) : NPC(name, coords) {
        moveDistance = 50;
        attackDistance = 150;
    }

    void attack(NPC* target) override;

    bool canKill(NPC* target) override;

    void defend() override;

    void accept(Visitor& visitor) override;

    std::string getType() const override;
};