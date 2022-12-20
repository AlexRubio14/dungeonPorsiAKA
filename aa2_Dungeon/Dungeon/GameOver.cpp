#include "Header.h"
void PrintGameover(Player& link, bool& isPlaying) {
	system("cls");
	if (link.isAlive)
	{
		cout << "You have win!!" << endl;
		printf("\n---- Princess Eduina  ----\n");
		printf("     _____         ____   \n");
		printf("    || UwU|   <3  |UwU |     \n");
		printf("    ||  ) )       |  __|      \n");
		printf("     |    |      || |   |  \n");
		printf("    (_____|      ||_|___|      \n");
		printf("      |  |        _|  _|     \n");
	}
	else
	{
		cout << "You have lost!" << endl;
		printf("\n---- Princess Eduina  ----\n");
		printf("      _____         ____   \n");
		printf("     |-.- ||       |T.T |     \n");
		printf("    ( (   ||       |  __|      \n");
		printf("     |    |       || |   |  \n");
		printf("     |_____)      ||_|___|      \n");
		printf("      |  |        _|  _|     \n");
	}
	isPlaying = false;
	system("pause");
}