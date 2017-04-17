#ifndef OPERATIONS_H_
#define OPERATIONS_H_




#define BOARD_SIZE 7
#define REQ_DISTANCE 3


/*
 * Definition of boolean types
 * This avoids using <stdbool.h>
 */
typedef int bool;
enum { false, true };

typedef struct player
{
	char name[20];
	char type[20];
	int life;
	int smartness;
	int strength;
	int magic;
	int luck;
	int dexterity;
	int stillalive;
	int positionrow;
	int positioncolumn;
}player;
player players[6];
/*
 * The slot template
 */
struct slot{
	int row;
	int column;
    bool explored;
	char Type[50];
	struct slot *left;
	struct slot *right;
	struct slot *up;
	struct slot *down;
}slot;

/*
 * FUNCTIONS PROTOTYPES
 */

/*
 * Functions getBoardSize and getDesiredElement
 * manage the interaction with the users
 */

//Asks the user to provide as input the size of the board
//Returns the size of the board
int getBoardSize();

//Asks the user to insert the row and the column of the element
//she wants to find given a board of size equal to maxsize
void getDesiredElement(int maxsize, int * row, int * col);

/*
 * Functions createBoard and reachDesiredElement
 * manage the creation and manipulation of the board
 */
/*
 * This function creates the board
 * Parameters:
 * 	boardSize: the size of the board
 * 	upLeft: pointer of pointer to slot at position (0, 0)
 * 	upRight: pointer of pointer to slot at position (0, size -1)
 * 	downLeft: pointer of pointer to slot at position (size -1, 0)
 * 	upLeft: pointer of pointer to slot at position (size - 1, size -1)
 */
void createBoard(int boardSize, struct slot **upLeft, struct slot **upRight, struct slot **downLeft, struct slot **downRight);

/*
 * This function traverses the board to find a slot at a predefined
 * position (row, column)
 * Parameters:
 * 	row: the row in which the desired slot is located
 * 	column: the column in which the desired slot is located
 * 	initialSlot: the slot from which the slot search should start
 */
struct slot *  reachDesiredElement(int row, int column, struct slot * initialSlot);


/*
 * The recursive function that traverses the board to find the slots at a predefined
 * distance from the current slot and place them in foundSlots.
 * Parameters:
 * 	reqDist: the required distance from the starting slot
 * 	currDist: the distance of the current slot from the starting slot
 * 	currSlot: a pointer to the current slot that is traversed
 * 	foundSlots: the array of slots that are at a required distance from the starting slot
 * 	count: pointer to an integer representing the number of slots that are found to be at a required distance from the starting slot
 * 	explored: matrix indicating for each slot at row x and column y has been traversed (true) or not (false)
 */
void findSlots(int reqDist, int currDist,  struct slot * currSlot, struct slot * foundSlots, int * count,  bool explored[7][7]);
player elf( player players[], int numplayers);
player human(player players[], int numplayers);
player ogre(player players[], int numplayers);
player wizard(player players[], int numplayers);
void showvalues(player players[], int numplayers);
player attack (player players[], int numplayers, int input);
void slotType(struct slot **board, player players[], int numplayers);
int nearCheck(player players[],int numplayers, int attacked);
int distantCheck(player players[], int numplayers, int attacked);
void magicAttack(player players[],int numplayers, int attacked);
void distantAttack(player players[],int numplayers, int attacked);
void nearAttack(player players[], int attacked);
#endif
