#include "deck.hpp"
#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>

Deck::Deck()
{
    Index index{0};

    for (int suit{ 0 }; suit < static_cast<int>(Card::CardSuit::max_suits); ++suit)
    {
        for (int rank{ 0 }; rank < static_cast<int>(Card::CardRank::max_ranks); ++rank)
        {
            m_deck[index] = {static_cast<Card::CardRank>(rank),static_cast<Card::CardSuit>(suit)};
            ++index;
        }
    }
}

void Deck::print() const
{
    for (const auto& card : m_deck)
    {
        card.print();
        std::cout << ' ';
    }

    std::cout << '\n';
}

void Deck::shuffle()
{
    static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

    std::shuffle(m_deck.begin(), m_deck.end(), mt);
    m_cardIndex = 0;
}

const Card& Deck::dealCard()
{
    ++m_cardIndex;
    return m_deck[m_cardIndex];
}