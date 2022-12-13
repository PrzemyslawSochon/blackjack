#include "game.hpp"
#include <cassert>
#include <exception>
#include <iostream>
#include <limits>

int main()
{
  bool wanna_play{true};
  while(wanna_play)
  {

  Deck deck{};

  try
  {
  Result result{playBlackjack(deck)};

  switch(result)
    {
      case Result::lose:
      {
        std::cout << "You lost!\n";
        wanna_play=askForReplay();
        break;
      }
      case Result::win:
      {
        std::cout << "You won!\n";
        wanna_play=askForReplay();
        break;
      }
      case Result::tie:
      {
        std::cout << "The game ended in a draw!\n";
        wanna_play=askForReplay();
        break;
      }
      default:
          assert(false && "should never happen");
          return 1;
    }
  }
  catch(const std::exception& e)
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cerr << e.what() << "Error, try again.\n";
  }
  }

  std::cout << "Thank you for playing! The casino is closing down...\n";

  return 0;
}