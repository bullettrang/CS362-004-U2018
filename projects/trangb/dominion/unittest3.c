/* -----------------------------------------------------------------------
*
* Include the following lines in  makefile:
*
* unittest3: unittest3.c dominion.o rngs.o
*      gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
* -----------------------------------------------------------------------
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>



//testing score for
#define NOISY_TEST 1
#define VICTORYCARDS 6
#define MAXPILES 3
#define CURSEVAL -1
#define STARTINGSCORE 2
//#define MAX_HAND 500
//#define MAX_DECK 500

//
//int hand[MAX_PLAYERS][MAX_HAND];
//int handCount[MAX_PLAYERS];
//int deck[MAX_PLAYERS][MAX_DECK];
//int deckCount[MAX_PLAYERS];
//int discard[MAX_PLAYERS][MAX_DECK];
//int discardCount[MAX_PLAYERS];


//int numHandCards(struct gameState *state) {
//	return state->handCount[whoseTurn(state)];
//}

struct gameState * resetGame(int k[], int seed) {
	struct gameState * g;
	//create/reset a game
	g = malloc(sizeof(struct gameState) *1);
	
	//init game
	initializeGame(2, k, seed, g);
	//create a copy of the game
	

	return g;

}
#define STARTINGNUM 5
#define NOISY_TEST 1
int main() {

	struct gameState * testG;
	struct gameState G;
	struct gameState tg;
	int kingdom[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };

	int testSuite[9] = { council_room ,feast, mine, remodel,smithy,village,great_hall,steward };
	//curse, estate, duchy,province, great hall, gardens
	//int testSuite[VICTORYCARDS] = { 0,1,2,3,10,16 };
	
	int  i, k;

	int seed = 1000;
	int curses[MAX_HAND];
	int estates[MAX_HAND];
	int duchies[MAX_HAND];
	int provinces[MAX_HAND];
	int great_halls[MAX_HAND];
	int gardenss[MAX_HAND];
	int numCards;



	printf("TESTING numHandCards():\n\n");


	for (i = 0; i < 5; i++) {
		numCards = i + 1;
		testG = resetGame(kingdom, seed);
		for (k = 0; k < numCards; k++) {
			drawCard(0, testG);
		}
		
#if NOISY_TEST
		printf("Actual Cards: %d, Expected Cards: %d\n ", numHandCards(testG),numCards + STARTINGNUM);
#endif
		assert(numHandCards(testG) == numCards + STARTINGNUM);
		free(testG);
	}

	//test base case
	testG = resetGame(kingdom, seed);
#if NOISY_TEST
	printf("Testing base case\n");
	printf("Actual Cards: %d, Expected Cards: %d\n ", numHandCards(testG), STARTINGNUM);
#endif

	assert(numHandCards(testG) == 5);


		
	
}