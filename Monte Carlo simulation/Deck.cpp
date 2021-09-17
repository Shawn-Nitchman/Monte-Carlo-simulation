#include "Deck.h"
#include <iostream>
#include <algorithm>
#include <random>

Deck::Deck()
{
	deck.insert(deck.end(), { "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "10S", "JS", "QS", "KS", "AS"});
	deck.insert(deck.end(), { "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "10C", "JC", "QC", "KC", "AC" });
	deck.insert(deck.end(), { "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "10D", "JD", "QD", "KD", "AD" });
	deck.insert(deck.end(), { "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "10H", "JH", "QH", "KH", "AH" });
}

Deck::~Deck()
{
}

void Deck::Print() 
{
	for (int i = 0; i < deck.size(); i++)
		std::cout << deck.at(i) << ' ';
}

void Deck::Shuffle()
{
	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(deck), std::end(deck), rng);
}