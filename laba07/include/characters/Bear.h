#pragma once

#include "NPC.h"
#include "Elf.h"

class Bear : public NPC {
public:
    Bear(const std::string& name, const Coordinates& coords) : NPC(name, coords) {
        moveDistance = 15;
        attackDistance = 50;
    }

    void attack(NPC* target) override;

    bool canKill(NPC* target) override;

    void defend() override;

    void accept(Visitor& visitor) override;

    std::string getType() const override;
};