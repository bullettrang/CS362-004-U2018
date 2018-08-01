/* -----------------------------------------------------------------------
*
* Include the following lines in  makefile:
*
* unittest2: unittest2.c dominion.o rngs.o
*      gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
* -----------------------------------------------------------------------
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


//test reveals deck size difference


#define NOISY_TEST 1
#define PLAYERONE 0

//2-player card totals
#define VICTORYSUPPLY 8
#define COPPERSUPPLY 46
#define SILVERSUPPLY 40
#define GREATHALLSUPPLY 8
#define GARDENSSUPPLY 8
int main() {
	int i;
	int j;
	int k;
	int l;
	int seed = 1000;

	int originalSupply;
	int originalDeck;
	struct gameState G, testG;
	//test sample of cards
	int kingdom[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };



	//  ---------- TEST 1 ----------
	//council room, feast, mine, remodel, smithy, village, great hall, steward,adventurer




	
	//test all 3 toFlags cards
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 10; j++) {
			//clear the game

			memset(&G, 23, sizeof(struct gameState));

			//init game
			initializeGame(2, kingdom, seed, &G);

			//create a copy of the game
			memcpy(&testG, &G, sizeof(struct gameState));
			originalSupply = testG.supplyCount[kingdom[j]];
			originalDeck = testG.deckCount[PLAYERONE];
			//printf("TESTING gainCard()\n\n");
			if (i == 1) {
				//printf("original deck size is %d \n", originalDeck);
			}
			//printf("Original supply pile of card %d : %d\n", kingdom[j], originalSupply);
			for (k = 0; k < 10 ; k++) {
				int newSupply;
				//how many jth kingdom cards do we get to the i pile? k times
				for (l = 0; l < k+1; l++) {
					gainCard(kingdom[j], &testG, i, PLAYERONE);
				}
				newSupply = testG.supplyCount[kingdom[j]];
				//printf(" \nnew supply pile of card %d is : %d \n", kingdom[j], newSupply);
				int displacedCards;
				if (i == 0) {
					displacedCards = testG.discardCount[PLAYERONE];
					//printf("discard pile is %d\n", displacedCards);
				}
				else if (i == 1) {
					int tempDeck;
					displacedCards = testG.deckCount[PLAYERONE];
					//subtract 5 cards for the starting deck size
					tempDeck = displacedCards - 5;
					displacedCards = tempDeck;
					//printf("deck pile is %d\n", displacedCards);
				}
				else {
					int tempHand;
					displacedCards = testG.handCount[PLAYERONE];
					tempHand = displacedCards - 5;
					displacedCards = tempHand;
					//printf("hand pile is %d\n", displacedCards);
				}
				int testSupply;

				testSupply = displacedCards + newSupply;
#if (NOISY_TEST ==1)
				//printf("\n\nTest Supply: %d   Expected Supply: %d \n\n", testSupply, originalSupply);
#endif
				assert(testSupply == originalSupply);
			}
		}
	}

}