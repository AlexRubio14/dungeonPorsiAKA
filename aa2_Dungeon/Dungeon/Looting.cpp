#include "Header.h"


void Chest::Init() 
{
	position.x = RandomNumber(0, 4);
	position.y = RandomNumber(0, 4);

	gold = RandomNumber(50, 200);
}
/*
void looting::Init()
{
	looting triforce, tunic, masterSword, shield, minishCap, epona, brokenLeaf, majorasMask, navi, bomb;

	triforce.gold = 400;
	triforce.HP = 50;
	triforce.stamina = 50;
	triforce.agility = 1;
	triforce.attack = 0;

	tunic.gold = 150;
	tunic.HP = 25;
	tunic.stamina = -10;
	tunic.agility = 0;
	tunic.attack = 0;

	masterSword.gold = 275;
	masterSword.HP = 0;
	masterSword.stamina = 10;
	masterSword.agility = 0;
	masterSword.attack = 15;

	shield.gold = 100;
	shield.HP = 30;
	shield.stamina = 0;
	shield.agility = -1;
	shield.attack = 0;

	minishCap.gold = 80;
	minishCap.HP = 5;
	minishCap.stamina = 0;
	minishCap.agility = 1;
	minishCap.attack = 0;

	epona.gold = 120;
	epona.HP = 0;
	epona.stamina = 30;
	epona.agility = 2;
	epona.attack = 0;

	brokenLeaf.gold = 10;
	brokenLeaf.HP = 0;
	brokenLeaf.stamina = -10;
	brokenLeaf.agility = 0;
	brokenLeaf.attack = -10;

	majorasMask.gold = -80;
	majorasMask.HP = -40;
	majorasMask.stamina = 30;
	majorasMask.agility = 0;
	majorasMask.attack = 0;

	navi.gold = -300;
	navi.HP = -10;
	navi.stamina = -10;
	navi.agility = -1;
	navi.attack = 0;

	bomb.gold = 0;
	bomb.HP = -15;
	bomb.stamina = 0;
	bomb.agility = 0;
	bomb.attack = 0;
}
*/

void CrearCofres(Player& link, Chest cofre[]) {
	//for (int c = 0; c < 2; c++)
	//{
	for (int c = 0; c < 2; c++)
	{
		if (cofre[c].position.x == link.position.x && cofre[c].position.y == link.position.y)
		{
			cofre[c].position.x = RandomNumber(0, 4);
			cofre[c].position.y = RandomNumber(0, 4);
		}
		for (int z = 1; z < 2; z++)
		{
			if (cofre[c].position.x == cofre[c - z].position.x && cofre[c].position.y == cofre[c - c].position.y)
			{
				cofre[c].position.x = RandomNumber(0, 4);
				cofre[c].position.y = RandomNumber(0, 4);
			}
		}
	}
}

void OpenChest(Player& link, Chest cofre[]) {


	int chestGold = RandomNumber(50, 200);
	link.gold += chestGold;
	int containsPotion = RandomNumber(0,3);
	printf("----- CHEST -----\n\n > You founded a chest. You've obtained the following list of items: \n\n");
	if (containsPotion == 0){
		printf("	> %d gold!\n	> 1 Potion\n", chestGold);	//> This chest has gear equipment inside!\n ---------------------------------------\n", chestGold);
		link.potions++;
	}
	else 
	{
		printf("		> %d gold!\n", chestGold);		//> This chest has gear equipment inside!\n---------------------------------------\n", chestGold);
	}
	if (link.potions > link.maxPotion)
		link.potions = link.maxPotion;

}