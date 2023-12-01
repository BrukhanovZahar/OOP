#include "../include/characters/NPC.h"
#include "../include/characters/Bear.h"
#include "../include/characters/Elf.h"
#include "../include/characters/Rogue.h"
#include "../include/characters/NPCFactory.h"
#include "../include/visitor/BattleVisitor.h"

int main() {

    ConsoleObserver consoleObserver;
    FileObserver fileObserver;

    std::vector<NPC*> characters;

    characters.push_back(NPCFactory::createNPC(NPCType::Elf, "Elf1", Coordinates(200, 200)));
    characters.push_back(NPCFactory::createNPC(NPCType::Rogue, "Rogue1", Coordinates(300, 300)));
    characters.push_back(NPCFactory::createNPC(NPCType::Bear, "Bear1", Coordinates(100, 100)));
    characters.push_back(NPCFactory::createNPC(NPCType::Bear, "Bear2", Coordinates(101, 101)));
    characters.push_back(NPCFactory::createNPC(NPCType::Elf, "Elf2", Coordinates(201, 201)));
    characters.push_back(NPCFactory::createNPC(NPCType::Rogue, "Rogue2", Coordinates(301, 301)));
    characters.push_back(NPCFactory::createNPC(NPCType::Rogue, "Rogue3", Coordinates(400, 400)));


    for (NPC* character: characters) {
        character->addObserver(&consoleObserver);
        character->addObserver(&fileObserver);
    }

    BattleVisitor battleVisitor(200, characters);

    auto person = characters.begin();
    while (person != characters.end()) {
        NPC* target = *person;
        target->accept(battleVisitor);
        ++person;
    }

    for (NPC* character: characters) {
        std::cout << "Person name: " << character->getName() << std::endl;
    }

    for (NPC* character: characters) {
        if (character) {
            delete character;
        }
    }

    return 0;
}