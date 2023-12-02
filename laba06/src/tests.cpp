#include <gtest/gtest.h>
#include "../include/characters/NPCFactory.h"
#include "../include/data/DataHandler.h"

class NPCFactoryTest : public testing::TestWithParam<std::tuple<NPCType, std::string, Coordinates>> {
};

TEST_P(NPCFactoryTest, CreateNPC) {
    auto param = GetParam();
    NPCType type = std::get<0>(param);
    std::string name = std::get<1>(param);
    Coordinates coords = std::get<2>(param);

    NPC* npc = NPCFactory::createNPC(type, name, coords);

    ASSERT_NE(npc, nullptr);
    EXPECT_EQ(npc->getName(), name);
    EXPECT_EQ(npc->getCoordinates().x, coords.x);
    EXPECT_EQ(npc->getCoordinates().y, coords.y);

    delete npc;
}

INSTANTIATE_TEST_SUITE_P(
        NPCFactoryTests,
        NPCFactoryTest,
        testing::Values(
                std::make_tuple(NPCType::Bear, "Bear1", Coordinates(10, 20)),
                std::make_tuple(NPCType::Elf, "Elf2", Coordinates(30, 40)),
                std::make_tuple(NPCType::Rogue, "Rogue3", Coordinates(50, 60))
        )
);

TEST(NPCDeserializeTest, DeserializeNPC) {
    std::vector<NPC*> rightNPC;
    std::vector<NPC*> characters;

    characters = DataHandler::deserializeFromFile("charactersTest.json");

    rightNPC.push_back(NPCFactory::createNPC(NPCType::Elf, "Elf1", Coordinates(200, 200)));
    rightNPC.push_back(NPCFactory::createNPC(NPCType::Rogue, "Rogue1", Coordinates(300, 300)));
    rightNPC.push_back(NPCFactory::createNPC(NPCType::Bear, "Bear1", Coordinates(100, 100)));
    rightNPC.push_back(NPCFactory::createNPC(NPCType::Bear, "Bear2", Coordinates(101, 101)));
    rightNPC.push_back(NPCFactory::createNPC(NPCType::Elf, "Elf2", Coordinates(201, 201)));
    rightNPC.push_back(NPCFactory::createNPC(NPCType::Rogue, "Rogue2", Coordinates(301, 301)));
    rightNPC.push_back(NPCFactory::createNPC(NPCType::Rogue, "Rogue3", Coordinates(400, 400)));

    for (int i{0}; i < rightNPC.size(); ++i) {
        std::string typeCheck, typeRight;
        std::string nameCheck, nameRight;

        typeRight = rightNPC[i]->getType();
        typeCheck = characters[i]->getType();
        nameRight = rightNPC[i]->getName();
        nameCheck = characters[i]->getName();
        Coordinates coordinateCheck = rightNPC[i]->getCoordinates();
        Coordinates coordinateRight = characters[i]->getCoordinates();

        ASSERT_NE(rightNPC[i], nullptr);
        ASSERT_NE(characters[i], nullptr);
        EXPECT_EQ(typeRight, typeCheck);
        EXPECT_EQ(nameCheck, nameRight);
        EXPECT_EQ(coordinateCheck.x, coordinateRight.x);
        EXPECT_EQ(coordinateCheck.y, coordinateRight.y);
    }
}

TEST(NPCFightTest, ElfRogueNPC) {
    std::string nameElf, nameRogue;
    std::string nameForElf = "Elf1", nameForRogue = "Rogue1";
    NPC* elf = NPCFactory::createNPC(NPCType::Elf, nameForElf, Coordinates(10, 10));
    NPC* rogue = NPCFactory::createNPC(NPCType::Rogue, nameForRogue, Coordinates(12, 12));

    rogue->attack(elf);
    elf->attack(rogue);
    nameElf = elf->getName();
    nameRogue = rogue->getName();
    Coordinates coordinateElf = elf->getCoordinates();
    Coordinates coordinateRogue = rogue->getCoordinates();

    EXPECT_EQ(nameElf, nameForElf);
    EXPECT_EQ(nameRogue, "");
    EXPECT_EQ(coordinateElf.x, 10);
    EXPECT_EQ(coordinateElf.y, 10);
    EXPECT_EQ(coordinateRogue.x, 0);
    EXPECT_EQ(coordinateRogue.y, 0);
}

TEST(NPCFightTest, ElfBearNPC) {
    std::string nameElf, nameBear;
    std::string nameForElf = "Elf1", nameForBear = "Bear1";
    NPC* elf = NPCFactory::createNPC(NPCType::Elf, nameForElf, Coordinates(10, 10));
    NPC* bear = NPCFactory::createNPC(NPCType::Bear, nameForBear, Coordinates(12, 12));

    elf->attack(bear);
    bear->attack(elf);
    nameElf = elf->getName();
    nameBear = bear->getName();
    Coordinates coordinateElf = elf->getCoordinates();
    Coordinates coordinateRogue = bear->getCoordinates();

    EXPECT_EQ(nameElf, "");
    EXPECT_EQ(nameBear, nameForBear);
    EXPECT_EQ(coordinateElf.x, 0);
    EXPECT_EQ(coordinateElf.y, 0);
    EXPECT_EQ(coordinateRogue.x, 12);
    EXPECT_EQ(coordinateRogue.y, 12);
}

TEST(NPCFightTest, RogueBearNPC) {
    std::string nameRogue, nameBear;
    std::string nameForRogue = "Elf1", nameForBear = "Bear1";
    NPC* rogue = NPCFactory::createNPC(NPCType::Rogue, nameForRogue, Coordinates(10, 10));
    NPC* bear = NPCFactory::createNPC(NPCType::Bear, nameForBear, Coordinates(12, 12));

    rogue->attack(bear);
    bear->attack(rogue);
    nameRogue = rogue->getName();
    nameBear = bear->getName();
    Coordinates coordinateElf = rogue->getCoordinates();
    Coordinates coordinateRogue = bear->getCoordinates();

    EXPECT_EQ(nameRogue, nameForRogue);
    EXPECT_EQ(nameBear, nameForBear);
    EXPECT_EQ(coordinateElf.x, 10);
    EXPECT_EQ(coordinateElf.y, 10);
    EXPECT_EQ(coordinateRogue.x, 12);
    EXPECT_EQ(coordinateRogue.y, 12);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}