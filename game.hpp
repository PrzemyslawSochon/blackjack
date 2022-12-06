#pragma once

#include "deck.hpp"
#include <chrono>
#include <thread>
#include <vector>

using namespace std::this_thread;
using namespace std::chrono_literals;
using std::chrono::system_clock;

using HandType = std::vector<Card>;

class Player
{
private:
    int m_score{0};
    HandType m_hand;
    int m_aces{0};

public:
    Player();

    int getScore() const;

    inline void evaluateAces();

    Card drawCard(Deck& deck);

    Card showCard() const;

    bool isBust();

    friend bool playerTurn(Deck& deck, Player& player);
    friend bool dealerTurn(Deck& deck, Player& dealer);
};

enum class Result
{
    win,
    lose,
    tie,

    max_results
};

bool playerWantsHit();
bool playerTurn(Deck& deck, Player& player);
bool dealerTurn(Deck& deck, Player& dealer);
Result playBlackjack(Deck& deck);