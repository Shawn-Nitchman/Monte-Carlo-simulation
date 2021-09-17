#include "Card.h"
#include <iostream>

Card::Card(Ranks RANK, Suits SUIT)
	: Rank(RANK),
	  Suit(SUIT)
{
}

// vitual destructor to prevent memory leaks
Card::~Card()
{
}

Card::Ranks Card::GetRank()
{
	return Rank;
}

Card::Suits Card::GetSuit()
{
	return Suit;
}

int Card::GetBridgeValue() 
{
	switch (Rank)
	{
	case Card::JACK:
		return 1;
	case Card::QUEEN:
		return 2;
	case Card::KING:
		return 3;
	case Card::ACE:
		return 4;
	default:
		return 0;
	}

	return 0;
}

void Card::Print()
{
	if (Rank <= TEN)
		std::cout << Rank;
	else if (Rank == JACK)
		std::cout << "J";
	else if (Rank == QUEEN)
		std::cout << "Q";
	else if (Rank == KING)
		std::cout << "K";
	else
		std::cout << "A";

	if (Suit == HEARTS)
		std::cout << "H";
	else if (Suit == DIAMONDS)
		std::cout << "D";
	else if (Suit == CLUBS)
		std::cout << "C";
	else
		std::cout << "S";
}