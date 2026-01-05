#include <vector>
#include <map>
#include <string>

using namespace std;

#include "game.h"
#include "user.h"
#include "nonUser.h"

Game::Game(int numPlayers, string playerNames, int user) {
	this->user = user;
	
	vector<string> names = parseLine(playerNames);
	
	if (names.size() < numPlayers) {
		for (int i = names.size(); i < numPlayers; i++) {
			names.push_back("Player " + to_string(i));
		}
	} 
	
	for (int i = 0; i < names.size(); i++) {
		if (i == this->user) {
			this->players.push_back(new User(names.at(i)));
		} else {
			this->players.push_back(new NonUser(names.at(i)));
		}
	}
}

Game::~Game() {
	for (Player* p : this->players) {
		delete p;
	}
}

void Game::newRound(int roundSize) {
	this->roundSize = roundSize;
	
	for (Player* p : this->players) {
		p->newRound(roundSize);
	}
}

Player* Game::getUser() {
	return this->getPlayer(this->user);
}

Player* Game::getPlayer(int num) {
	return this->players.at(num);
}
