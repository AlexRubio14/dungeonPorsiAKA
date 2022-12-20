#pragma once
#include "Map.h"

struct Enemy {
    MapPosition position;

    bool isAlive;

    int health;
    int maxHealth;

    int stamina;
    int maxStamina;

    void Init();
};

