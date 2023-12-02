#include "../include/characters/NPCFactory.h"
#include "../include/battle/BattleManager.h"
#include "../include/data/DataHandler.h"

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

    DataHandler::serializeToFile(characters, "characters.json");

    // characters = DataHandler::deserializeFromFile("characters.json");

    for (NPC* character: characters) {
        character->addObserver(&consoleObserver);
        character->addObserver(&fileObserver);

        character->printInfo();
    }

    BattleManager::startBattle(characters, 200);

    for (NPC* character: characters) {
        delete character;
    }

    return 0;
}