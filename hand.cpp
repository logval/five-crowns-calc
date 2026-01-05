#include <vector>
#include <string>

using namespace std;

#include "gameUtils.h"

Hand::Hand(string cards, int roundSize) {
	this->legalSize = roundSize;
	vector<string> parsed = parseLine(cards);
	
	for (string s : parsed) {
		this->cards.push_back(stringToCard(s)); 
	}
}

Hand::~Hand() {
	// nothing happens here
}

void addCard(int card) {
	this->cards.push_back(card);
}

int discard(int card) {
	
}

bool contains(int card) {
	for (int c : this->cards) {
		if (c == card) {
			return true;
		}
	}
	
	return false;
}

string handToString() {
	string result = "";
	
	for (int c : this->cards) {
		result = result + cardToString(c) + "\t";
	}
	
	return result;
}
