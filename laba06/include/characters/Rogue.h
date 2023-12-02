#pragma once

#include "NPC.h"

class Rogue : public NPC {
public:
    Rogue(const std::string& name, const Coordinates& coords) : NPC(name, coords) {}

    void attack(NPC* target) override;

    void defend() override;

    void accept(Visitor& visitor) override;

    std::string getType() const override;
};