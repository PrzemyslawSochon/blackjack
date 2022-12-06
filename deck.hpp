#pragma once

#include "card.hpp"
#include <array>

using DeckType = std::array<Card, 52>;
using Index = std::array<Card, 52>::size_type;

class Deck
{

private:
    DeckType m_deck;
    Index m_cardIndex{0};

public:
    Deck();
    
    void print() const;

    void shuffle();

    const Card& dealCard();

    friend class Player;
    friend bool playerTurn(Deck& deck, Player& player);
    friend bool playBlackJack(Deck& deck);
};