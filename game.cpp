#include "game.hpp"
#include "settings.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>
#include <vector>

/********The beginning of Player class body*********/
Player::Player() 
{
    m_score=0;
    m_hand.reserve(12);
    m_aces=0;
}

int Player::getScore() const
{
    return m_score;
}

//In this version of Blackjack aces can give either 1 or 11 points.
inline void Player::evaluateAces()
{

//If player's score indicates loss (surpassed point threshold from settings.hpp)
//the game subtracts 10 points for every ace in player's hand.
    while(m_score>g_maximumScore && m_aces>0)
    {
        m_score-=10;
        --m_aces;
    }
}

//Note the passing by reference. It keeps changes within the Deck itself.
Card Player::drawCard(Deck& deck)
{
    m_hand.push_back(deck.dealCard());

    Card lastDrawnCard{m_hand.back()};

    //keep track of drawn aces
    if(lastDrawnCard.getValue()==11) {++m_aces;}

    int value = lastDrawnCard.getValue();
    m_score+=value;

    return lastDrawnCard;
}

Card Player::showCard() const
{
    return m_hand.back();
}

bool Player::isBust()
{
    return(m_score>g_maximumScore);
}
/********The end of Player class body*********/

bool playerWantsHit()
{
    while (true)
    {
        std::cout << "Hit or stand? ";

        char ch{};
        std::cin >> ch;

        if(!std::cin)
        {
            throw std::runtime_error("Invalid input.");
        }

        else
        {
            //Ignores everything after 1st char i.e. buffer works with words and sentences.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch (ch)
            {
            case 'h':
            case 'H':
                return true;
            case 's':
            case 'S':
                return false;
            }
        }
    }
}

bool playerTurn(Deck& deck, Player& player)
{
    while (true)
    {
        if (player.isBust())
        {
            std::cout << "You busted!\n";
            return true;
        }
        else
        {
            if (playerWantsHit())
            {
                Card card{ player.drawCard(deck) };
                player.evaluateAces();
                std::cout << "You were dealt ";
                sleep_for(1s);
                card.print();
                std::cout << " and now have " << player.getScore() << " points.\n";
            }
            else
            {
                // The player didn't go bust.
                return false;
            }
        }
    }
}

bool dealerTurn(Deck& deck, Player& dealer)
{
    //Computer draws cards until it reaches value from settings.hpp
    while (dealer.getScore() < g_minimumDealerScore)
    {
        Card card{ dealer.drawCard(deck) };
        dealer.evaluateAces();
        std::cout << "The dealer turned up ";
        sleep_for(1s);
        card.print();
        sleep_for(1s);
        std::cout << " and now has " << dealer.getScore() << " points.\n";

    }

    // If the dealer's score is too high, they went bust.
    if (dealer.isBust())
        {
            std::cout << "The dealer busted!\n";
            return true;
        }
    return false;
}

Result playBlackjack(Deck& deck)
{
    deck.shuffle();

    // Create the dealer and give them 1 card.
    Player dealer{};
    dealer.drawCard(deck);

    // The dealer's card is face up, the player can see it.
    std::cout << "The dealer is showing: ";
    sleep_for(1s);
    dealer.showCard().print();
    sleep_for(1s);
    std::cout << " and has " << dealer.getScore() << " points.\n";

    // Create the player and give them 2 cards.
    Player player{};

    player.drawCard(deck);
    std::cout << "You drawn ";
    sleep_for(1s);
    player.showCard().print();
    player.drawCard(deck);

    sleep_for(2s);
    std::cout << "\nYou drawn ";
    player.showCard().print();
    sleep_for(2s);
    player.evaluateAces();

    std::cout << "\nYou have: " << player.getScore() << " points.\n";

    if (playerTurn(deck, player))
    {
        // The player went bust and loses.
        return Result::lose;
    }

    if (dealerTurn(deck, dealer))
    {
        // The dealer went bust, the player wins.
        return Result::win;
    }

    //If both players stand and none busted, compare their points.

    if(player.getScore() < dealer.getScore()) {return Result::lose;}
    else if (player.getScore() > dealer.getScore()) {return Result::win;}
    else {return Result::tie;}
}