/*
 * userInteraction.c

 *
 *  Created on: 29 Mar 2017
 *      Author: liliana
 */

#include <stdio.h>
#include <time.h>
#include "crossfireOperations.h"
	// ** add code that means only be implemented against players who are located in the same slot as the attacker player or in the slots that are adjacent
//This function returns the board size provided as input by the user
int getBoardSize(){
	int boardSize;
	printf("Please enter the required size of the board\n");
	//asks the user to enter the desired board size
	scanf("%d", &boardSize);
	return boardSize;
}

//THis function takes as input the size of the board and the pointers
// to the integers representing the row and the column of the slot that
// the user want to retrieve
void getDesiredElement(int boardSize, int * row, int * col){
	printf("Please enter the column and the Row of the desired slot \n");
	printf("Note that size of the board is %d\n", boardSize);

		//it will cycle asking the user to insert the row
		//until the value of the desired row is >= 0 or < of the
		// size of the board
		do {
			printf("Row: ");
			scanf("%d", row);
			printf("%d\n", *row);
			if(row < 0 && *row >= boardSize)
				printf("Error: Incorrect row dimension\n");
		} while(*row < 0 && *row >= boardSize);

		//it will cycle asking the user to insert the column
		//until the value of the desired row is >= 0 or < of the
		// size of the board
		do {
			printf("Column: ");
			scanf("%d", col);
			printf("%d\n", *col);
			if(*col < 0 && *col >= boardSize)
				printf("Error: Incorrect column dimension\n");
		} while(*col < 0 && *col >= boardSize);
}

// Randomly assign values Elf
player elf( player players[], int numplayers)
{
	srand(time(NULL));
	strcpy(players[numplayers].type, "Elf");
	players[numplayers].smartness = (rand()%(100-70))+70;
	players[numplayers].strength=(rand()%(50-1))+1;
	players[numplayers].magic =(rand()%(80-51))+51;
	players[numplayers].luck = (rand()%(100-60))+60;
	players[numplayers].dexterity=(rand()%(100-1))+1;

	return players[numplayers];
}

// Randomly assign values Human
player human(player players[], int numplayers)
{
	strcpy(players[numplayers].type, "Human");

	while ((players[numplayers].smartness + players[numplayers].strength + players[numplayers].magic+ players[numplayers].luck + players[numplayers].dexterity)== 0 ||(players[numplayers].smartness + players[numplayers].strength + players[numplayers].magic+ players[numplayers].luck + players[numplayers].dexterity)>300)
	{
		srand(time(NULL));
		players[numplayers].smartness =(rand()%(100-1))+1;
		players[numplayers].strength=(rand()%(100-1))+1;
		players[numplayers].magic =(rand()%(100-1))+1;
		players[numplayers].luck=(rand()%(100-1))+1;
		players[numplayers].dexterity=(rand()%(100-1))+1;
	}
	return players[numplayers];
}

// Randomly assign values Ogre
player ogre(player players[], int numplayers)
{
	srand(time(NULL));
	strcpy(players[numplayers].type, "Ogre");
	players[numplayers].smartness =(rand()%(20-1))+1;
	players[numplayers].strength=(rand()%(100-80))+80;
	players[numplayers].magic = 0;
	players[numplayers].luck=(rand()%(100-1))+1;
	players[numplayers].dexterity=(rand()%(100-80))+80;

	return players[numplayers];
}

