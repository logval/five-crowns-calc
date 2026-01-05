/* 
 * a calculator designed for the hit card game five crowns
 * by logval a.k.a. tofu dragon
 *
 */

#include <string>
#include <iostream>

using namespace std;

#include "game.h"
#include "gameUtils.h"
#include "user.h"

int main() {
	string input;
	int numPlayers, roundSize, userDeal;
	vector<string> names;
	Game* game;
	Player* user;
	
	clear();
	cout << "welcome to the five crowns calc" << endl;
	
	while (stoi(input) < 2 || stoi(input) > 7) {
		cout << "from 2 to 7, how many players? ";
		cin >> input;
	}
	
	numPlayers = stoi(input);
	roundSize = 3;
	input = "-1";
	
	while (stoi(input) < 0 || stoi(input) >= numPlayers) {
		cout << "how many turns until you first deal? ";
		cin >> input;
	}
	
	userDeal = stoi(input);
	
	cout << 
	"please provide names for all players in a space seperated list"
	<< endl;
	cout << "starting with the dealer, then moving clockwise: ";
	cin >> input;
	
	game = new Game(numPlayers, input, userDeal);
	user = game->getUser();
	input = "";
	
	while (roundSize < 14) {
		clear();
		
		game->newRound(roundSize);
		
		cout << "round " << to_string(roundSize) << endl << endl;
		cout << "your hand: " << endl;
		cout << user->getHand();
		
		
		
		roundSize++;
	}
	
	clear();
	
	cout << "goodbye!" << endl;
	
	if (game != nullptr) {
		delete game;
		game = nullptr;
	}
	
	return 0;
}


































































