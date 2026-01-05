#pragma once

#include <vector>
#include <map>
#include <string>

using namespace std;

#include "player.h"

class Game {
	public:
		Game(vector<string> playerNames, int user);
		~Game();
		void newRound(int roundSize);
		Player* getUser();
		
	private: 
		int user;
		int roundSize;
		string discardTop;
		vector<Player*> players;
		Player* getPlayer(int num);
};
