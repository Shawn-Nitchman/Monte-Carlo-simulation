#pragma once
#include <deque>
#include <vector>
#include <string>

class Deck
{
public:
	Deck();
	~Deck();

	void Print();
	void Shuffle();

	void  PopCard();

private:
	std::vector<std::string> deck;
};