// Randomly assign values Wizard
player wizard(player players[], int numplayers)
{
	srand(time(NULL));
	strcpy(players[numplayers].type, "Wizard");
	players[numplayers].smartness =(rand()%(100-90))+90;
	players[numplayers].strength=(rand()%(20-1))+1;
	players[numplayers].magic = (rand()%(100-80))+80;
	players[numplayers].luck=(rand()%(100-50))+50;
	players[numplayers].dexterity=(rand()%(100-1))+1;

	return players[numplayers];
}
// Prints values
void showvalues(player players[], int numplayers)
{
	printf("Player %d %s\n", numplayers, players[numplayers].name);
	printf("Smartness = %d\n",players[numplayers].smartness);
	printf("Strength = %d\n",players[numplayers].strength);
	printf("Magic = %d\n",players[numplayers].magic);
	printf("Luck = %d\n",players[numplayers].luck);
	printf("Dexterity = %d\n",players[numplayers].dexterity);
}
player nearattack (player players[], int numplayers, int input)
{
	int attacker, attacked;
	attacker=numplayers;
	printf("Select a Player to attack");
	scanf("%d", &attacked);
	if (attacked==attacker)
	{
		printf("You can't attack your self, please select another player");
		scanf("%d", &attacked);
	}
	else if (attacked >= input)
	{
		printf("Input is invalid, Please input another number 1");
		scanf ("%d", &attacked);
	}
	else{
		if (players[attacked].strength <= 70 && players[attacked].life >0 )
			{
				players[attacked].life= players[attacked].life -  (0.5 * players[attacked].strength);
			}
		else
			{
				if(players[attacker].life >0)
				{
					players[attacker].life= players[attacked].life -  (0.3 * players[attacked].strength);
				}
			}
		printf("Player %d  attacks Player %d \n", attacker, attacked);
		printf("Player %d  life points are  now %d \n", attacker, players[attacker].life);
		printf("Player %d  life points are  now %d \n", attacked, players[attacked].life);
		}
		return players[attacker],players[attacked];
}

void SlotAssign(int numplayers, int SizeofSlots, player players[], slot slots[])
{
	int i,j;
	srand(time(NULL));
	for(i=0;i<SizeofSlots;i++)//assigns players to slots
		{
			j=(rand()%(SizeofSlots-1)+1);
			players[i].position = j;

		}

}


player distantattack (player players[], int numplayers, int input)
{
	int attacker, attacked;
	attacker=numplayers;
	printf("Select a Player to attack");
	scanf("%d", &attacked);
	if (attacked==attacker)
	{
		printf("You can't attack your self, please select another player");
		scanf("%d", &attacked);
	}
	else if (attacked >= input)
	{
		printf("Input is invalid, Please input another number 1");
		scanf ("%d", &attacked);
	}
	else{
		if (players[attacked].dexterity >= players[attacker].dexterity )
			{
				printf("No impact player %d got away", attacked);
			}
		else
			{
				if(players[attacker].dexterity >players[attacked].dexterity)
				{
					players[attacked].life= players[attacked].life -  (0.3 * players[attacked].strength);
					printf("Player %d  attacks Player %d \n", attacker, attacked);
					printf("Player %d  life points are  now %d \n", attacker, players[attacker].life);
					printf("Player %d  life points are  now %d \n", attacked, players[attacked].life);
				}
			}

		}
		return players[attacker],players[attacked];
}

player magicattack (player players[], int numplayers, int input)
{

	int attacker, attacked;
	attacker=numplayers;
	printf("Select a Player to attack");
	scanf("%d", &attacked);
	if (attacked==attacker)
	{
		printf("You can't attack your self, please select another player");
		scanf("%d", &attacked);
	}
	else if (attacked >= input)
	{
		printf("Input is invalid, Please input another number 1");
		scanf ("%d", &attacked);
	}
	else{
		if ((players[attacker].smartness + players[attacker].magic) > 150)
			{
				players[attacked].life= players[attacked].life -  ((0.5 * players[attacker].magic)+(0.2 * players[attacker].smartness)) ;
			printf("Player %d  attacks Player %d \n", attacker, attacked);
		printf("Player %d  life points are  now %d \n", attacker, players[attacker].life);
		printf("Player %d  life points are  now %d \n", attacked, players[attacked].life);
			}
		else
			{
			printf("No impact, player %d got away", attacked);

			}

		}
		return players[attacker],players[attacked];
}
