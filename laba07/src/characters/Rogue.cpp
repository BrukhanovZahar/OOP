#include "../../include/characters/Rogue.h"
#include "../../include/visitor/BattleVisitor.h"

void Rogue::attack(NPC* target) {
    if (dynamic_cast<Rogue*>(target) != nullptr) {
        notifyObservers(name + " is attacking and kill " + target->getName() + "!");
        target->must_die();
    } else {
        notifyObservers(name + " is attacking " + target->getName());
        target->defend();
    }
}

bool Rogue::canKill(NPC* target) {
    if (dynamic_cast<Rogue*>(target) != nullptr) {
        return true;
    }
    return false;
}

void Rogue::defend() {
    notifyObservers("and " + name + " is defending.");
}

void Rogue::accept(Visitor& visitor) {
    visitor.visit(*this);
}

std::string Rogue::getType() const {
    return "Rogue";
}