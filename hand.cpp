#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

#include "hand.h"
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

void Hand::addCard(int card) {
	this->cards.push_back(card);
}

int Hand::discard(int card) {
	int i;
	
	if (!this->contains(card)) {
		throw runtime_error("error: Hand does not contain card");
	} else {
		i = 0; 
		while (i < this->cards.size()) {
			if (this->cards.at(i) == card) {
				break;
			}
			i++;
		}
		
		this->cards.erase(this->cards.begin() + i); 
		
		return card;
	}
}

bool Hand::contains(int card) {
	for (int c : this->cards) {
		if (c == card) {
			return true;
		}
	}
	
	return false;
}

string Hand::handToString() {
	string result = "";
	
	for (int c : this->cards) {
		result = result + cardToString(c) + "\t";
	}
	
	return result;
}
