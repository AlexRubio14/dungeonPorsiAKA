#pragma once
#include "Map.h"
#include "Player.h"


struct Chest
{
	MapPosition position;

	bool looted;
	int gold; //pot tenir entre 50 - 200
	int hp;
	int stamina;
	int moves;
	int attack;
	bool potion;
	
	void Init();
};


void CrearCofres(Player& link, Chest cofre[]);
void OpenChest(Player& link, Chest cofre[]);