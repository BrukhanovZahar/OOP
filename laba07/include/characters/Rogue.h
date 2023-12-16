#pragma once

#include "NPC.h"

class Rogue : public NPC {
public:
    Rogue(const std::string& name, const Coordinates& coords) : NPC(name, coords) {
        moveDistance = 50;
        attackDistance = 50;
    }

    void attack(NPC* target) override;

    bool canKill(NPC* target) override;

    void defend() override;

    void accept(Visitor& visitor) override;

    std::string getType() const override;
};