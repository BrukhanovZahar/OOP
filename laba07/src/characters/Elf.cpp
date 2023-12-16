#include "../../include/characters/Elf.h"
#include "../../include/visitor/BattleVisitor.h"

void Elf::attack(NPC* target) {
    if (dynamic_cast<Rogue*>(target) != nullptr) {
        notifyObservers(name + " is attacking and kill " + target->getName() + "!");
        target->must_die();
    } else {
        notifyObservers(name + " is attacking " + target->getName());
        target->defend();
    }
}

bool Elf::canKill(NPC* target) {
    if (dynamic_cast<Rogue*>(target) != nullptr) {
        return true;
    }
    return false;
}

void Elf::defend() {
    notifyObservers("and " + name + " is defending.");
}

void Elf::accept(Visitor& visitor) {
    visitor.visit(*this);
}

std::string Elf::getType() const {
    return "Elf";
}