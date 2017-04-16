*
 * main.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "crossfireOperations.h"
#include <time.h>
#include "crossfireOperations.h"


int main(){

	setbuf(stdout,NULL);
	int row, column;
	struct slot* currSlot = NULL;
	struct slot *foundSlots;
	bool explored[BOARD_SIZE][BOARD_SIZE];
	int count =0;
	int input, numplayers, numofslots, inputtype, game= 1;
	srand(time(NULL));
	int i=0,j;


	//pointer to slot (0,0)
	struct slot *upLeft;

	//pointer to slot (0,boardSize -1)
	struct slot *upRight;

	//pointer to slot (boardSize - 1, 0)
	struct slot *downLeft;

	//pointer to slot (boardSize - 1, boardSize -1)
	struct slot *downRight;


	//Creates the board
	createBoard(BOARD_SIZE,&upLeft, &upRight, &downLeft, &downRight);

	/*	Asks the user the row and the column of the slot
		s/he wants to retrieve from the board.
		Note that the user needs to know the size of the board to input
		the correct row and column of the slot s/he wants to retrieve */
	getDesiredElement(BOARD_SIZE, &row,&column);

	//Finds the slot


	/*If the the required slot is closer to the down-right
	 * corner of the board the search starts from downRight,
	 * which points to slot at position (boardSize-1, boarSize -1)*/
	if(row >= BOARD_SIZE/2){
		if(column >= BOARD_SIZE/2)
			currSlot = reachDesiredElement(row,column,downRight);
		else
		/*If the the required slot is closer to the down-left
		* corner of the board the search starts from downLeft,
		* which points to slot at position (boardSize-1, 0)*/
			currSlot = reachDesiredElement(row,column,downLeft);
	} else {
		/*If the the required slot is closer to the up-right
		* corner of the board the search starts from upRight,
		* which points to slot at position (0, boarSize -1)*/
		if(column >= BOARD_SIZE/2)
			currSlot = reachDesiredElement(row,column, upRight);
		/*If the the required slot is closer to the up-left
		* corner of the board the search starts from upLeft,
		* which points to slot at position (0, 0)*/
		else currSlot = reachDesiredElement(row,column,upLeft);
	}

	for(int i=0; i<BOARD_SIZE; i++){
		for(int j=0; j<BOARD_SIZE;j++){
			explored[i][j] = false;
		}
	}

	foundSlots = malloc(BOARD_SIZE * BOARD_SIZE * sizeof(struct slot ));
	printf("\n\nFunction findSlotsinvoked:\n");

	if(currSlot!= NULL){
		//invokes function findSlots. The required distance is a constant
		//However you can reuse this function providing as input any arbitrary distance
		findSlots(REQ_DISTANCE, 0, currSlot, foundSlots, &count, explored);
		for(int i=0; i<count; i++){
			printf("(%d, %d)-> ",foundSlots[i].row, foundSlots[i].column);
		}
	}
// Asks the user to input a set of players (max 6).
		printf("Please input  number of players 2-6");
		scanf ("%d", &input);
		while (input <2 || input > 6)
			{
		   		printf("Input is invaid, Please input  number of players 2-6");
		   		scanf ("%d", &input);
			}

		// Asks the user to input a name.
				for (numplayers=0;numplayers >= 0 && numplayers < input; ++numplayers)
			  	{
					printf("Please input name for player %d", numplayers);
					scanf("%s", &players[numplayers].name);
			   	}

		//life points are initially set to 100.
				for (numplayers=0;numplayers >= 0 && numplayers <input; ++numplayers)
				{
					players[numplayers].life= 100;
				}

				//??SlotAssign(numplayers,SizeofSlots,players,slots);//assign players to slots
					for(i=0;i<numplayers;i++)
					{//prints the slot each player is in
					int k,n;
					for(i=0;i<numplayers;i++)
					{
						k=rand()%boardsize;//assigns players to a random slot
						n=rand()%boardsize;

						players[i].positionrow = k;
						players[i].positioncolumn = n;
					}
					for(i=0;i<numplayers;i++)
					{
						printf("player %s is in slot (%d, %d)\n", players[i].name,players[i].positionrow,players[i].positioncolumn);
					}
					
					printf("\n");
					printf("\n-----Begin-----\n");
					
				// For each player the user has to select a type (Elf, Human, Ogre, Wizard)
					for (numplayers=0;numplayers >= 0 && numplayers <input; ++numplayers)
				 	{
						printf("Please input choose a character type for player %d :/n 1 Elf/n 2 Human/n 3 Ogre/n 4 Wizard/n ", numplayers);
						scanf ("%d", &inputtype);
						while (inputtype <1 || inputtype > 4)
						{
							printf("Input is invaid, Please input number of between 1 and 4");
							scanf ("%d", &input);
						}
						// Switch calls functions to randomly assign values and print value
						switch (inputtype)
						{
							case 1:
							elf(players, numplayers);
							showvalues(players,numplayers);
							break;

							case 2:
							human(players, numplayers);
							showvalues(players, numplayers);
							break;

							case 3:
							ogre(players, numplayers);
							showvalues(players,numplayers);
							break;

							case 4:
							wizard(players,numplayers);
							showvalues(players, numplayers);
							break;
						}
					}
	int choice,choice2;
	while ( game != input)
	{
		for(i=0;i<numplayers;i++)
		{
			if (players[numplayers].life >0)
			{
				printf("<%s>(<%s>, <%d>", players[numplayers].name,players[numplayers].type,players[numplayers].life);//moves players
				printf("enter 1 to move, 2 to attack, 3 to quit the game");
				scanf("%d", &choice);

				if(choice == 1)
				{
					printf("choice 1 to move forward\nChoice 2 to move backwards\n, Choice 3 to move up \n, Choice 4 to move down\n");
					scanf("%d",&choice2);

					if(choice2 == 1)
					{
						// needs added
					}
					if(choice2 == 2)
					{
					// needs added
					}

					if(choice2 == 3)
						{
						// Needs added
						}
					if(choice2 == 4)
						{
						// needs added
						}


					if (strcmp(slots[i].TypeofSlot, "Hill")==0)//if player is on this slot, change stats
					{
						if(players[i].dexterity <  50)
						{
							players[i].strength = (players[i].strength - 10);
							if(players[i].strength < 0)
							{
								players[i].strength = 0;//if stat falls below 0,set to 0
							}
						}

						if(players[i].dexterity >= 60)
						{
							players[i].strength = (players[i].strength + 10);
							if(players[i].strength>100)
							{
								players[i].strength = 100;//if strenght is over 100,set to 100
							}
						}
					}

					if(strcmp(slots[i].TypeofSlot, "City")==0)//if player is on this type, change stats
					{
						if(players[i].smartness > 60)
						{
							players[i].magic = (players[i].magic + 10);
							if(players[i].magic > 100)
							{
								players[i].magic = 100;
							}
						}
						if(players[i].smartness <= 50)
						{
							players[i].dexterity = players[i].dexterity - 10;
							if(players[i].dexterity<0)
							{
								players[i].dexterity=0;//if dex falls below 0,set to 0
							}
						}
					}
		//prints each players new location ** needs changed
		//printf("new location of %s = %d\n", players[i].name, players[i]);


				}
				if(choice == 2)
				{
					printf("choice 1 for a near attack \n Choice 2 for a distant attack \n, Choice 3 for a magic attack \n");

					if(choice2 == 1)
					{
					nearattack (players, numplayers, input);
					}
					if(choice2 == 2)
					{
						distantattack (players, numplayers, input);
					}
					if (choice2 == 3)
					{
						magicattack (players, numplayers, input);
					}
				}
				if(choice == 3)
				{
					players[numplayers].life = 0;
				}

			}
			else if (players[numplayers].stillalive ==0)
			{
				printf("player %d is out of the game", numplayers);
				players[numplayers].stillalive = 1;
				++game;
			}
		}
	}

			// Prints the winner and losers
		for (numplayers=0;numplayers >= 0 && numplayers < input; ++numplayers)
		{
			if (players[numplayers].stillalive ==0)
			{
				printf("player %d is the winner", numplayers);
			}
			if (players[numplayers].stillalive ==1)
			{
				printf("player %d lost", numplayers);
			}
		}

	return 0;
}
