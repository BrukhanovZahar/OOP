#pragma once

#include "../characters/Bear.h"
#include "../characters/Elf.h"
#include "../characters/Rogue.h"

class Visitor {
public:
    virtual ~Visitor() = default;
    virtual void visit(Bear& bear) = 0;
    virtual void visit(Elf& elf) = 0;
    virtual void visit(Rogue& rogue) = 0;
};