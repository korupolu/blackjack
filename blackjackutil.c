/*********************************************************************************
*																				 *
* NAME  :	blackjackutils.c												     *
*																				 *	
* PURPOSE:																		 *
*         The purpose of this file is to provide utilities for blackjack game    *
*																				 *
**********************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <ctype.h>
#include "blackjack.h"


/**************************************************************************************************
* PURPOSE:																						  *
*																								  *
*	The purpose of this function is to return the assosiated value with the card.				  *
*																								  *		
* INPUT:																						  *	
*		short card - value of the card															  *
*																								  *	
* OUTPUT:																						  *
*		return the card value assiated with the card after conversion.							  *
***************************************************************************************************/
short getCardValue(short card)
{
	short cardValue = card % NUMBER_OF_CARDS_IN_SUITE + 1;
	switch (cardValue)
	{
	case CARD_A_CHAR:
		cardValue = MAX_CARD_A_VALUE;
		break;
	case CARD_2_CHAR:
		cardValue = CARD_2_VALUE;
		break;
	case CARD_3_CHAR:
		cardValue = CARD_3_VALUE;
		break;
	case CARD_4_CHAR:
		cardValue = CARD_4_VALUE;
		break;
	case CARD_5_CHAR:
		cardValue = CARD_5_VALUE;
		break;
	case CARD_6_CHAR:
		cardValue = CARD_6_VALUE;
		break;
	case CARD_7_CHAR:
		cardValue = CARD_7_VALUE;
		break;
	case CARD_8_CHAR:
		cardValue = CARD_8_VALUE;
		break;
	case CARD_9_CHAR:
		cardValue = CARD_9_VALUE;
		break;
	case CARD_10_CHAR:
		cardValue = CARD_10_VALUE;
		break;
	case CARD_J_CHAR:
		cardValue = CARD_J_VALUE;
		break;
	case CARD_Q_CHAR:
		cardValue = CARD_Q_VALUE;
		break;
	case CARD_K_CHAR:
		cardValue = CARD_K_VALUE;
		break;
	}
	return cardValue;
}

/**************************************************************************************************
* PURPOSE:																						  *
*																								  *
*	The purpose of this function is to store the name of the card at the given address. 		  *
*																								  *
* INPUT:																						  *
*		short card - value of the card															  *
*		char* cardName - address where to store the card name									  *
*																								  *
***************************************************************************************************/
void  getCardName(short card, char* cardName)
{
	short cardValue = card % NUMBER_OF_CARDS_IN_SUITE + 1;
	switch (cardValue)
	{
	case CARD_A_CHAR:
		strcpy(cardName, CARD_A_CHAR_LETTER);
		break;
	case CARD_2_CHAR:
		strcpy(cardName, CARD_2_CHAR_LETTER);
		break;
	case CARD_3_CHAR:
		strcpy(cardName, CARD_3_CHAR_LETTER);
		break;
	case CARD_4_CHAR:
		strcpy(cardName, CARD_4_CHAR_LETTER);
		break;
	case CARD_5_CHAR:
		strcpy(cardName, CARD_5_CHAR_LETTER);
		break;
	case CARD_6_CHAR:
		strcpy(cardName, CARD_6_CHAR_LETTER);
		break;
	case CARD_7_CHAR:
		strcpy(cardName, CARD_7_CHAR_LETTER);
		break;
	case CARD_8_CHAR:
		strcpy(cardName, CARD_8_CHAR_LETTER);
		break;
	case CARD_9_CHAR:
		strcpy(cardName, CARD_9_CHAR_LETTER);
		break;
	case CARD_10_CHAR:
		strcpy(cardName, CARD_10_CHAR_LETTER);
		break;
	case CARD_J_CHAR:
		strcpy(cardName, CARD_J_CHAR_LETTER);
		break;
	case CARD_Q_CHAR:
		strcpy(cardName, CARD_Q_CHAR_LETTER);
		break;
	case CARD_K_CHAR:
		strcpy(cardName, CARD_K_CHAR_LETTER);
	}
}


