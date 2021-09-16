#pragma once
#include <vector>
#include "Card.h"

class Deck
{
public:
	Deck();
	~Deck();

private:
	std::vector<Card*> deck; //
};