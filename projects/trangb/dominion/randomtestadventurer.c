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
#define PLAYERONE 0
#define MINPLAYERS 2
#define HAND 2
#define MAXPLAYERS 4
int main() {
	struct gameState * testG;
	//revised kingdom to include steward
	int kingdom[10] = { adventurer, gardens, embargo, village, minion, steward, cutpurse,
		sea_hag, tribute, smithy };
	int seed = 1000;
	int i;
	int previoushand;
	int totalplayers;
	srand(time(NULL));
	int temphand[MAX_HAND];
	printf("\nTesting Adventurer\n");

	for (i = 0; i < 20; i++) {
		totalplayers = rand() % MAXPLAYERS + MINPLAYERS;
		testG = resetGame(kingdom, seed, totalplayers);
		previoushand = testG->handCount[PLAYERONE];
		printf("Checking hand count\n");
		testG->deckCount[PLAYERONE] = rand() % 15;
		gainCard(adventurer, testG, HAND, PLAYERONE);
		adventurerEffect(0, PLAYERONE, testG, temphand);

		printf("Expected: %d, Actual: %d\n", previoushand + 2, testG->handCount[PLAYERONE]);

		if (previoushand + 2 == testG->handCount[PLAYERONE]) {
			printf("hand count correct\n");
		}
		else {
			printf("hand count incorrect\n");
		}
		free(testG);
	}
	printf("\nTEST COMPLETED\n");
}