#include "Player.h"

Player::Player()
{
}

void Player::Deal(std::vector<std::string>& deck)
{
	for (int i = 0; i < 13; i++)
	{
		hand.at(i) = deck.at(i);
		deck.pop_back();
	}
}

int Player::getScore()
{
}

