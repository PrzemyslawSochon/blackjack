#include "card.hpp"
#include <cassert>
#include <iostream>

class Player
{
    public:
};

//default is needed to initialise array of cards in upcoming Deck class
Card::Card() = default;

Card::Card(CardRank rank, CardSuit suit)
    : m_rank{rank}, m_suit{suit}
{}

void Card::print() const
{
    switch (m_rank)
    {
    case CardRank::rank_2:      std::cout << "two of ";   break;
    case CardRank::rank_3:      std::cout << "three of ";   break;
    case CardRank::rank_4:      std::cout << "four of ";   break;
    case CardRank::rank_5:      std::cout << "five of ";   break;
    case CardRank::rank_6:      std::cout << "six of ";   break;
    case CardRank::rank_7:      std::cout << "seven of ";   break;
    case CardRank::rank_8:      std::cout << "eight of ";   break;
    case CardRank::rank_9:      std::cout << "nine of ";   break;
    case CardRank::rank_10:     std::cout << "ten of ";   break;
    case CardRank::rank_jack:   std::cout << "jack of ";   break;
    case CardRank::rank_queen:  std::cout << "queen of ";   break;
    case CardRank::rank_king:   std::cout << "king of ";   break;
    case CardRank::rank_ace:    std::cout << "ace of ";   break;
    default:
        std::cout << '?';
        break;
    }

    switch (m_suit)
    {
    case CardSuit::club:       std::cout << "clubs";   break;
    case CardSuit::diamond:    std::cout << "diamonds";   break;
    case CardSuit::heart:      std::cout << "hearts";   break;
    case CardSuit::spade:      std::cout << "spades";   break;
    default:
        std::cout << '?';
        break;
    }
}

int Card::getValue() const
{
    switch (m_rank)
    {
    case CardRank::rank_2:        return 2;
    case CardRank::rank_3:        return 3;
    case CardRank::rank_4:        return 4;
    case CardRank::rank_5:        return 5;
    case CardRank::rank_6:        return 6;
    case CardRank::rank_7:        return 7;
    case CardRank::rank_8:        return 8;
    case CardRank::rank_9:        return 9;
    case CardRank::rank_10:       return 10;
    case CardRank::rank_jack:     return 10;
    case CardRank::rank_queen:    return 10;
    case CardRank::rank_king:     return 10;
    case CardRank::rank_ace:      return 11;

    default:
        assert(false && "should never happen");
        return 0;
    }
}