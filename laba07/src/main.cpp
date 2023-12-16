#include "../include/characters/NPCFactory.h"
#include "../include/battle/BattleManager.h"
#include <thread>
#include <set>
#include <string>
#include <random>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <cstdlib>

const int X = 1000;
const int Y = 600;
std::vector<NPC*> characters;
std::mutex charactersMutex;
std::atomic<bool> isRunning(true);
std::map<std::string, sf::Texture> textures;

sf::Texture backgroundTexture;

void loadTextures() {
    textures["Elf"].loadFromFile("/Users/br_zahar/CLionProjects/MAI/OOP/laba07/datasets/elf02.png");
    textures["Rogue"].loadFromFile("/Users/br_zahar/CLionProjects/MAI/OOP/laba07/datasets/rogue02.png");
    textures["Bear"].loadFromFile("/Users/br_zahar/CLionProjects/MAI/OOP/laba07/datasets/bear05.png");
}

void drawField(sf::RenderWindow& window) {

    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(0.515f, 0.495f);

    sf::Color overlayColor(255, 255, 255, 35);
    sf::RectangleShape overlay(sf::Vector2f(window.getSize().x, window.getSize().y));
    overlay.setFillColor(overlayColor);

    while (isRunning) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        window.draw(backgroundSprite);
        window.draw(overlay);

        for (const NPC* character: characters) {
            if (character->isAlive()) {
                sf::Sprite sprite;
                sprite.setTexture(textures[character->getType()]);
                sprite.setScale(0.07, 0.07);
                sprite.setPosition(character->getCoordinates().x, character->getCoordinates().y);

                window.draw(sprite);
            }
        }

        window.display();
    }
}


void generateCharacters(std::mt19937& gen, const int countCharacters) {
    for (int i = 0; i < countCharacters; ++i) {
        std::string name;
        std::uniform_int_distribution<int> typeRand(0, 2);
        NPCType type = static_cast<NPCType>(typeRand(gen));
        std::string typeName;
        switch (type) {
            case NPCType::Bear:
                typeName = "Bear";
                break;
            case NPCType::Elf:
                typeName = "Elf";
                break;
            case NPCType::Rogue:
                typeName = "Rogue";
                break;
        }

        name += typeName + std::to_string(i);

        std::uniform_int_distribution<int> distX(0, X);
        std::uniform_int_distribution<int> distY(0, Y);
        int x = distX(gen);
        int y = distY(gen);

        std::lock_guard<std::mutex> lock(charactersMutex);
        characters.push_back(NPCFactory::createNPC(type, name, Coordinates(x, y)));
    }
}

void BattleManager::operator()() {
    std::mt19937 gen(rd());
    while (isRunning || !events.empty()) {
        {
            std::optional<std::pair<NPC*, NPC*>> event;

            {
                std::lock_guard<std::mutex> lock(mutex);
                if (!events.empty()) {
                    event = events.back();
                    events.pop();
                }
            }

            if (event) {
                NPC* attacker = event->first;
                NPC* defender = event->second;

                if (attacker->isAlive() && defender->isAlive()) {
                    std::uniform_int_distribution<int> chance(1, 6);
                    int attackPower = chance(gen);
                    int defenderPower = chance(gen);

                    if (attackPower > defenderPower) {
                        attacker->attack(defender);
                    }
                }
            }
        }
    }
}


void moveCharacters(std::mt19937& gen, int maxX, int maxY, int duration) {
    int counterTime = 0;
    isRunning = true;

    while (counterTime < duration) {
        for (NPC* npc: characters) {
            if (npc->isAlive()) {
                int distance = npc->getMoveDistance();
                std::uniform_int_distribution<int> dist(-distance, distance);
                int shiftX = dist(gen);
                int shiftY = dist(gen);
                npc->move(shiftX, shiftY, maxX, maxY);
            }
        }

        for (NPC* npc: characters) {
            for (NPC* other: characters) {
                if (other != npc && npc->isAlive() && other->isAlive() && npc->isClose(other) && npc->canKill(other)) {
                    BattleManager::get().addEvent({npc, other});
                }
            }
        }

        ++counterTime;
        std::cout << counterTime << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    isRunning = false;
}

int main() {

    std::random_device rd;
    std::mt19937 gen(rd());

    sf::RenderWindow window(sf::VideoMode(X + 75, Y + 90), "NPC Field");
    loadTextures();
    backgroundTexture.loadFromFile("/Users/br_zahar/CLionProjects/MAI/OOP/laba07/datasets/backgrondPlace.jpg");

    ConsoleObserver consoleObserver;
    FileObserver fileObserver;

    generateCharacters(gen, 50);

    for (NPC* character: characters) {
        character->addObserver(&consoleObserver);
        character->addObserver(&fileObserver);
    }

    std::thread battleThread(std::ref(BattleManager::get()));
    std::thread moveThread(moveCharacters, std::ref(gen), X, Y, 30);
    drawField(window);
    moveThread.join();
    battleThread.join();

    int countDied = 0;
    for (NPC* character: characters) {
        character->printInfo();
        if (!character->isAlive()){
            ++countDied;
        }
        delete character;
    }
    std::cout << "Number of dead: " <<  countDied << std::endl;
    return 0;
}