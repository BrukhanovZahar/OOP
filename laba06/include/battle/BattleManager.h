#pragma once

#include "../characters/NPC.h"
#include "../visitor/BattleVisitor.h"

class BattleManager {
public:
    static void startBattle(std::vector<NPC*>& characters, int battleRadius) {
        BattleVisitor battleVisitor(battleRadius, characters);

        printMessage("Start battle.");

        auto person = characters.begin();
        while (person != characters.end()) {
            NPC* target = *person;
            target->accept(battleVisitor);
            ++person;
        }

        printMessage("Info after battle:");

        for (NPC* character: characters) {
            character->printInfo();
        }

        printMessage("End battle.");
    }

private:
    static void printMessage(const std::string& message) {
        std::cout << "\033[32m";

        for (int i = 0; i < 80; ++i) {
            std::cout << "-";
        }
        std::cout << std::endl;

        std::cout << message << std::endl;

        for (int i = 0; i < 80; ++i) {
            std::cout << "-";
        }

        std::cout << "\033[0m" << std::endl;
    }
};