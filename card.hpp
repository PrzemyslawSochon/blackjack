#pragma once

class Deck;
class Player;

class Card
{
public:
    enum CardSuit
    {
        club,
        diamond,
        heart,
        spade,

        max_suits
    };

    enum CardRank
    {
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,
        rank_ace,

        max_ranks
    };

private:
    CardRank m_rank{};
    CardSuit m_suit{};

public:
    Card();
    Card(CardRank rank, CardSuit suit);

    void print() const;
    int getValue() const;

friend class Deck;
};