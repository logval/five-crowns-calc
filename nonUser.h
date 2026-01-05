#pragma once

#include <string>

using namespace std;

#include "player.h"

class NonUser : public Player {
	public:
		NonUser(string name);
		~NonUser(); 
};
