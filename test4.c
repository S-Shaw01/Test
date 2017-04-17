#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"




void createBoard(int boardSize, struct slot **upLeft, struct slot **upRight, struct slot **downLeft, struct slot **downRight){

	int i,j;
	struct slot ** board = malloc(boardSize * sizeof(struct slot *));


	for(i =0; i< boardSize; i++){
		
		
		board[i] = malloc(boardSize * sizeof(struct slot));

		
		for(j=0;j < boardSize; j++){
			board[i][j].row = i;
			board[i][j].column = j;
		}
	}

	
	for(i =1; i< boardSize-1; i++){
		for(j=1;j < boardSize-1; j++){
			board[i][j].up = &board[i-1][j];
			board[i][j].right = &board[i][j+1];
			board[i][j].down = &board[i+1][j];
			board[i][j].left = &board[i][j-1];
		}
	}

	
	
	for(j = 1; j < boardSize -1; j++){
		
		board[0][j].right = &board[0][j+1];
		board[0][j].left = &board[0][j-1];
		board[0][j].down = &board[1][j];
		board[0][j].up = NULL;

		
		board[boardSize - 1][j].right = &board[boardSize - 1][j+1];
		board[boardSize -1][j].left = &board[boardSize - 1][j-1];
		board[boardSize - 1][j].up = &board[boardSize - 2][j];
		board[boardSize - 1][j].down = NULL;
	}

	
	for(i = 1; i < boardSize -1; i++){
		
		
		board[i][0].right = &board[i][1];
		board[i][0].up = &board[i-1][0];
		board[i][0].down = &board[i+1][0];
		board[i][0].left = NULL;

		board[i][boardSize-1].left = &board[i][boardSize-2];
		board[i][boardSize -1].up = &board[i -1][boardSize-1];
		board[i][boardSize -1].down = &board[i+1][boardSize -1];
		board[i][boardSize -1].right = NULL;
	}


		board[0][0].right = &board[0][1];
		board[0][0].down = &board[1][0];
		board[0][boardSize-1].left = &board[0][boardSize-2];
		board[0][boardSize -1].down = &board[1][boardSize -1];
		board[boardSize -1][0].right = &board[boardSize -1][1];
		board[boardSize -1][0].up = &board[boardSize -2][0];
		board[boardSize - 1][boardSize-1].up = &board[boardSize-2][boardSize-1];
		board[boardSize - 1][boardSize -1].left = &board[boardSize -1][boardSize -2];

	
	*upLeft = &board[0][0];
	*upRight = &board[0][boardSize -1];
	*downLeft = &board[boardSize -1][0];
	*downRight = &board[boardSize -1][boardSize -1];
	
	for(i=0;i<boardSize;i++)
	{
		for(int d=0;d<boardSize;d++)
		{
		j = 1+rand()%3;//chooses random number between 1=3
		if(j == 1)
		{
			strcpy(board[i][d].Type, "Ground");// if 1, type = ground
		}
		else if(j == 2)
		{
			strcpy(board[i][d].Type, "City");	//if 2, type = city
		}
		else
		{
			strcpy(board[i][d].Type, "Hill");//if 3, type = hill
		}
		}
	}

}

void slotType(struct slot **board, player players[], int numplayers)
{
	int do_nothing = 0;
	if(strcmp(board[players[numplayers].positionrow][players[numplayers].positioncolumn].Type, "Hill")==0)
	{
		if(players[numplayers].dexterity < 50)
		{
			players[numplayers].strength = players[numplayers].strength - 10;
		}
		else if(players[numplayers].dexterity >= 60)
		{
			players[numplayers].strength = players[numplayers].strength + 10;
		}
	}
	else if(strcmp(board[players[numplayers].positionrow][players[numplayers].positioncolumn].Type, "City")==0)
	{
		if(players[numplayers].smartness > 60)
		{
			players[numplayers].magic = players[numplayers].magic + 10;
		}
		else if(players[numplayers].smartness <=50)
		{
			players[numplayers].dexterity = players[numplayers].dexterity - 10;
		}
	}
	else
	{
		do_nothing++;
	}
}