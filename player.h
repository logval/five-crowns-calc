#pragma once

#include <vector>
#include <map>
#include <string>

using namespace std;

class Player {
	public:
		Player(string name);
		~Player();
		void newRound(int roundSize);
		// show hand
		
	private: 
		string name;
		int roundSize;
		int* hand;
};
