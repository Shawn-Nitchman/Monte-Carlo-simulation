#pragma once
#include <vector>
#include <string>

class Deck
{
public:
	Deck();
	~Deck();

	void Print();
	void Shuffle();

private:
	std::vector<std::string> deck;
};