#pragma once

#include <vector>
#include <map>
#include <string>

using namespace std;

#include "player.h"

class Game {
	public:
		Game(int numPlayers, string playerNames, int user);
		~Game();
		void newRound(int roundSize);
		void nextTurn(bool mustLayDown);
		Player* getUser();
		Player* getPlayer(int num);
				
	private: 
		int user;
		int turn;
		int cardsLeft; 
		int roundSize;
		string discardTop;
		vector<Player*> players;
};
