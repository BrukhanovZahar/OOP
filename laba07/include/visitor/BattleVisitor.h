#pragma once

#include "Visitor.h"
#include <cmath>

class BattleVisitor : public Visitor {
public:
    BattleVisitor(int battleRadius, std::vector<NPC*>& characters) : battleRadius(battleRadius > 0 ? battleRadius : 0),
                                                                     characters(characters) {}

    void setBattleRadius(int battleRadius) {
        BattleVisitor::battleRadius = battleRadius > 0 ? battleRadius : 0;
    }

    void setCharacters(std::vector<NPC*>& characters) {
        this->characters = characters;
    }

    void visit(Bear& bear) override {
        attackInRange(&bear);
    }

    void visit(Elf& elf) override {
        attackInRange(&elf);
    }

    void visit(Rogue& rogue) override {
        attackInRange(&rogue);
    }

    void attackInRange(NPC* attacker) {
        auto person = characters.begin();
        while (person != characters.end()) {
            NPC* target = *person;
            if (target != attacker && isInRange(attacker->getCoordinates(), target->getCoordinates())) {
                attacker->attack(target);

                if (target->getName().empty() && target->getCoordinates().x == 0 && target->getCoordinates().y == 0) {
                    person = characters.erase(person);
                } else {
                    ++person;
                }
            } else {
                ++person;
            }
        }
    }

private:
    int battleRadius;
    std::vector<NPC*>& characters;

    bool isInRange(const Coordinates& coords1, const Coordinates& coords2) const {
        int distance = static_cast<int>(std::sqrt(
                std::pow(coords1.x - coords2.x, 2) + std::pow(coords1.y - coords2.y, 2)));
        return distance <= battleRadius;
    }
};