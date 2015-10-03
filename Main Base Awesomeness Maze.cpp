/* **************************
File Name: Main Awesomeness.cpp
Author:   Peter Huynh
Last Mod: 03 - 08 - 2011
************************** */

#include <stdio.h>
#include <stdlib.h>

struct Position
{
	int x;
	int y;
};

struct Position player;
struct Position target;
struct Position enemy1, enemy2;
char direction1 = 1, direction2 = 1;

void DrawMap();
void HandleEnemy();
int Modulo(int nb, int mod);
void HandlePlayer(char input);

int main()
{
	player.x = 2, player.y = 5;
	target.x = 3, target.y = 0;
	enemy1.x = 0, enemy1.y = 1;
	enemy2.x = 5, enemy2.y = 3;

		/* Game Loop */
	while (1)
	{
		DrawMap();

		char input;
		printf("Enter a choice: l(Left), r(Right), u(Up), d(Down) and e(Exit)\n");
		scanf(" %c", &input);
		
		if (input=='e')
			goto Exit;
		else
		{
			HandlePlayer(input);
			HandleEnemy();
		
			system("cls");

			if ((player.x==enemy1.x && player.y==enemy1.y) ||		/* colliding with an enemy */
				(player.x==enemy2.x && player.y==enemy2.y))
			{
				printf("Sorry, you failed...\n");
				goto Exit;
			}
			else if (player.x==target.x && player.y==target.y)		/* Target reached */
			{
				printf("Congratulation, you won...\n");
				goto Exit;
			};
		};
	};

Exit:	/* Label */
    printf("\n");
};

void HandleEnemy()
{
	  /* Enemy1 */
	if (direction1)
		enemy1.x++;
	else
		enemy1.x--;

	if (enemy1.x == 0 || enemy1.x == 5)
		direction1 = !direction1;

	/* Enemy2 */
	if (direction2)
		enemy2.x -= 2;
	else
		enemy2.x += 2;

	if (enemy2.x <= 0 || enemy2.x >= 5)
	{
		if (direction2)
			enemy2.x++;
		else
			enemy2.x--;

		direction2 = !direction2;
	}
}

int Modulo(int nb, int mod)
{
	if (nb < 0)
		nb += mod;
	    /* the modulus function allows the player to wrap from one side to the other */
	return nb % mod;
}

void HandlePlayer(char input)
{
	int tempx = player.x,
		tempy = player.y;

	if (input == '1')
		tempx--;
	else if (input == 'r')
		tempx++;
	else if (input == 'u')
		tempy--;
	else if (input == 'd')
		tempy++;

	player.x = Modulo(tempx, 6);
	player.y = Modulo(tempy, 6);
}
void DrawMap()
{
	int y = 0;
	for (y = 0; y<6; y++) /* draw rows */
	{
		printf("\t-------------------\n");
		printf("\t");

		int x = 0;
		for (x = 0; x<7; x++) /* draw columns */
		{
			printf("|");

			/* Target Position */
			if (x == target.x && y == target.y)
				printf("T ");

			/* Enemy1 Position */
			else if (x == enemy1.x && y == enemy1.y)
				printf("<>");

			/* Enemy2 Position */
			else if (x == enemy2.x && y == enemy2.y)
				printf("<>");

			/* Player Position */
			else if (x == player.x && y == player.y)
				printf("P ");

			else
				printf(" ");
		}
		printf("\n");
	}
	printf("\t-------------------\n");
	printf("\n");
}