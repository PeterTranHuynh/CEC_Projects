/* **************************
File Name: Modded Base Maze.cpp
Author:   Peter Huynh
Last Mod: 04 - 07 - 2011
************************** */
//headers
#include <stdio.h>
#include <stdlib.h>

//position definition (placed here incase of errors)
struct Position
{
	int x;
	int y;
};

//function declarations
struct Position player;
struct Position target;
struct Position enemy1, enemy2;
char direction1 = 1, direction2 = 1;
int score1 = 0;

//function prototypes declarations
void DrawMap();
void HandleEnemy();
int Modulo(int nb, int mod);
void HandlePlayer(char input);
int score();

//main
int main()
{
Beginning: /* Label */
	printf("\n");

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
		scanf_s(" %c", &input);
		
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
				score();
				printf("Sorry, you failed...\n Your score is: %d\n", score1);
				goto Beginning;
			}
			else if (player.x==target.x && player.y==target.y)		/* Target reached */
			{
				score();
				printf("Congratulation, you won...\n Your score is: %d\n", score1);
				goto Beginning;
			};
		};
	};

Exit:	/* Label */
    printf("\n");
};


//function definitions
int score()
{
	if ((player.x==enemy1.x && player.y==enemy1.y) || (player.x==enemy2.x && player.y==enemy2.y))
	{
		score1--;
		return score1;
	}
	else
	{
		score1++;
		return score1;
	}
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