#pragma once

#include <string>
#include <map>

using namespace std;

#include "player.h"

class User : public Player {
	public:
		User(string name);
		~User(); 
		void updateSeen(int card);
	
	private: 
		map<int, int> seenCards; // key: card ID, value: # seen
};
