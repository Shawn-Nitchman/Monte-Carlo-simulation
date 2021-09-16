#include "Card.h"

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

int Card::GetFaceValue() 
{
	if (Rank <= TEN)
		return static_cast<int>(Rank);

	if (Rank <= KING)
		return 10;

	return 11;
}