#pragma once
#include <vector>
#include <string>
#include "Deck.h"


class Player 
{
public:
	Player();

	void Deal(std::vector<std::string>& deck);
	int getScore();

private:
	std::vector<std::string> hand;
};