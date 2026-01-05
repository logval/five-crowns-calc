/* 
 * a calculator designed for the hit card game five crowns
 * by logval a.k.a. tofu dragon
 *
 */

#include <string>
#include <iostream>
#include <system>

using namespace std;

#include "game.h"
#include "gameUtils.h"
#include "player.h"

int main() {
	string input;
	int numPlayers;
	int roundSize;
	int userDeal;
	vector<string> names;
	Game* game;
	Player* user;
	
	system("clear");
	cout << "welcome to the five crowns calc" << endl;
	
	while (stoi(input) < 2 || stoi(input) > 7) {
		cout << "from 2 to 7, how many players? ";
		cin >> input;
	}
	
	numPlayers = stoi(input);
	roundSize = 3;
	input = "-1"
	
	while (stoi(input) < 0 || stoi(input) >= numPlayers) {
		cout << "how many turns until you first deal? ";
		cin >> input;
	}
	
	userDeal = stoi(input);
	
	cout << 
	"please provide names for all players in a space seperated list"
	<< endl;
	cout << "starting with the dealer, then moving clockwise: "
	cin >> input
	
	
	
	system("clear");
	
	
	
	if (game != nullptr) {
		delete game;
		game = nullptr;
	}
	
	return 0;
}


































































