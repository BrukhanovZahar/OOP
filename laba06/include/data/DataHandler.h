#pragma once

#include "../characters/NPC.h"
#include <fstream>
#include <json/json.h>

class DataHandler {
public:
    static void serializeToFile(const std::vector<NPC*>& characters, const std::string& filename) {
        Json::Value root;

        for (const auto& character: characters) {
            Json::Value characterData;
            characterData["type"] = character->getType();
            characterData["name"] = character->getName();
            characterData["coordinates"] = std::to_string(character->getCoordinates().x) + ", " +
                                           std::to_string(character->getCoordinates().y);
            root.append(characterData);
        }

        std::ofstream outfile(filename);
        outfile << root;
        outfile.close();
    }

    static std::vector<NPC*> deserializeFromFile(const std::string& filename) {
        std::vector<NPC*> characters;

        std::ifstream inFile(filename);
        Json::Value root;
        inFile >> root;

        for (const auto& characterDate: root) {
            std::string type = characterDate["type"].asString();
            std::string name = characterDate["name"].asString();
            std::string coordinatesStr = characterDate["coordinates"].asString();

            size_t commaPosition = coordinatesStr.find(",");
            int x = std::stoi(coordinatesStr.substr(0, commaPosition));
            int y = std::stoi(coordinatesStr.substr(commaPosition + 2));

            Coordinates coordinates(x, y);

            characters.push_back(NPCFactory::createNPC(getNPCTypeFromString(type), name, coordinates));
        }

        inFile.close();
        return characters;
    }

private:
    static NPCType getNPCTypeFromString(const std::string& type) {
        if (type == "Bear") {
            return NPCType::Bear;
        } else if (type == "Elf") {
            return NPCType::Elf;
        } else if (type == "Rogue") {
            return NPCType::Rogue;
        } else {
            throw std::invalid_argument("The data in the deserialize file has been corrupted.");
        }
    }
};