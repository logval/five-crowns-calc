#pragma once

#include <vector>
#include <map>
#include <string>

using namespace std;

#include "hand.h"

class Player {
	public:
		Player(string name);
		virtual ~Player();
		virtual void newRound(int roundSize);
		virtual int takeTurn(bool *mustLayDown);
		virtual Hand* getHand();
		
	private: 
		string name;
		int points;
		int roundSize;
		Hand* hand;
};
