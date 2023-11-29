#pragma once

#include <string>
#include <memory>
#include <iostream>
#include <stdexcept>

enum class NPCType {
    Bear,
    Elf,
    Rogue
};

struct Coordinates {
    int x;
    int y;

    Coordinates(int x, int y) : x(x), y(y) {}
};

class NPC {
public:
    NPC(const std::string& name, const Coordinates& coords) : name(name), coordinates(coords) {}

    virtual ~NPC() {
        std::cout << "NPC " << name << " is dead." << std::endl;
    };

    virtual void attack(NPC* target) = 0;

    virtual void defend() = 0;

    const std::string& getName() const { return name; }

    const Coordinates& getCoordinates() const { return coordinates; }

protected:
    std::string name;
    Coordinates coordinates;
};