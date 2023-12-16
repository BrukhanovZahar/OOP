#pragma once

#include <queue>
#include <random>
#include <thread>
#include "../characters/NPC.h"
#include "../visitor/BattleVisitor.h"

class BattleManager {
public:

    static BattleManager& get() {
        static BattleManager instance;
        return instance;
    }

    void addEvent(std::pair<NPC*, NPC*> event) {
        std::lock_guard<std::mutex> lock(mutex);
        events.push(event);
    }

    virtual void operator()();


private:


    BattleManager() {}

    std::random_device rd;
    std::queue<std::pair<NPC*, NPC*>> events;
    std::mutex mutex;
};