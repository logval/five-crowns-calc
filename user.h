#pragma once

#include <string>
#include <map>

using namespace std;

#include "player.h"

class User : public Player {
	public:
		User(string name);
		~User(); 
	
	private: 
		map<int, int> seenCards; // key: card ID, value: # seen
};
