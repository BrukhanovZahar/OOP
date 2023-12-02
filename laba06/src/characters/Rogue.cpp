#include "../../include/characters/Rogue.h"
#include "../../include/visitor/BattleVisitor.h"

void Rogue::attack(NPC* target) {
    if (dynamic_cast<Rogue*>(target) != nullptr) {
        notifyObservers(name + " is attacking and kill " + target->getName() + "!");
        delete target;
    } else {
        notifyObservers(name + " is attacking " + target->getName());
        target->defend();
    }
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