/**************************************************************************************************
* PURPOSE:																						  *
*																								  *
*	The purpose of this function is to store the full name of the card at the given address      *
*																								  *
* INPUT:																						  *
*		short card - value of the card															  *
*       char *cardFullName - address to store the card full name
*																								  *
***************************************************************************************************/
void getCardFullName(short card, char *cardFullName)
{
	char cardName[MAX_CARD_NAME_LENGTH];
	memset(cardName, '\0', sizeof(cardName));
	getCardName(card, cardName);
	short suiteValue = card / NUMBER_OF_CARDS_IN_SUITE;
	switch (suiteValue)
	{
	case CLUB_CARD:
		strcpy(cardFullName, "CLUB-");
		break;
	case DIAMOND_CARD:
		strcpy(cardFullName, "DIAMOND-");
		break;
	case HEART_CARD:
		strcpy(cardFullName, "HEART-");
		break;
	case SPADE_CARD:
		strcpy(cardFullName, "SPADE-");
	}
	strcat(cardFullName, cardName);
}


/**************************************************************************************************
* PURPOSE:																						  *
*																								  *
*	The purpose of this function is to print the full name of the cards recived by player or      *
*   delater             				                                                          *
*																								  *
* INPUT:																						  *
*		short* cardsReceived -  pointer to the array containg the cards to be displayed           *
*       short noOfCards  - number of card to be displayed from the input array                    *
*																								  *
* OUTPUT:																						  *
*		Prints full card names to console                                                         *
***************************************************************************************************/
void printCards(short* cardsReceived, short noOfCards)
{
	char cardFullName[MAX_CARD_FULL_NAME_LENGTH];	
	for (short cardCount = 0; cardCount < noOfCards; cardCount++)
	{
		memset(cardFullName, '\0', sizeof(cardFullName));
		getCardFullName(*(cardsReceived + cardCount), cardFullName);
		printf("%s ", cardFullName);
		if (cardCount != (noOfCards - 1))
			printf(", ");
	}
}

/**************************************************************************************************
* PURPOSE:																						  *
*																								  *
*The purpose of this function is to assign minimum value of A to total score to avoid from        *
* burst (if player has received A cards and assigned higher value previously)                     *
*                                                                                                 *
*																								  *
* INPUT:																						  *
*	  short* totalScore	- pointer to the total score field 	for the respective player or dealer	  * 
*     short *noOfACount - pointer to the number of A cards received by player or dealer           *
*     short burstValue - bust value to be checked for adjusting total score with minimum A value. *
*																								  *
* OUTPUT:																						  *
*		return the name of the card after converion	.											  *
***************************************************************************************************/
void adjustTotalScore(short *totalScore, short *noOfACount, short burstValue)
{
	while ((*totalScore > burstValue) && (*noOfACount > 0))
	{
		*totalScore -= MAX_CARD_A_VALUE;
		*totalScore += MIN_CARD_A_VALUE;
		*noOfACount -= 1;
		if (*totalScore < burstValue) break;
		//printf("\n\nConsidering one of Card A value as %d  to avoid burst.", MIN_CARD_A_VALUE);
		//printf("\n\nTotal score after update %d ", *totalScore);
	}
}

