#include <Stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"





int main(void)
{
	setbuf(stdout, NULL);
	srand(time(NULL));
	int row, column, boardSize;
	boardSize = 7;
	row = 7;
	column = 7;

		struct slot* currSlot = NULL;
		struct slot *foundSlots;
		bool explored[BOARD_SIZE][BOARD_SIZE];


		int count =0;

		//pointer to slot (0,0)
		struct slot *upLeft;

		//pointer to slot (0,boardSize -1)
		struct slot *upRight;

		//pointer to slot (boardSize - 1, 0)
		struct slot *downLeft;

		//pointer to slot (boardSize - 1, boardSize -1)
		struct slot *downRight;
		
		//Creates the board
		createBoard(boardSize,&upLeft, &upRight, &downLeft, &downRight);


	int input, numplayers, inputtype, game= 1;
	int j, i;
	int boardsize = 7;
	

	// Asks the user to input a set of players (max 6).
	printf("Please input number of players 2-6\n");
	scanf ("%d", &input);
	while (input <2 || input > 6)
	{
   		printf("Input is invaid, Please input  number of players 2-6\n");
   		scanf ("%d", &input);
	}

	// Asks the user to input a name.
	for (numplayers=0;numplayers >= 0 && numplayers < input; ++numplayers)
  	{
		printf("Please input name for player %d\n", numplayers);
		scanf("%s", &players[numplayers].name);
   	}

	//life points are initially set to 100.
	for (numplayers=0;numplayers >= 0 && numplayers <input; ++numplayers)
	{
		players[numplayers].life= 100;
	}
	// ** Subsequently the players are placed in a slot randomly.
	// ** Note that, differently from the previous assignment, now more than one player can be assigned to a slot.


	// For each player the user has to select a type (Elf, Human, Ogre, Wizard)
	for (numplayers=0;numplayers >= 0 && numplayers <input; ++numplayers)
 	{
		printf("Please input choose a chartcter type for player %d :/n 1 Elf/n 2 Human/n 3 Ogre/n 4 Wizard/n ", numplayers);
		scanf ("%d", &inputtype);
		while (inputtype <1 || inputtype > 4)
		{
			printf("Input is invaid, Please input number of between 1 and 4\n");
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

	printf("======BOARD======\n");
	
	printf("\n");
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
			printf("player %s is in slot (%d, %d)\n", players[i].name,players[i].positionrow,players[i].positioncolumn);//prints players positions
		}
		printf("\n");
		int counter, choice, check, attacked, attackType;
		char attackPlayer[15];
		int rowChoice, columnChoice;
		
		while(numplayers>1)
	{
		for(numplayers=0;numplayers >= 0 && numplayers < input; ++numplayers)
		{
			printf("you are in slot (%d, %d)\n", players[numplayers].positionrow,players[numplayers].positioncolumn);
			printf("\n");
			printf("enter 1 to move to an adjacent slot, 2 to attack another player, 3 to exit the game\n");
			scanf("%d", &choice);
		
			
			
				if(choice == 1)
				{
					
					
						
						if(players[numplayers].positionrow == 1 && players[numplayers].positioncolumn == 1)// if in position (1,1) you can move to these places
						{
							printf("you can move to slot (1,2) or (2,1). enter your choice in the form x,y\n");
							scanf("%d, %d", &rowChoice, &columnChoice);
							if(rowChoice == 1 && columnChoice == 2)
							{
								players[numplayers].positionrow = 1;
								players[numplayers].positioncolumn = 2;
								
								check = 1;
							}
							else if(rowChoice == 2 && columnChoice == 1)
							{
								players[numplayers].positionrow = 2;
								players[numplayers].positioncolumn = 1;
								
								check = 1;
							}
							else
							{
								printf("invalid choice\n");
								check = 0;
							}
						}
						else if(players[numplayers].positionrow == 1 && players[numplayers].positioncolumn == 7)//if in position (1,7), you can move to these places
						{
							printf("you can move to slot (1,6) or (2,7).enter your choice in the form x,y\n");
							scanf("%d, %d", &rowChoice, &columnChoice);
							if(rowChoice == 1 && columnChoice == 6)
							{
								players[numplayers].positionrow = 1;
								players[numplayers].positioncolumn = 6;
								
								check = 1;
							}
							else if(rowChoice == 2 && columnChoice == 7)
							{
								players[numplayers].positionrow = 2;
								players[numplayers].positioncolumn = 7;
								
								check = 1;
							}
							else
							{
								printf("invalid choice\n");
								check = 0;
							}
						}
						else if(players[numplayers].positionrow == 7 && players[numplayers].positioncolumn == 7)//if in position (7,7), you can move to these places
						{
							printf("you can moce to slot (7, 6) or (6, 7). enter your choice in the form x,y\n");
							scanf("%d, %d", &rowChoice, &columnChoice);
							if(rowChoice == 7 && columnChoice == 6)
							{
								players[numplayers].positionrow = 7;
								players[numplayers].positioncolumn = 6;
								
								check = 1;
							}
							else if(rowChoice == 6 && columnChoice == 7)
							{
								players[numplayers].positionrow = 6;
								players[numplayers].positioncolumn = 7;
								
								check = 1;
							}
							else
							{
								printf("invalid choice\n");
								check = 0;
							}
						}
						else if(players[numplayers].positionrow == 7 && players[numplayers].positioncolumn == 1)//if in position (7,7), you can move to these places
						{
							printf("you can move to slot (6, 1) or (7, 2).enter your choice in the form x, y\n");
							scanf("%d, %d", &rowChoice, &columnChoice);
							
							if(rowChoice == 6 && columnChoice == 1)
							{
								players[numplayers].positionrow = 6;
								players[numplayers].positioncolumn = 1;
								
								check = 1;
							}
							else if(rowChoice == 7 && columnChoice == 2)
							{
								players[numplayers].positionrow = 7;
								players[numplayers].positioncolumn = 2;
								
								check = 1;
							}
							else
							{
								printf("invalid choice\n");
								check = 0;
							}
						}
						else//else it tells you which way up,down,left and right you can move
						{
							printf("you can move to slot (%d, %d), (%d, %d), (%d, %d) or (%d, %d).enter your choice in the form x, y\n",players[numplayers].positionrow + 1,players[numplayers].positioncolumn, players[numplayers].positionrow
							,players[numplayers].positioncolumn + 1,players[numplayers].positionrow - 1,players[numplayers].positioncolumn, players[numplayers].positionrow, players[numplayers].positioncolumn - 1);
							scanf("%d, %d", &rowChoice, &columnChoice);
							if(rowChoice == players[numplayers].positionrow + 1 && columnChoice == players[numplayers].positioncolumn)
							{
								players[numplayers].positionrow =players[numplayers].positionrow + 1;
								
								check = 1;
							}
							else if(rowChoice == players[numplayers].positionrow && columnChoice == players[numplayers].positioncolumn + 1)
							{
								players[numplayers].positioncolumn = players[numplayers].positioncolumn + 1;
								
								check = 1;
							}
							else if(rowChoice == players[numplayers].positionrow - 1 && rowChoice == players[numplayers].positioncolumn)
							{
								players[numplayers].positionrow = players[numplayers].positionrow - 1;
								
								check = 1;
							}
							else if(rowChoice == players[numplayers].positionrow && columnChoice == players[numplayers].positioncolumn - 1)
							{
								players[numplayers].positioncolumn = players[numplayers].positioncolumn - 1;
								
								check = 1;
							}
							else
							{
								printf("invalid choice\n");
								check = 0;
							}
						}
					
					
					
				}
				else if(choice == 2)
				{
					
						printf("please enter the name of the player you wish to attack\n");
						scanf("%s", &attackPlayer[15]);//scans in the name of the player you wish to attack
						
						for(int bplayer=0;bplayer<numplayers;bplayer++)
						{
							if(strcmp(players[bplayer].name, attackPlayer)==0)
							{
								bplayer = attacked;//copies the player you wish to attack into attacked
								
							}
							else
							{
								printf("Player is not in game\n");
								
							}
						}
						
						
							printf("please enter the type of attack you want to use : 1 for near, 2 for distant, 3 for magic\n");
							scanf("%d", &attackType);
							if(attackType == 1)
							{
								if(nearCheck(players,numplayers,attacked)==0)//checks if they are adjacent
								{
									
									printf("Attack not permitied, player not in range\n");//if they arent adjacent
								}
								else
								{
									nearAttack(players, attacked);//calls nearAttack if they are adjacent
									
								}
							}
							else if(attackType == 2)
							{
								if(distantCheck(players,numplayers,attacked)==0)//checks if they are in range for distant attack
								{
									printf("Attack not permitied, player not in range\n");
									
								}
								else                    
								{
									distantAttack(players,numplayers,attacked);//calls distantAttack if they are in a position that can be targeted
									
								}
							}
							else if(attackType == 3)
							{
								if(players[i].smartness + players[i].magic <= 150)
								{
									
									printf("Attack not allowed, insufficient points\n");//if the players smartness and magic is less than 150 they cant perfrom the attack
									
								}
								else
								{
									magicAttack(players,numplayers,attacked);//if it is 150 or over they can perform the attack
								
								}
							}
							else
							{
								printf("Invalid choice\n");
							}
						
					
				}
				else if(choice == 3)
				{
					printf("%s has left the game\n", players[numplayers].name);
					
					for(int h = 0;h<numplayers;h++)
					{
						strcpy(players[h].name, players[h+1].name);
						strcpy(players[h].type, players[h+1].type);
						players[h].life = players[h+1].life;
						players[h].smartness = players[h+1].smartness;
						players[h].strength = players[h+1].strength;
						players[h].magic = players[h+1].magic;
						players[h].luck = players[h+1].luck;
						players[h].dexterity = players[h+1].dexterity;
						players[h].positionrow = players[h+1].positionrow;
						players[h].positioncolumn = players[h+1].positioncolumn;
					}
					numplayers--;
				}
				else
				{
					printf("Invalid choice\n");
				}
				for(int s=0;s<numplayers;s++)
				{
					printf("%s (%s, %d)\n", players[s].name,players[s].type,players[s].life);
				}
				printf("\n");
		}
		for(int t=0;t<numplayers;t++)
		{
			if(players[t].life <= 0)
			{
				printf("Game over for player %s", players[t].name);
				for(int r=t;r<numplayers;r++)
				{

					strcpy(players[r].name, players[r+1].name);
					strcpy(players[r].type, players[r+1].type);
					players[r].life = players[r+1].life;
					players[r].smartness = players[r+1].smartness;
					players[r].strength = players[r+1].strength;
					players[r].magic = players[r+1].magic;
					players[r].luck = players[r+1].luck;
					players[r].dexterity = players[r+1].dexterity;
					players[r].positionrow = players[r+1].positionrow;
					players[r].positioncolumn = players[r+1].positioncolumn;
				}
				numplayers--;
			}
		}
	}
if(numplayers == 1)
{
	printf("Game over.\n%s is the winner!!", players[0].name);
	
}
else if(numplayers == 0)
{
	printf("Game over.\n");
}
	return 0;
}

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

