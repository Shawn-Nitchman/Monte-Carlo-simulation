#pragma once
#include <deque>
#include "Card.h"

class Deck
{
public:
	Deck();
	~Deck();

	void Print();
	void Shuffle();

	Card* TopCard();
	void  PopCard();

private:
	std::deque<Card*> deck;
};