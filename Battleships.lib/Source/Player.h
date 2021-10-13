#pragma once

#include "Board.h"

class Player
{
	int scores;
	int missShots;
	std::string nick;
	Battleships::Board plane;

public:

	Player();
	Player(int, int, const std::string&);
	Player(const std::string&);

	friend std::ostream operator<<(std::ostream& os, const Player& p);
	friend std::istream operator>>(std::istream& is, Player& p);
};