#include <iostream>
#include <ctime>
#include "Deck.h"
#include "Player.h"

int main()
{
    srand(time(nullptr));

    Player shawn;

    Deck deck;
    deck.Shuffle();
    deck.Print();

    std::cout << "Shawn Hand" << std::endl;

    shawn.deal(deck);
    shawn.PrintHand();
    std::cout << shawn.getScore();


    system("pause");
    return 0;
}