/**************************************************************************************************
* PURPOSE:																						  *
*																								  *
*   The purpose of this function is to simulate dealer role in balckjack game                     *
*                                                                                                 *
*																								  *
* INPUT:																						  *
*	  short* cardsReceived	- pointer to the array containing the cards received by the dealer    *
*     short initialCardsSize - total number of cards received                                     *
*     short* curCardIndexInDeck - pointer to the current index in deck                            *
*     short* deck - pointer to the array containing the deck of cards                             *
*     short deckSize -  total size of the deck													  *
*																								  *
* OUTPUT:																						  *
*		return below mentioned values based on the out come of the dealer play					  *
*			totalScore - if the dealer moved to stand state.										  *
*			NO_MORE_CARDS_IN_DECK - if player run out of cards in deck                            *
*			DEALER_BUST_HAPPEND  - if dealer score exceeded the bust value                        *
*           BCLACKJACK_INTERNAL_ERROR - if any internal erro detected.                           *
*                                                                                                 *
*			                                                                                      *
***************************************************************************************************/
short playDealer(short *cardsReceived, short initialCardsSize, short *curCardIndexInDeck, short *deck, short deckSize)
{
	//check for invalid values.
	if ((cardsReceived == NULL) || (curCardIndexInDeck == NULL) || (deck == NULL))
	{
		return BLACKJACK_INTERNAL_ERROR;
	}
	short result = 0;
	short totalScore = 0;
	short noOfACount = 0;
	short noOfCardsReceived = initialCardsSize;
	short card = 0;
	short cardValue = 0;
	char newCard[MAX_CARD_FULL_NAME_LENGTH];
	printf("\n\n--------- Dealer game started -------------\n");
	//calculate the initial total score and number of A cards received
	for (short cardIndex = 0; cardIndex < initialCardsSize; cardIndex++)
	{
		card = *(cardsReceived + cardIndex);
		cardValue = getCardValue(card);
		if (cardValue == MAX_CARD_A_VALUE)
			noOfACount++;
		totalScore += cardValue;
	}

	//adjust initial total score if needed
	adjustTotalScore(&totalScore, &noOfACount, DEALER_BUSRST_SCORE);
	result = totalScore;
	//print initial total score and received cards so far
	printf("\n\nDealer initial score: %d", totalScore);
	printf("\nDealer received cards so far: ");
	printCards(cardsReceived, noOfCardsReceived);
	//continue to get more cards or wait till player stands
	while (totalScore <= DEALER_BUSRST_SCORE)
	{
		
		//Check whether dealer score reached bust score
		if (totalScore == DEALER_BUSRST_SCORE)
		{
			printf("\n\nDealer score reached to stand. Current score: %d", totalScore);
			break;
		}
		else
		{
			/**
			* Get the new card if more cards available in deck.
			* update local counts such as total score, result, etc
			**/
			if (*curCardIndexInDeck != NUMBER_OF_CARDS_IN_DECK )
			{
				card = *(deck + *curCardIndexInDeck);
				*curCardIndexInDeck += 1;
				cardValue = getCardValue(card);
				if (cardValue == MAX_CARD_A_VALUE)
					noOfACount++;
				totalScore += getCardValue(card);
				cardsReceived[noOfCardsReceived] = card;
				noOfCardsReceived++;
				//adjust total score if needed
				adjustTotalScore(&totalScore, &noOfACount, DEALER_BUSRST_SCORE);
				//print new card, total score and all the cards received.
				memset(newCard, '\0', sizeof(newCard));
				getCardFullName(card, newCard);
				printf("\n\nNew card dealer received : %s\n", newCard);
				printf("\n\nDealer score: %d", totalScore);
				printf("\nDealer received cards so far: ");
				printCards(cardsReceived, noOfCardsReceived);
				result = totalScore;
			}
			else
			{
				//update result as appopriate error when no more cards present in deck and dealer want one more card
				result = NO_MORE_CARDS_IN_DECK;
				break;
			}
		}
	}
	//check if dealer score is bursted 
	if (totalScore > DEALER_BUSRST_SCORE)
	{
		printf("\n\nOops!.Dealer burst happened.");
		printf("\nCurrent Dealer core: %d", totalScore);
		result = DEALER_BUST_HAPPEND;
	}
	return result;
}

