/*********************************************************************************
*																				 *
* NAME  :	blackjack.c												             *
*																				 *
* PURPOSE:																		 *
*         This is the main file having main() function to start the game         *
*																				 *
**********************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include "blackjack.h"

/**************************************************************************************************
* PURPOSE:																						  *
*																								  *
*	This procedure display the game rules on console.                                          	  *
*																								  *
***************************************************************************************************/
void printInstructions()
{
	printf("\nThere is a standard deck of 52 cards: <URL : https ://en.wikipedia.org/wiki/Standard_52-card_deck>.");
	printf("\nThe dealer shuffles the deck of cards and deals two cards for the player and two cards for itself.");
	printf("\nThe player's cards are face up (shown to the player). One of the dealer's cards is face up, the other one face down.");
	printf("\nThe player can decide if he wants to take one more card.If so, the dealer gives him a card from the deck face up.");
	printf("\nThe player can continue requesting more cards until he decides to \"stand.\"");
	printf("\nThe objective for the player is to have the total of the numbers on the cards to get as close to %d without going", PLAYER_BURST_SCORE);
	printf("\n\"bust\" (exceeding %d).", PLAYER_BURST_SCORE);
	printf("\nIf the player goes bust, he loses the game, and the program ends.");
	printf("\nIf the player's total is %d, he wins the game, and the program ends.", PLAYER_BURST_SCORE);
	printf("\nOtherwise, after the player has finished, the dealer turns the face - down card face up.");
	printf("\nIf the dealer's total is %d or less, he must deal himself cards until the total is at least %d, and then stand.", (DEALER_BUSRST_SCORE -1), DEALER_BUSRST_SCORE);
	printf("\nIf the dealer goes bust, the player wins, and the program ends.");
	printf("\nIf the player has a greater total, he wins the game, and the program ends.");
	printf("\nOtherwise, the dealer wins the game, and the program ends.");
	printf("\nThe values of the cards are counted towards the total as follows :");

	printf("\n	 Card		Value");
	printf("\n	----		---- -");
	printf("\n	2		%d", CARD_2_VALUE);
	printf("\n	3		%d", CARD_3_VALUE);
	printf("\n	4		%d", CARD_4_VALUE);
	printf("\n	5		%d", CARD_5_VALUE);
	printf("\n	6		%d", CARD_6_VALUE);
	printf("\n	7		%d", CARD_7_VALUE);
	printf("\n	8		%d", CARD_8_VALUE);
	printf("\n	9		%d", CARD_9_VALUE);
	printf("\n	10		%d", CARD_10_VALUE);
	printf("\n	J		%d", CARD_J_VALUE);
	printf("\n	Q		%d", CARD_Q_VALUE);
	printf("\n	K		%d", CARD_K_VALUE);
	printf("\n	A		%d or %d\n\n", MIN_CARD_A_VALUE, MAX_CARD_A_VALUE);
}

void main()
{
	
	int option = 0;
	printf("\n\nWelcome to blackjack game.");
	while (option != 3)
	{
		printf("\n\nPlease select the option.\n ");
		printf("\n1 - to start the game.");
		printf("\n2 - to display information about game.");
		printf("\n3 - to exit the game\n");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				system("cls");
				startGameAndDisplayResults();
				break;
			case 2:
				system("cls");
				printInstructions();
				break;
			case 3:
				exit(0);
				break;
		}
	}
}