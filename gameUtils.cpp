#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

#include "gameUtils.h"

void toUpper(string s) {
	transform(
		s.begin(), 
		s.end(), 
		s.begin(), 
		[](unsigned char c) {
			return toupper(c);
		}
	);
}

bool isQuit(string s) {
	toUpper(s);
	return (s == "Q" || s == "QUIT");
}

int stringToCard(string card) {
	int result = 0;
	int suitSpot; 
	
	toUpper(card);
	
	if (card == "J" || card == "JKR" || card == "JOKER") {
		result = 0;
	} else if (card == "?") {
		result = -1;
	} else {
		// card suit
		suitSpot = card.size() - 1;
		
		if (card[suitSpot] == 'S') {
			result += 1;
		} else if (card[suitSpot] == 'H') {
			result += 2;
		} else if (card[suitSpot] == 'D') {
			result += 3;
		} else if (card[suitSpot] == 'C') {
			result += 4;
		} else if (card[suitSpot] == 'R') {
			result += 5;
		} 
		
		// remove suit for convenience
		card.pop_back();
		
		// card rank - face char
		if (card == "J") {
			result += 110;
		} else if (card == "Q") {
			result += 120;
		} else if (card == "K") {
			result += 130;
		} else { // card rank - other
			result += stoi(card) / 10;
		}
	}
	
	return result;
}

string cardToString(int card) {
	int rank;
	int suitNum;
	string suit;

	if (card == 0) {
		return "JKR";
	} else if (card == -1) {
		return "?";
	} else {
		rank = getRank(card);
		suitNum = getSuit(card);
				
		if (suitNum == 1) {
			suit = "S";
		} else if (suitNum == 2) {
			suit = "H";
		} else if (suitNum == 3) {
			suit = "D";
		} else if (suitNum == 4) {
			suit = "C";
		} else if (suitNum == 5) {
			suit = "R";
		}
		
		return to_string(rank) + suit;
	}
}

int getRank(int card) {
	if (card == -1) {
		return -1;
	} else {
		return card / 10;
	}
}

int getSuit(int card) {
	return card % 10;
}

bool isWild(int card, int round) {
	return (card == 0 || getRank(card) == round);
}

bool isCard(string card) {
	int suitSpot; 	
	
	toUpper(card);
	
	if (card == "J" || card == "JKR" || card == "JOKER") {
		return true;
	} else if (card == "?") {
		return true;
	} else {
		// card suit
		suitSpot = card.size() - 1;
		
		if (
			card[suitSpot] != 'S' &&
			card[suitSpot] != 'H' &&
			card[suitSpot] != 'D' &&
			card[suitSpot] != 'C' &&
			card[suitSpot] != 'R' 
		) {
			return false;
		}
		
		// remove suit for convenience
		card.pop_back();
		
		return (
			card == "3" ||
			card == "4" ||
			card == "5" ||
			card == "6" ||
			card == "7" ||
			card == "8" ||
			card == "9" ||
			card == "10" ||
			card == "11" ||
			card == "12" ||
			card == "13" ||
			card == "J" ||
			card == "Q" ||
			card == "K" 
		);
	}
}

bool isCard(int card) {
	int rank = getRank(card);
	int suit = getSuit(card);
	
	return (
		(rank == -1 && suit == -1) || // unknown
		(rank == 0 && suit == 0) || // joker
		(
			(rank > 2 && rank < 14) &&
			(suit >= 1 && suit <= 5)
		)
	);	
}

vector<string> parseLine(string line) {
	string term = "";
	vector<string> terms;
	int i = 0;
	char current = line[i];
	
	while (current != '\0') {
		while (current != ' ') {
			term.push_back(current);
			current = line[++i]; 
		}
		
		terms.push_back(term);
		term = "";
		current = line[++i];
	}
	
	return terms;
}

bool canBeHand(string line) {
	vector<string> parsed = parseLine(line);
	
	for (string p : parsed) {
		if (!isCard(p)) {
			return false;
		}
	}
	
	return true;
}
