#pragma once

#include <string>
#include <vector>

using namespace std;

/* 
 * notes on card util functions:
 * 	- jokers have a value of 0
 * 	- unknown cards have a value of -1
 * 	- suits are as follows: 
 *		SUIT	 	LETTER	NUMERAL
 *		unknown		(N/A)	-1
 *		joker		(N/A)	0
 *		spades		S		1
 * 		hearts		H		2
 * 		diamonds	D		3
 * 		clubs		C		4
 * 		stars		R		5
 * 
 */

void clear();
void toUpper(string s);
bool isQuit(string s);
int stringToCard(string card);
string cardToString(int card); 
int getRank(int card);
int getSuit(int card);
int getCardPoints(int card, int round);
bool isWild(int card, int round);
bool isCard(string card);
bool isCard(int card);
vector<string> parseLine(string line);
bool canBeHand(string line);
