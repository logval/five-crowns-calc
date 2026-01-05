#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

#include "player.h"
#include "user.h"
#include "hand.h"

User::User(string name): Player(name) {
	this-> name = name;
}

User::~User() {
	if (this->hand != nullptr) {
		delete this->hand;
		this->hand = nullptr;
	}
}

void User::newRound(int roundSize) {
	if (this->hand != nullptr) {
		// count points of current hand
	}
	
	delete this->hand;
	this->roundSize = roundSize;
	this->hand = new Hand("0", roundSize); // test
}

int User::takeTurn(bool *mustLayDown) {
	return 0;
}

Hand* User::getHand() {
	return this->hand;
}

void User::updateSeen(int card) {
	if (this->seenCards.contains(card)) {
		seenCards.at(card) += 1;
	} else {
		seenCards.insert({card, 1});
	}
}
