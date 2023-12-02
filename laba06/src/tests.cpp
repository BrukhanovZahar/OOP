#include <gtest/gtest.h>
#include "../include/characters/NPCFactory.h"

class NPCFactoryTest : public testing::TestWithParam<std::tuple<NPCType, std::string, Coordinates>> {
};

TEST_P(NPCFactoryTest, CreateNPC) {
    auto param = GetParam();
    NPCType type = std::get<0>(param);
    std::string name = std::get<1>(param);
    Coordinates coords = std::get<2>(param);

    NPC* npc = NPCFactory::createNPC(type, name, coords);

    // Проверяем, что объект создан и имеет правильные параметры
    ASSERT_NE(npc, nullptr);
    EXPECT_EQ(npc->getName(), name);
    EXPECT_EQ(npc->getCoordinates().x, coords.x);
    EXPECT_EQ(npc->getCoordinates().y, coords.y);

    delete npc;
}

// Задаем параметры для теста: Bear, Elf, Rogue с разными именами и координатами
INSTANTIATE_TEST_SUITE_P(
        NPCFactoryTests,
        NPCFactoryTest,
        testing::Values(
                std::make_tuple(NPCType::Bear, "Bear1", Coordinates(10, 20)),
                std::make_tuple(NPCType::Elf, "Elf2", Coordinates(30, 40)),
                std::make_tuple(NPCType::Rogue, "Rogue3", Coordinates(50, 60))
        )
);


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}