/**************************************************************************************************
* PURPOSE:																						  *
*																								  *
*   The purpose of this function is to simulate player role in balckjack game                     *
*                                                                                                 *
*																								  *
* INPUT:																						  *
*	  short* cardsReceived	- pointer to the array containing the cards received by the player    *
*     short initialCardsSize - total number of cards received                                     *
*     short* curCardIndexInDeck - pointer to the current index in deck                            *
*     short* deck - pointer to the array containing the deck of cards                             *
*     short deckSize -  total size of the deck													  *
*																								  *
* OUTPUT:																						  *
*		return below mentioned values based on the out come of the player play					  *
*			totalScore - if the player moved to stand state.										  *
*			PLAYER_WON_THE_GAME - if player already won the game by reaching bust score           *
*			NO_MORE_CARDS_IN_DECK - if player run out of cards in deck                            *
*			PLAYER_BUST_HAPPENED  - if player score exceeded the bust value                       *
*           BCLACKJACK_INTERNAL_ERROR - if any internal erro detected.                           *
*                                                                                                 *
*			                                                                                      *
***************************************************************************************************/
short playPlayer(short *cardsReceived, short initialCardsSize, short *curCardIndexInDeck, short *deck, short deckSize)
{
	//check for invalid values.
	if ((cardsReceived == NULL) || (curCardIndexInDeck == NULL) || (deck == NULL))
	{
		return BLACKJACK_INTERNAL_ERROR;
	}
	char responseChar= '\0';
	short result = 0;
	short totalScore = 0;
	short noOfACount = 0;
	short noOfCardsReceived = initialCardsSize;
	short card = 0;
	short cardValue = 0;
	char newCard[MAX_CARD_FULL_NAME_LENGTH];
	printf("\n\n--------- Player game started -------------\n");
	//calculate the initial total score and number of A cards received
	for (short cardIndex = 0; cardIndex < initialCardsSize; cardIndex++)
	{
		card = *(cardsReceived + cardIndex);
		cardValue = getCardValue(card);
		if (cardValue == MAX_CARD_A_VALUE)
			noOfACount++;
		totalScore += cardValue;
	}
	
	//adjust initial total score if needed
	adjustTotalScore(&totalScore, &noOfACount, PLAYER_BURST_SCORE);
	result = totalScore;
	//print initial total score and received cards so far
	printf("\nPlayer initial score: %d", totalScore);
	printf("\nPlayer received cards so far: ");
	printCards(cardsReceived, noOfCardsReceived);
	//continue to get more cards or wait till player stands
	while (totalScore <= PLAYER_BURST_SCORE)
	{
		//check whether player wins by reaching total score equal to burst score. 
		if (totalScore == PLAYER_BURST_SCORE)
		{
			printf("\n\nCongracts!. Player reached maximum score: %d ", totalScore);
			result = PLAYER_WON_THE_GAME;
			break;
		}
		else
		{
			do
			{
				if (responseChar != '\n')
				{
					printf("\n\nDo you want to continue by taking more cards or stand? press Y for more cards OR press N to stand\n");
				}
				scanf("%c", &responseChar);
				fflush(stdin);
			} while (tolower(responseChar) != 'y' && tolower(responseChar) != 'n');

			if (responseChar == 'Y' || responseChar == 'y')
			{
				/*
				* get the new card if more cards available in deck
				* and update local counts such as total score, result, etc
				*/
				if (*curCardIndexInDeck != NUMBER_OF_CARDS_IN_DECK )
				{
					card = *(deck + *curCardIndexInDeck);
					*curCardIndexInDeck += 1;
					cardValue = getCardValue(card);
					if (cardValue == MAX_CARD_A_VALUE)
						noOfACount++;
					totalScore += getCardValue(card);
					cardsReceived[noOfCardsReceived] = card;
					noOfCardsReceived++;
					//adjust total score if needed
					adjustTotalScore(&totalScore, &noOfACount, PLAYER_BURST_SCORE);
					//print the new card, total score and all the cards player received so far
					memset(newCard, '\0', sizeof(newCard));
					getCardFullName(card, newCard);
					printf("\n\nNew card player received : %s\n", newCard);
					printf("\n\nPlayer score: %d", totalScore);
					printf("\nPlayer received cards so far: ");
					printCards(cardsReceived, noOfCardsReceived);
					result = totalScore;
				}
				else
				{
					//update result as appopriate error when no more cards present in deck and player want one more card
					result = NO_MORE_CARDS_IN_DECK;
					break;
				}
			}
			else
			{
				//player requested to stand
				result = totalScore;
				break;
			}

		}
	}
	//check if player is bursted and update result.
	if (totalScore > PLAYER_BURST_SCORE)
	{
		result = PLAYER_BUST_HAPPENED;
		printf("\n\nOops!. Player burst happened.\n");
		printf("\nCurrent player score is %d . Player lost the game", totalScore);
	}
	return result;
}
/**************************************************************************************************
*PURPOSE:                                                                                         *
*       This function initializes the deck of cards with its initial values starting from 0        *
*       to deck size                                                                              *
*                                                                                                 *
*INPUT:																						      *
*                                                                                                 *
*     short* deck - pointer to the array for storing the deck of cards                            *
*     short deckSize - total size of the deck													  *
*																								  *
* OUTPUT:																						  *
*		array filled with the deck of cards with initial values                  				  *
*			                                                                                      *
***************************************************************************************************/
void initDeck(short *deck, short deckSize)
{
	for (short deckIndex = 0; deckIndex < deckSize; deckIndex++)
	{
		*(deck + deckIndex) = deckIndex;
	}
}

