#include <vector>
#include <map>
#include <string>

using namespace std;

#include "player.h"

Player::Player(string name) {
	this->name = name;
}

Player::~Player() {
	// stuff
}

void Player::newRound(int roundSize) {
	this->roundSize = roundSize;
}
