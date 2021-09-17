#include <iostream>
#include <ctime>
#include "Deck.h"

int main()
{
    srand(time(nullptr));

    Deck deck;

    deck.Print();
    std::cout << std::endl;
    deck.Shuffle();
    deck.Print();
}

//void deal()
//{
//    for (int i = 0; i <= 12; i++) {
//        Card* card = deck.TopCard();
//        hand.push_back(card);
//        std::cout << " ";
//        deck.PopCard();
//    }
//}

//int getScore(Card hand[13])
//{
//    int score = 0;
//    int heartCount = 0, clubCount = 0, spadeCount = 0, diamondCount = 0;
//
//    for (int i = 0; i <= 12; i++)
//    {
//        score += hand[i]->GetBridgeValue();
//
//        switch (hand[i]->GetSuit())
//        {
//        case Card::CLUBS:
//            clubCount++;
//            break;
//        case Card::SPADES:
//            spadeCount++;
//            break;
//        case Card::DIAMONDS:
//            diamondCount++;
//            break;
//        case Card::HEARTS:
//            heartCount++;
//            break;
//        default:
//            break;
//        }
//    }
//
//    if (heartCount == 2 || clubCount == 2 || spadeCount == 2 || diamondCount == 2)
//        score += 1;
//
//    if (heartCount == 1 || clubCount == 1 || spadeCount == 1 || diamondCount == 1)
//        score += 2;
//
//    if (heartCount == 0 || clubCount == 0 || spadeCount == 0 || diamondCount == 0)
//        score += 5;
//
//    return score;
//}

