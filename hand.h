#pragma once

#include <vector>
#include <string>

using namespace std;

class Hand {
	public: 
		Hand(string cards, int roundSize);
		~Hand(); 
		void addCard(int card);
		int discard(int card);
		bool contains(int card);
		string handToString();
		
	private:
		vector<int> cards;
		int legalSize;
};
