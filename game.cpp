#include <vector>
#include <map>
#include <string>

using namespace std;

#include "game.h"
#include "player.h"
#include "user.h"

Game::Game(vector<string> playerNames, int user) {
	this->user = user;
	
	for (int i = 0; i < playerNames.size(); i++) {
		if (i == this->user) {
			// this->players.push_back(new User(playerNames.at(i)));
		} else {
			// this->players.push_back(new Player(playerNames.at(i)));
		}
	}
}

Game::~Game() {
	for (int i = 0; i < this->players.size(); i++) {
		Player* p = this->players.at(this->players.size() - 1 - i);
		this->players.pop_back();
		delete p;
	}
}

void Game::newRound(int roundSize) {
	this->roundSize = roundSize;
	
	for (int i = 0; i < this->players.size(); i++) {
		// this->players.at(i)->newRound(roundSize);
	}
}

Player* Game::getUser() {
	return this->getPlayer(this->user);
}

Player* Game::getPlayer(int num) {
	return this->players.at(num);
}
