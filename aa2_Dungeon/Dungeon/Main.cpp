#include "Header.h"

enum Scene { START, NAVIGATION, COMBAT, LOOTING, GAMEOVER };

int main()
{
	
	
	srand(time(NULL));

	Scene currentScene = START;

	char action;

	Player link;
	link.Init();

	int menosEnemy = 5;
	Enemy goblin[5];
	Chest cofre[2];
	
	for (int i = 0; i < 2; i++)
		cofre[i].Init();
	
	CrearCofres(link, cofre);
	

	
	bool isPlaying = true, chestFounded = false, goblinFounded = false;

	char playerAction;

	while (isPlaying)
	{
		switch (currentScene)
		{
		case START:
			Introduction();
			currentScene = NAVIGATION;
			//afegir tota la introducció del joc
			//currentScene = NAVIGATION;
			//system("cls"); //netejar la consola
			break;
		case NAVIGATION:
			
			PrintMap (link, goblin, cofre, menosEnemy);
			cin >> action;
			MoveAction(action, link, goblin, cofre);
			ChestFounded(link, cofre, chestFounded);
			EnemyFounded(link, goblin, goblinFounded);
			if (chestFounded)
				currentScene = LOOTING;
			else if (goblinFounded)
			{
				currentScene = COMBAT;
				goblinFounded = false;

			}
			//introduir tot el mapa
			//el mapejat dels objectes, enemics...
			//moviment
			//if per entrar als diversos escenaris
			//currentScene = LOOTING; //agafa cofre
			//currentScene = COMBAT; //cau amb enemic
			//currentScene = NAVIGATION; //no cau en res
			break;
		case COMBAT:
			system("cls");
			PlayCombat(link, goblin[5]);
			system("Pause");
			if (link.isAlive == true && goblin[5].isAlive == false)
			{
				currentScene = NAVIGATION;
				menosEnemy--;
			}
			if (link.isAlive == false)
				currentScene = GAMEOVER;
			if (menosEnemy == 0)
				currentScene = GAMEOVER;
			//PlayCombat( link, goblin);
			//afegir tot el combat
			//currentScene = NAVIGATION; //torna al mapa amb 1 enemic menys al mapa
			break;
		case LOOTING:
			system("cls");
			OpenChest(link,cofre);
			chestFounded = false;
			currentScene = NAVIGATION;
			system("pause");
			//afegir tot el sistema de cofres
			break;
		case GAMEOVER:
			PrintGameover(link, isPlaying);
			//missatge de gameover
			//isPlaying = false;
			break;
		default:
			//ns que va aquí pero estava posat en els apunts
			break;
		}
	}
	return 0;
}

int RandomNumber(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

bool ChestFounded(Player& link, Chest cofre[], bool& chestFounded) {
	
	for (int i = 0; i < 2; i++)
	{
		if (link.position.x == cofre[i].position.x && link.position.y == cofre[i].position.y)
		{
			cofre[i].position.x = 30;
			//link.moves
			Scene currentScene = LOOTING;
			chestFounded = true;
		}
	}
	return chestFounded;
}

bool EnemyFounded(Player& link, Enemy goblin[], bool& goblinFounded) {

	for (int i = 0; i < 5; i++)
	{
		if (link.position.x == goblin[i].position.x && link.position.y == goblin[i].position.y)
		{
			goblin[i].position.x = 30;
			//link.moves
			Scene currentScene = COMBAT;
			goblinFounded = true;
		}
	}
	return goblinFounded;
}

