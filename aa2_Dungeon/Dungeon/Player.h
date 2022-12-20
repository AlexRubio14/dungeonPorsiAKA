#pragma once
#include "Map.h"

struct Player 
{
    MapPosition position;
    int gold;

    int health;
    int maxHealth;

    int stamina;
    int maxStamina;

    int moves;
    int maxMoves;

    int potions;
    int maxPotion;

    bool isAlive;

    void Init();
};

void DrinkPotion(Player& link);