/* -----------------------------------------------------------------------
randomtestcard1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o $(CFLAGS)
	./randomtestcard1 &> randomtestcard1.out
	gcov -abcfu dominion.c >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out
* -----------------------------------------------------------------------
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

struct gameState * resetGame(int k[], int seed, int players) {
	struct gameState * g;
	//create/reset a game
	g = malloc(sizeof(struct gameState) * 1);

	//init game
	initializeGame(players, k, seed, g);
	//create a copy of the game
	return g;
}
#define NUMPLAYERS 2
#define PLAYERONE 0
int main() {
	struct gameState * testG;
	//revised kingdom to include steward
	int kingdom[10] = { adventurer, gardens, embargo, village, minion, steward, cutpurse,
		sea_hag, tribute, smithy };
	int seed = 1000;
	int i;
	int currentDeck;
	int previousHand;
	int previousDeck;
	int currentHand;
	srand(time(NULL));
	printf("Testing smithy card\n\n");

	for (i = 0; i < 20; i++) {
		testG = resetGame(kingdom, seed, NUMPLAYERS);

		testG->handCount[PLAYERONE] = rand() % MAX_HAND;
		testG->deckCount[PLAYERONE] = rand() % MAX_DECK;
		
		printf("\nTesting Hand Count\n");
		previousDeck = testG->deckCount[PLAYERONE];
		previousHand = testG->handCount[PLAYERONE];

		smithyEffect(PLAYERONE, testG, 0);

		currentDeck = testG->deckCount[PLAYERONE];
		currentHand = testG->handCount[PLAYERONE];

		printf("Expected: %d, Actual: %d\n", previousHand + 2, currentHand);

		if (currentHand == previousHand + 2) {
			printf("Correct handcount\n");
		}
		else {
			printf("Incorrect hand count");
		}

		printf("Expected: %d, Actual: %d\n", previousDeck - 3, currentDeck);
		if (currentDeck == previousDeck - 3) {
			printf("Correct Deck count\n");
		}
		else {
			printf("Incorrect deck count\n");
		}

	}
	printf("\n\n Testing Smithy is done \n\n");
	free(testG);
}