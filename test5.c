#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "header.h"

int nearCheck(player players[],int numplayers, int attacked)
{
	if((players[attacked].positionrow - players[numplayers].positionrow == 1 || players[attacked].positionrow - players[numplayers].positionrow == 0 || players[attacked].positionrow - players[numplayers].positionrow == -1)&&
	(players[attacked].positioncolumn - players[numplayers].positioncolumn == 1 || players[attacked].positioncolumn - players[numplayers].positioncolumn == 0 || players[attacked].positioncolumn - players[numplayers].positioncolumn == -1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int distantCheck(player players[], int numplayers, int attacked)
{
	int check, distance;
	if(nearCheck(players, numplayers, attacked)==1)
	{
		check = 0;
	}
	
	distance = abs(players[attacked].positionrow - players[numplayers].positionrow) + abs(players[attacked].positioncolumn - players[numplayers].positioncolumn);
	if(distance >= 5)
	{
		check = 0;
	}
	else
	{
		check = 1;
	}
	return check;
}
void nearAttack(player players[], int attacked)
{
	if(players[attacked].strength <= 70)
	{
		players[attacked].life -= (players[attacked].strength)*0.5;
	}
	else if(players[attacked].strength > 70)
	{
		players[attacked].life -= (players[attacked].strength)*0.3;
	}
}
void distantAttack(player players[], int numplayers, int attacked)
{
	if(players[numplayers].dexterity > players[attacked].dexterity)
	{
		players[numplayers].life -= (players[attacked].strength)*0.3;
	}
}
void magicAttack(player players[],int numplayers, int attacked)
{
	players[attacked].life = (players[attacked].magic)*0.5 + (players[attacked].smartness)*0.2;
}