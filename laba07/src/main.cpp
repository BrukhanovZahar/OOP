#include "../include/characters/NPCFactory.h"
//#include "../include/battle/BattleManager.h"
//#include "../include/data/DataHandler.h"
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
    textures["Bear"].loadFromFile("/Users/br_zahar/CLionProjects/MAI/OOP/laba07/datasets/bear04.png");
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

        // Очистка окна
        window.clear();

        window.draw(backgroundSprite);
        window.draw(overlay);

        // Захватываем мьютекс перед обращением к characters
//        std::lock_guard<std::mutex> lock(charactersMutex);

        // Отрисовка каждого персонажа
        for (const NPC* character: characters) {
            if (character->isAlive()) {
                sf::Sprite sprite;
                sprite.setTexture(textures[character->getType()]);
                sprite.setScale(0.07, 0.07);
                sprite.setPosition(character->getCoordinates().x, character->getCoordinates().y);

                // Отрисовка персонажа
                window.draw(sprite);
            }
        }

        // Отображение всего, что было отрисовано
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

        // Захватываем мьютекс перед обращением к characters
        std::lock_guard<std::mutex> lock(charactersMutex);
        characters.push_back(NPCFactory::createNPC(type, name, Coordinates(x, y)));
    }
}


void moveCharacters(std::mt19937& gen, int maxX, int maxY, int duration) {
    int counterTime = 0;
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

        ++counterTime;
        std::cout << counterTime << std::endl;
//        std::lock_guard<std::mutex> lock(charactersMutex);
        for (NPC* character: characters) {
            character->printInfo();
        }

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

//    characters.push_back(NPCFactory::createNPC(NPCType::Elf, "Elf1", Coordinates(10, 10)));
//    characters.push_back(NPCFactory::createNPC(NPCType::Rogue, "Rogue1", Coordinates(990, 4)));
//    characters.push_back(NPCFactory::createNPC(NPCType::Bear, "Bear1", Coordinates(999, 999)));
//    characters.push_back(NPCFactory::createNPC(NPCType::Bear, "Bear2", Coordinates(301, 101)));
//    characters.push_back(NPCFactory::createNPC(NPCType::Elf, "Elf2", Coordinates(201, 201)));
//    characters.push_back(NPCFactory::createNPC(NPCType::Rogue, "Rogue2", Coordinates(401, 301)));
//    characters.push_back(NPCFactory::createNPC(NPCType::Rogue, "Rogue3", Coordinates(460, 400)));

    generateCharacters(gen, 50);

    std::thread moveThread(moveCharacters, std::ref(gen), X, Y, 30);
    drawField(window);
    moveThread.join();

    for (NPC* character: characters) {
        delete character;
    }

    return 0;
}