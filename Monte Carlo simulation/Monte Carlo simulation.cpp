#include <iostream>
#include <algorithm>    
#include <array>
#include <random>       
#include <chrono> 
#include <stdio.h>
#include <ctype.h>

int getScore(std::string hand[13]);
void resetScore(int &shawn, int &brian, float &pass, float &part, float &game, float &smallSlam, float &grandSlam);

int main()
{
    std::array<std::string, 52> deck = { "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "10S", "JS", "QS", "KS", "AS",
                                         "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "10C", "JC", "QC", "KC", "AC",
                                         "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "10D", "JD", "QD", "KD", "AD",
                                         "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "10H", "JH", "QH", "KH", "AH"};
    std::array<std::string, 39> newDeck;
    std::string shawnHand[13];
    std::string brianHand[13];

    char exit = 'Y';
    int shawnScore = 0, brianScore = 0;
    float pass = 0.0, part = 0.0, game = 0.0, smallSlam = 0.0, grandSlam = 0.0;

    std::cout << "Welcome to the Monte Carlo simulation\n";
    do {
        std::cout << "----------------------------------------------------------\n";
        resetScore(shawnScore, brianScore, pass, part, game, smallSlam, grandSlam);

        for (int i = 0; i < 12; i++) 
        {
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));
        }

        for (int i = 0; i <= 12; i++)
        {
            shawnHand[i] = deck[i];
        }

        for (int i = 13; i <= 51; i++)
        {
            newDeck[i - 13] = deck[i];
        }
 
        std::cout << "Here is your hand:\n";
        for (int i = 0; i <= 12; i++)
        {
            std::cout << shawnHand[i] << " ";
        }
        std::cout << "\nThis hand is worth " << getScore(shawnHand) << " points" << "\nRunning simulation...........\n\n";
        shawnScore = getScore(shawnHand);

        for (int i = 0; i <= 999; i++) 
        {
            for (int i = 0; i <= 12; i++)
            {
                brianHand[i] = newDeck[i];
            }
            brianScore = getScore(brianHand);

            if (brianScore + shawnScore < 20)
                pass += 1;
            else if ((brianScore + shawnScore) >= 20 && (brianScore + shawnScore) <= 25)
                part += 1;
            else if ((brianScore + shawnScore) >= 26 && (brianScore + shawnScore) <= 31)
                game += 1;
            else if ((brianScore + shawnScore) >= 32 && (brianScore + shawnScore) <= 35)
                smallSlam += 1;
            else if ((brianScore + shawnScore) >= 36)
                grandSlam += 1;

            for (int i = 0; i < 12; i++)
            {
                unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
                shuffle(newDeck.begin(), newDeck.end(), std::default_random_engine(seed));
            }
        }

        std::cout << "The estiamte proability based on 1000 simulated hands:\n"
            << "Pass: " << (pass / 1000) * 100 << "%\n"
            << "Part Score: " << (part / 1000) * 100 << "%\n"
            << "Game: " << (game / 1000) * 100 << "%\n"
            << "Small Slam: " << (smallSlam / 1000) * 100 << "%\n"
            << "Grand Slam: " << (grandSlam / 1000) * 100 << "%\n";

        std::cout << "Another Hand [Y/N]? ";
        std::cin >> exit;
    } while (toupper(exit) != 'N');
}

int getScore(std::string hand[13])
{
    int score = 0;
    int heartCount = 0, clubCount = 0, spadeCount = 0, diamondCount = 0;

    std::string temp;

    for (int i = 0; i <= 12; i++)
    {
        if (hand[i] == "JS" || hand[i] == "JC" || hand[i] == "JD" || hand[i] == "JH")
            score += 1;
        if (hand[i] == "QS" || hand[i] == "QC" || hand[i] == "QD" || hand[i] == "QH")
            score += 2;
        if (hand[i] == "KS" || hand[i] == "KC" || hand[i] == "KD" || hand[i] == "KH")
            score += 3;
        if (hand[i] == "AS" || hand[i] == "AC" || hand[i] == "AD" || hand[i] == "AH")
            score += 4;

        temp = hand[i];
        if (temp.find_first_of("S") != std::string::npos)
            spadeCount += 1;
        if (temp.find_first_of("C") != std::string::npos)
            clubCount += 1;
        if (temp.find_first_of("D") != std::string::npos)
            diamondCount += 1;
        if (temp.find_first_of("H") != std::string::npos)
            heartCount += 1;
    }

    if (heartCount == 2 || clubCount == 2 || spadeCount == 2 || diamondCount == 2)
        score += 1;

    if (heartCount == 1 || clubCount == 1 || spadeCount == 1 || diamondCount == 1)
        score += 2;

    if (heartCount == 0 || clubCount == 0 || spadeCount == 0 || diamondCount == 0)
        score += 5;

    return score;
}

void resetScore(int &shawn, int &brian, float &pass, float &part, float &game, float &smallSlam, float &grandSlam)
{
    shawn = 0;
    brian = 0;
    pass = 0;
    part = 0;
    game = 0;
    smallSlam = 0;
    grandSlam = 0;
}

//std::cout << "shuffled elements:";
//for (std::string& x : deck) std::cout << ' ' << x;
//std::cout << '\n';


