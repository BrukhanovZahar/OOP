#include "../../include/characters/Bear.h"
#include "../../include/visitor/BattleVisitor.h"

void Bear::attack(NPC* target) {
    if (dynamic_cast<Elf*>(target) != nullptr) {
        notifyObservers(name + " is attacking and kill " + target->getName() + "!");
        target->must_die();
    } else {
        notifyObservers(name + " is attacking " + target->getName());
        target->defend();
    }
}

bool Bear::canKill(NPC* target) {
    if (dynamic_cast<Elf*>(target) != nullptr) {
        return true;
    }
    return false;
}

void Bear::defend() {
    notifyObservers("and " + name + " is defending.");
}

void Bear::accept(Visitor& visitor) {
    visitor.visit(*this);
}

std::string Bear::getType() const {
    return "Bear";
}