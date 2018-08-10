/* -----------------------------------------------------------------------
* 
* Include the following lines in  makefile:
*
* unittest1: unittest1.c dominion.o rngs.o
*      gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
* -----------------------------------------------------------------------
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1
#define PLAYERONE 0
#define STARTINGCOST 6
int main() {
	int i;
	int j;

	int handCount;
	struct gameState G, testG;
	int numPlayers = 2;
	int seed = 1000;
	int maxHandCount = 5;
	int pt;					//current player to check
	int bonus = 0;

	//test sample of cards
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };
	int kCosts[10] = {
	6,4,2,3,5,5,4,4,5,4
	};
	//test sample of costs
	
	// does the cost function work correctly?
	//requirements
	//does it display p1's cost of hand cards correctly?
	//does it display p2's cost of hand cards correctly?
	//does it display p1's cost of deck correctly?
	//does it display p2's cost of deck correctly?


	//start the game
	initializeGame(numPlayers, k, seed, &G);

	//int firstPlayer = whoseTurn(&G);
	int totalHandCost;
	
	int pOneHandCost;
	// ----------- TEST 1: check the cost of each players hand
	//since each player starts with 3 coppers and 2 estates, this should be zero for both players

	//create a copy of the game
	memcpy(&testG, &G, sizeof(struct gameState));
	printf("CURRENTLY TESTING getCost(cardNumber)\n\n");
	printf("Test 1: Starting game, both players' starting hands should have a total card cost of 0-6 \n\n");
	//cycle through each player
	for (pt = 0; pt < numPlayers; pt++) {
		//set totalHandCost to 0 for each player
		totalHandCost = 0;
		printf("PLAYER %d cards: ", pt + 1);
		//cycle through each player's hand
		for (i = 0; i < 5; i++) {
			printf("%d ", testG.hand[pt][i]);
			totalHandCost += getCost(testG.hand[pt][i]);
		}
#if(NOISY_TEST==1)
		printf(" player %d Actual Hand Cost : %d ,  player %d expected hand cost : between 0 & 6 \n", pt + 1, totalHandCost, pt + 1);
#endif
		assert(totalHandCost >= 0 && totalHandCost <7);
		if (pt == 0) {
			pOneHandCost = totalHandCost;
		}
	}



		int playerOneDeckCost = 0;
	for (i = 0; i < testG.deckCount[PLAYERONE]; i++) {
		playerOneDeckCost += getCost(testG.deck[PLAYERONE][i]);
	}

#if(NOISY_TEST==1)
	printf(" player %d Actual deck Cost : %d ,  player %d expected deck cost : between 0 & 6 \n", 1, playerOneDeckCost, 1);
#endif
	assert(playerOneDeckCost >= 0 && playerOneDeckCost <7);

#if(NOISY_TEST==1)
	printf("Hand + deck cost of player 1: %d \n", playerOneDeckCost + pOneHandCost);
#endif
		int p1StartingCost = playerOneDeckCost + pOneHandCost;
		assert(p1StartingCost == STARTINGCOST);
	printf("Test 2: random hand ,checking both players total cost of hands after drawing test suite cards ranging from 1-5 cards in hand \n\n");
	int randomHandCost;
	int actualRandomHandCost;
	for (pt = 0; pt < numPlayers; pt++) {
		for (handCount = 1; handCount <= maxHandCount; handCount++) {
			randomHandCost = 0;							//reset random handcost
			actualRandomHandCost = 0;					//reset actual random handcost
			memset(&G, 23, sizeof(struct gameState));   // clear the game state
			initializeGame(numPlayers, k, seed, &G); // initialize a new game
			memcpy(&testG, &G, sizeof(struct gameState));	//initialize test game
		for (i = 0; i < 10; i++) {				
				testG.handCount[pt] = handCount;
				j = 0;
				while (j < handCount) {					//up to the # of cards in hand we are testing
					testG.hand[pt][j] = k[i];					//set the jth card of player pt's hand to ith card
					randomHandCost += getCost(testG.hand[pt][j]);	//grab total cost
					actualRandomHandCost += kCosts[i];
					j++;
				}
#if(NOISY_TEST==1)
				printf("player %d current handcost: %d , actual handCost: %d\n", pt, randomHandCost, actualRandomHandCost);
#endif
				assert(randomHandCost == actualRandomHandCost);
			}
		}
	}
	//adventurer , council, mine, remodel, salvager

	printf("Test 3: checking state after playing: adventurer, council, mine, remodel, salvager");
		//for (i = 0; i < 5; i++) {
		//	memset(&G, 23, sizeof(struct gameState));   // clear the game state
		//	r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
		//	memcpy(&testG, &G, sizeof(struct gameState));	//initialize test game
		//	cardEffect(testSuite[i],)
		//}
		printf("Test 3: getCost after playing council card\n");
		memset(&G, 23, sizeof(struct gameState));
		 initializeGame(numPlayers, k, seed, &G);
		memcpy(&testG, &G, sizeof(struct gameState));
		//cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
		totalHandCost = 0;
		int oldHand[5];
		printf("OLD HAND: ");
		for (i = 0; i < 5; i++) {
			totalHandCost += getCost(testG.hand[PLAYERONE][i]);
			oldHand[i] = testG.hand[PLAYERONE][i];
			printf("%d ", oldHand[i]);
		}
		printf("Old hand cost: %d\n", totalHandCost);
		//save the old hand cost
		int oldHandCost = totalHandCost;
		//reset total handcost
		totalHandCost = 0;
		cardEffect(8, 0, 0, 0, &testG, 0, &bonus);
		//check hand of player after playing council card
		printf("drawed four cards after playing council \n");
		printf("hand after playing council: ");
		for (i = 0; i < testG.handCount[PLAYERONE]; i++) {
			printf("%d ", testG.hand[PLAYERONE][i]);
			totalHandCost += getCost(testG.hand[PLAYERONE][i]);
		}
		printf("\n\n");
		printf("new hand cost is %d \n", totalHandCost);
		assert(totalHandCost >= oldHandCost);

}