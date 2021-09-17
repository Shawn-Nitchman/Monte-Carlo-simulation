#pragma once
#include <deque>
#include "Deck.h"
#include "Card.h"

class Player
{
public:
	Player();
	int getScore();
	void deal(Deck);
	void PrintHand();

private:
	std::deque<Card*> hand;
};