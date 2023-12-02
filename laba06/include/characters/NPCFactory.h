#pragma once

#include "NPC.h"
#include "Bear.h"
#include "Elf.h"
#include "Rogue.h"

class NPCFactory {
public:
    static NPC* createNPC(NPCType type, const std::string& name, const Coordinates& coords) {
        switch (type) {
            case NPCType::Bear:
                return new Bear(name, coords);
            case NPCType::Elf:
                return new Elf(name, coords);
            case NPCType::Rogue:
                return new Rogue(name, coords);
            default:
                throw std::invalid_argument("Invalid NPC type.");
        }
    }
};