/**************************************************************************************************
*PURPOSE:                                                                                         *
*       This function shuffle the deck of the cards                                               *
*                                                                                                 *
*INPUT:																						      *
*                                                                                                 *
*     short* deck - pointer to the array containing deck of cards                                 *
*     short deckSize - total size of the deck													  *
*																								  *
* OUTPUT:																						  *
*		array filled with the deck of cards shuffled                             				  *
*			                                                                                      *
***************************************************************************************************/
void shuffleDeck(short *deck, short deckSize)
{
	short randomNumber;
	short tempCard;
	srand(time(NULL));
	for (short deckIndex = 0; deckIndex < deckSize; deckIndex++)
	{
		randomNumber = rand() % NUMBER_OF_CARDS_IN_DECK;
		tempCard = deck[deckIndex];
		deck[deckIndex] = deck[randomNumber];
		deck[randomNumber] = tempCard;
	}
}

/**************************************************************************************************
*PURPOSE:                                                                                         *
*       This is the starting point for begining of the blackjack game. This procedure performs    *
*       below functions.																		  *
*																								  *
*       - Initialize the deck of cards                                                            *
*       - Shuffle the deck of cards                                                               *
*       - Distributes the initial cards                                                           *
*       - Player play the game                                                                    *
*       - Dealer play the game if needed                                                          *
*       - Decides the winner and display the winner.                                              *
*       - Error message if any error occured.                                                     *
*                                                                                                 *
*                                                                                                 *
*INPUT:																						      *
*                                                                                                 *
*     short* deck - pointer to the array containing deck of cards                                 *
*     short deckSize - total size of the deck													  *
*																								  *
* OUTPUT:																						  *
*		array filled with the deck of cards shuffled                             				  *
*			                                                                                      *
***************************************************************************************************/
void startGameAndDisplayResults()
{
	short playerCardsReceived[NUMBER_OF_CARDS_IN_DECK];
	short dealerCardsReceived[NUMBER_OF_CARDS_IN_DECK];
	short cardDeck[NUMBER_OF_CARDS_IN_DECK];
	short currentCardIndexInDeck = 0;
	short totalPlayerScore = 0;
	short totalDealerScore = 0;
	initDeck(cardDeck, NUMBER_OF_CARDS_IN_DECK);
	shuffleDeck(cardDeck, NUMBER_OF_CARDS_IN_DECK);
	for (short cardIndex = 0; cardIndex < INITIAL_PLAYER_CARDS_TO_BE_DISTRIBUTED; cardIndex++)
	{
		playerCardsReceived[cardIndex] = cardDeck[currentCardIndexInDeck];
		currentCardIndexInDeck++;
	}
	for (short cardIndex = 0; cardIndex < INITIAL_DEALER_CARDS_TO_BE_DISTRIBUTED; cardIndex++)
	{
		dealerCardsReceived[cardIndex] = cardDeck[currentCardIndexInDeck];
		currentCardIndexInDeck++;
	}
	printf("\n----------------------------------------------------------------------------- \n");
	printf("-------------   GAME STARTED. DISTRIBUTING INITIAL CARDS   ------------------- \n");
	printf("\n----------------------------------------------------------------------------- \n");
	printf("\nDealer received %d cards. Only below cards are allowed to face-up : \n\n", INITIAL_DEALER_CARDS_TO_BE_DISTRIBUTED);
	printCards(dealerCardsReceived, INITIAL_DEALER_CARDS_TO_BE_SHOWN);
	printf("\n");
	totalPlayerScore = playPlayer(playerCardsReceived, INITIAL_PLAYER_CARDS_TO_BE_DISTRIBUTED, &currentCardIndexInDeck, cardDeck, NUMBER_OF_CARDS_IN_DECK);
	switch (totalPlayerScore)
	{
	case PLAYER_WON_THE_GAME:
		printf("\n\n------------------------------------------- \n");
		printf("	FINAL RESULT: PLAYER WON THE GAME	");
		printf("\n------------------------------------------- ");
		break;
	case PLAYER_BUST_HAPPENED:
		printf("\n\n------------------------------------------- \n");
		printf("	FINAL RESULT: DEALER WON THE GAME	");
		printf("\n------------------------------------------- ");
		break;
	case NO_MORE_CARDS_IN_DECK:
		printf("\n\n------------------------------------------- -----------\n");
		printf("	GAME CANCELLED. ALL TEH CARDS ARE USED IN DECK	");
		printf("\n------------------------------------------------------- ");
		break;
	case BLACKJACK_INTERNAL_ERROR:
		printf("\n\n------------------------------------------- -----------\n");
		printf("	SORRY. INTERNAL ERROR. GAME CANCELLED. TRY AGAIN	");
		printf("\n------------------------------------------------------- ");
		break;
		
	default:
		totalDealerScore = playDealer(dealerCardsReceived, INITIAL_DEALER_CARDS_TO_BE_DISTRIBUTED, &currentCardIndexInDeck, cardDeck, NUMBER_OF_CARDS_IN_DECK);
		switch(totalDealerScore)
		{
			case BLACKJACK_INTERNAL_ERROR:
				printf("\n\n------------------------------------------- -----------\n");
				printf("	SORRY. INTERNAL ERROR. GAME CANCELLED. TRY AGAIN	");
				printf("\n------------------------------------------------------- ");
				break;
			case  DEALER_BUST_HAPPEND:
				printf("\n\n------------------------------------------- \n");
				printf("	FINAL RESULT: PLAYER WON THE GAME	");
				printf("\n------------------------------------------- ");
				break;
			case NO_MORE_CARDS_IN_DECK:
				printf("\n\n------------------------------------------- -----------\n");
				printf("	GAME CANCELLED. ALL TEH CARDS ARE USED IN DECK	");
				printf("\n------------------------------------------------------- ");
				break;
			default:
				if (totalDealerScore == totalPlayerScore)
				{
					printf("\n\nPlayer score : %d, Dealer score %d.", totalPlayerScore, totalDealerScore);
					printf("\n\n------------------------------------------- ---------------------\n");
					printf("	FINAL RESULT: NO ONE WON THE GAME. BOTH GOT SAME SCORE	");
					printf("\n------------------------------------------- ------------------------");

				}
				else
				{
					if (totalDealerScore > totalPlayerScore)
					{
						printf("\n\nPlayer score : %d, Dealer score %d.", totalPlayerScore, totalDealerScore);
						printf("\n\n------------------------------------------- \n");
						printf("	FINAL RESULT: DEALER WON THE GAME	");
						printf("\n------------------------------------------- ");
					}
					else
					{
						printf("\n\nPlayer score : %d, Dealer score %d.", totalPlayerScore, totalDealerScore);
						printf("\n\n------------------------------------------- \n");
						printf("	FINAL RESULT: PLAYER WON THE GAME	");
						printf("\n------------------------------------------- ");
					}
			}
		}
	}
}