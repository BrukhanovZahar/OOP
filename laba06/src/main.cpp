#include "../include/characters/NPC.h"
#include "../include/characters/Bear.h"
#include "../include/characters/Elf.h"
#include "../include/characters/Rogue.h"
#include "../include/characters/NPCFactory.h"

int main() {

    ConsoleObserver consoleObserver;
    FileObserver fileObserver;

    NPC* bear = NPCFactory::createNPC(NPCType::Bear, "Bear1", Coordinates(100, 100));
    NPC* bear2 = NPCFactory::createNPC(NPCType::Bear, "Bear2", Coordinates(101, 101));
    NPC* elf = NPCFactory::createNPC(NPCType::Elf, "Elf1", Coordinates(200, 200));
    NPC* elf2 = NPCFactory::createNPC(NPCType::Elf, "Elf2", Coordinates(201, 201));
    NPC* rogue = NPCFactory::createNPC(NPCType::Rogue, "Rogue1", Coordinates(300, 300));
    NPC* rogue2 = NPCFactory::createNPC(NPCType::Rogue, "Rogue2", Coordinates(301, 301));
    NPC* rogue3 = NPCFactory::createNPC(NPCType::Rogue, "Rogue3", Coordinates(302, 302));

    bear->addObserver(&consoleObserver);
    bear2->addObserver(&consoleObserver);
    elf->addObserver(&consoleObserver);
    elf2->addObserver(&consoleObserver);
    rogue->addObserver(&consoleObserver);
    rogue2->addObserver(&consoleObserver);
    rogue3->addObserver(&consoleObserver);
    bear->addObserver(&fileObserver);
    bear2->addObserver(&fileObserver);
    elf->addObserver(&fileObserver);
    elf2->addObserver(&fileObserver);
    rogue->addObserver(&fileObserver);
    rogue2->addObserver(&fileObserver);
    rogue3->addObserver(&fileObserver);

    bear->attack(elf);
    bear->attack(bear2);
    bear->attack(rogue);

    std::cout << std::endl;

    elf2->attack(bear);
    elf2->attack(rogue);

    std::cout << std::endl;

    rogue2->attack(bear);
    rogue2->attack(elf2);
    rogue2->attack(rogue3);

//    delete bear;
//    delete elf;
//    delete rogue;

    return 0;
}