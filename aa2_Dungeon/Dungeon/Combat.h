#pragma once
#include <iostream>
#include <fstream>
#include "Player.h"
#include "Enemy.h"

using namespace std;

int Barres(int primeraBarra, int segonaBarra);
void DrawEnemy(int draw);
void PlayCombat(Player& link, Enemy& goblin);
void PrintPlayer();