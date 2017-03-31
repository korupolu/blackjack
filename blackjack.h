#ifndef _BALCKJACK_H
#define _BLACKJACK_H

/**
* Game related error codes. Please don't modify them.
*/
#define PLAYER_BUST_HAPPENED					-10
#define DEALER_BUST_HAPPEND						-10
#define NO_MORE_CARDS_IN_DECK					-11
#define BLACKJACK_INTERNAL_ERROR				-12
#define PLAYER_WON_THE_GAME						0

/**
* Player and Dealar related codes which can be modified as per requirements.
* But extra attention needed in changing them to function the game properly.
**/
#define PLAYER_BURST_SCORE						21
#define DEALER_BUSRST_SCORE						17
#define INITIAL_PLAYER_CARDS_TO_BE_DISTRIBUTED	2
#define INITIAL_DEALER_CARDS_TO_BE_DISTRIBUTED	2
#define INITIAL_DEALER_CARDS_TO_BE_SHOWN		1
#define MAX_CARD_FULL_NAME_LENGTH				13
#define MAX_CARD_NAME_LENGTH					3


/**
*Codes related to the player cards deck. Please don't modify them
**/
#define NUMBER_OF_CARDS_IN_DECK				52
#define NUMBER_OF_CARDS_IN_SUITE			13
#define NUMBER_OF_SUITES					4
#define CLUB_CARD							0
#define DIAMOND_CARD						1
#define HEART_CARD							2
#define SPADE_CARD							3


/**
* Card values. These values can be modified as per requirement.
**/

#define MAX_CARD_A_VALUE					11
#define MIN_CARD_A_VALUE					1
#define CARD_2_VALUE						2
#define CARD_3_VALUE						3
#define CARD_4_VALUE						4
#define CARD_5_VALUE						5
#define CARD_6_VALUE						6
#define CARD_7_VALUE						7
#define CARD_8_VALUE						8
#define CARD_9_VALUE						9
#define CARD_10_VALUE						10
#define CARD_J_VALUE						10
#define CARD_Q_VALUE						10
#define CARD_K_VALUE						10

/**
* Codes for card characters to be displayed
**/

#define CARD_A_CHAR							1
#define CARD_2_CHAR							2
#define CARD_3_CHAR							3
#define CARD_4_CHAR							4
#define CARD_5_CHAR							5
#define CARD_6_CHAR							6
#define CARD_7_CHAR							7
#define CARD_8_CHAR							8
#define CARD_9_CHAR							9
#define CARD_10_CHAR						10
#define CARD_J_CHAR							11
#define CARD_Q_CHAR							12
#define CARD_K_CHAR							13
#define CARD_A_CHAR_LETTER					"A"
#define CARD_2_CHAR_LETTER					"2"
#define CARD_3_CHAR_LETTER					"3"
#define CARD_4_CHAR_LETTER					"4"
#define CARD_5_CHAR_LETTER					"5"
#define CARD_6_CHAR_LETTER					"6"
#define CARD_7_CHAR_LETTER					"7"
#define CARD_8_CHAR_LETTER					"8"
#define CARD_9_CHAR_LETTER					"9"
#define CARD_10_CHAR_LETTER					"10"
#define CARD_J_CHAR_LETTER					"J"
#define CARD_Q_CHAR_LETTER					"Q"		
#define CARD_K_CHAR_LETTER					"K"	

//function prototype declaration
void startGameAndDisplayResults();
#endif