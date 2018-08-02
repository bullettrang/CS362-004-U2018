#include "dominion.h"
#include "dominion_helpers.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rngs.h"

#define NUMPLAYERS 2
#define PLAYERONE 0
#define COPPERCOUNT 46

//int stewardEffect(int choice1, int choice2, int choice3, int currentPlayer, struct gameState *state, int handPos) {
//	if (choice1 == 1)
//	{
//		//+2 cards
//		drawCard(currentPlayer, state);
//		drawCard(currentPlayer, state);
//	}
//	else if (choice1 == 2)
//	{
//		//+2 coins
//		state->coins = state->coins + 2;
//	}
//	else
//	{
//		//trash 2 cards in hand
//		//******BUG******
//		discardCard(choice1, currentPlayer, state, 1);
//		discardCard(choice3, currentPlayer, state, 1);
//	}
//
//	//discard card from hand
//	discardCard(handPos, currentPlayer, state, 0);
//	return 0;
//}
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
int main(){
	struct gameState * testG;
	//revised kingdom to include steward
	int kingdom[10] = { adventurer, gardens, embargo, village, minion, steward, cutpurse,
		sea_hag, tribute, smithy };
	int seed = 1000;
	int i;
	int j;
	int currentDeck;
	int previousHand;
	int previousDeck;
	int currentHand;


	int oldCoinCount;
	int newCoinCount;
	srand(time(NULL));
	printf("Testing STEWARD card\n\n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 20; j++) {
			//reset game
			testG = resetGame(kingdom, seed, NUMPLAYERS);

			//choice1 ==1 (+2 cards)
			if (i == 0) {
				testG->handCount[PLAYERONE] = rand() % MAX_HAND;
				testG->deckCount[PLAYERONE] = rand() % MAX_DECK;
				printf("\nTesting Hand Count\n");
				previousDeck = testG->deckCount[PLAYERONE];
				previousHand = testG->handCount[PLAYERONE];
				gainCard(steward, testG, 2, 0);
				stewardEffect(1, copper, copper, PLAYERONE, testG, testG->handCount[0] - 1);

				currentDeck = testG->deckCount[PLAYERONE];
				currentHand = testG->handCount[PLAYERONE];

				printf("Expected: %d, Actual: %d\n", previousHand + 2, currentHand);

				if (currentHand == previousHand + 2) {
					printf("Correct handcount\n");
				}
				else {
					printf("Incorrect hand count");
				}

				printf("Expected: %d, Actual: %d\n", previousDeck - 2, currentDeck);
				if (currentDeck == previousDeck - 2) {
					printf("Correct Deck count\n");
				}
				else {
					printf("Incorrect deck count\n");
				}
			}//+2 coins 
			//46 copper
			//40 silver
			//30 gold
			else if (i == 1) {
				testG->coins = rand() % COPPERCOUNT;
				oldCoinCount = testG->coins;
				previousHand = testG->handCount[PLAYERONE];
				printf("\nTesting coin count\n");
				gainCard(steward, testG, 2, 0);
				stewardEffect(2, copper, copper, PLAYERONE, testG, testG->handCount[0] - 1);
				currentHand = testG->handCount[PLAYERONE];
				newCoinCount = testG->coins;
				printf("Expected: %d, Actual: %d\n", oldCoinCount + 2, newCoinCount);
				//CHECK COINS
				if (newCoinCount == oldCoinCount + 2) {
					printf("Coin count correct\n");
				}
				else {
					printf("Coin count wrong\n");
				}
				//CHECK HAND
				printf("\nTesting hand count\n");
				printf("Expected: %d, Actual: %d\n", previousHand, currentHand);
			}
			else {
				testG->handCount[PLAYERONE] = rand() % MAX_HAND;
				printf("\nTesting Hand Count\n");
				previousHand = testG->handCount[PLAYERONE];
				gainCard(steward, testG, 2, 0);
				stewardEffect(3, copper, copper, PLAYERONE, testG, testG->handCount[0] - 1);
				currentHand = testG->handCount[PLAYERONE];

				printf("Expected: %d, Actual: %d\n",previousHand+2, currentHand);
				if (currentHand == previousHand + 2) {
					printf("Hand count after trashing correct\n");
				}
				else {
					printf("Hand count after trashing wrong\n");

				}
			}

			//CLEAN UP
			free(testG);
			}

		}
	printf("\n\n Testing Steward is done \n\n");
	}

