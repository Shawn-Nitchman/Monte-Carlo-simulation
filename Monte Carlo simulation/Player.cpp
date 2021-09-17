#include "Player.h"
#include <iostream>

Player::Player() 
{
}

void Player::deal(Deck deck)
{
    for (int i = 0; i <= 12; i++) {
        Card* card = deck.TopCard();
        hand.push_back(card);
        std::cout << " ";
        deck.PopCard();
    }
}

void Player::PrintHand()
{
    for (Card* card : hand)
    {
        card->Print();
        std::cout << " ";
    }
}

int Player::getScore()
{
    int score = 0;
    int heartCount = 0, clubCount = 0, spadeCount = 0, diamondCount = 0;

    for (int i = 0; i <= 12; i++)
    {
        score += hand[i]->GetBridgeValue();

        switch (hand[i]->GetSuit())
        {
        case Card::CLUBS:
            clubCount++;
            break;
        case Card::SPADES:
            spadeCount++;
            break;
        case Card::DIAMONDS:
            diamondCount++;
            break;
        case Card::HEARTS:
            heartCount++;
            break;
        default:
            break;
        }
    }

    if (heartCount == 2 || clubCount == 2 || spadeCount == 2 || diamondCount == 2)
        score += 1;

    if (heartCount == 1 || clubCount == 1 || spadeCount == 1 || diamondCount == 1)
        score += 2;

    if (heartCount == 0 || clubCount == 0 || spadeCount == 0 || diamondCount == 0)
        score += 5;

    return score;
}
