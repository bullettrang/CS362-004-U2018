/* -----------------------------------------------------------------------
*
* Include the following lines in  makefile:
*
* unittest4: unittest4.c dominion.o rngs.o
*      gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
* -----------------------------------------------------------------------
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#define NOISY_TEST 1

struct gameState * resetGame(int k[], int seed,int players) {
	struct gameState * g;
	//create/reset a game
	g = malloc(sizeof(struct gameState) * 1);

	//init game
	initializeGame(players, k, seed, g);
	//create a copy of the game


	return g;

}
int main() {
	struct gameState * testG;
	int kingdom[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };
	int seed = 1000;
	int i;
	int players;
	
	players = 2;
	//testing 2 player, 3 player, 4 player games
	for (i = 0; i < 3; i++) {
		players = i + 2;
		printf("testing with %d players\n", players);
		// initialize game
		testG = resetGame(kingdom, seed,players);
		int curplayer;
		int turn;
		curplayer = 0;
		
		switch (players) {
		
			case 2:
				printf("In 2 players case\n");
				turn = whoseTurn(testG);
				//player 1 turn in 2-player game
				printf("Expected turn player %d, Actual turn: %d\n",curplayer +1, turn + 1);
				assert(turn == curplayer);
				endTurn(testG);
				//checking player 1 hand after p1 turn ends
				printf("checking previous player %d's hand\n", curplayer+1);
				assert(testG->handCount[curplayer] == 0);
				curplayer++;
				turn = whoseTurn(testG);
				//player 2 turn in 2-player game
				printf("Expected turn player %d, Actual turn: %d\n", curplayer + 1, turn + 1);
				assert(turn == 1);
				endTurn(testG);
				printf("checking previous player %d's hand\n", curplayer + 1);
				assert(testG->handCount[curplayer] == 0);
				//returning to player 1 again
				printf("Full rotation of turns, checking previous player %d's hand\n", curplayer + 1);
				assert(testG->handCount[curplayer] == 0);
				turn = whoseTurn(testG);
				assert(turn == 0);
				free(testG);
				break;

			case 3:
				printf("In 3 players case\n");
				turn = whoseTurn(testG);
				//player 1 turn in 3-player game
				printf("Expected turn player %d, Actual turn: %d\n", curplayer + 1, turn + 1);
				assert(turn == 0);
				endTurn(testG);
				//checking player 1 hand after p1 turn ends
				printf("checking previous player %d's hand\n", curplayer + 1);
				assert(testG->handCount[curplayer] == 0);
				curplayer++;
				turn = whoseTurn(testG);
				//player 2 turn in 3-player game
				printf("Expected turn player %d, Actual turn: %d\n", curplayer + 1, turn + 1);
				assert(turn == curplayer);
				endTurn(testG);
				//checking p2 hand
				printf("checking previous player %d's hand\n", curplayer + 1);
				assert(testG->handCount[curplayer] == 0);
				curplayer++;
				turn = whoseTurn(testG);
				//player 3 turn in 3-player game
				printf("Expected turn player %d, Actual turn: %d\n", curplayer + 1, turn + 1);
				assert(turn == curplayer);
				endTurn(testG);
				printf("checking previous player %d's hand\n", curplayer + 1);
				assert(testG->handCount[curplayer] == 0);
				curplayer = 0;
				turn = whoseTurn(testG);
				printf("Full rotation of turns, checking previous player %d's hand\n", curplayer + 1);
				assert(turn == curplayer);
				free(testG);
				break;
			case 4:
				printf("In 4 players case\n");
				turn = whoseTurn(testG);
				//player 1 turn in 4-player game
				printf("Expected turn player %d, Actual turn: %d\n", curplayer + 1, turn + 1);
				assert(turn == curplayer);
				endTurn(testG);
				//checking player 1 hand after p1 turn ends
				printf("checking previous player %d's hand\n", curplayer + 1);
				assert(testG->handCount[curplayer] == 0);
				curplayer++;
				turn = whoseTurn(testG);
				//player 2 turn in 3-player game
				printf("Expected turn player %d, Actual turn: %d\n", curplayer + 1, turn + 1);
				assert(turn == curplayer);
				endTurn(testG);
				//checking p2 hand
				printf("checking previous player %d's hand\n", curplayer + 1);
				assert(testG->handCount[curplayer] == 0);
				curplayer++;
				turn = whoseTurn(testG);
				//player 3 turn in 3-player game
				printf("Expected turn player %d, Actual turn: %d\n", curplayer + 1, turn + 1);
				assert(turn == curplayer);
				endTurn(testG);
				//checking p3 hand
				printf("checking previous player %d's hand\n", curplayer + 1);
				assert(testG->handCount[curplayer] == 0);
				curplayer++;
				turn = whoseTurn(testG);
				printf("Expected turn player %d, Actual turn: %d\n", curplayer + 1, turn + 1);
				assert(turn == curplayer);
				endTurn(testG);
				turn = whoseTurn(testG);
				//player 4 turn in 4-player game
				printf("checking previous player %d's hand\n", curplayer + 1);
				assert(testG->handCount[curplayer] == 0);
				curplayer = 0;
				turn = whoseTurn(testG);
				printf("Full rotation of turns, checking previous player %d's hand\n", curplayer + 1);
				assert(turn == curplayer);
				free(testG);
				break;
			default:
				break;
		}
		
	}
	


}