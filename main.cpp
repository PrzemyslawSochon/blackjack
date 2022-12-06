#include "game.hpp"
#include <cassert>
#include <exception>
#include <iostream>
#include <limits>

int main()
{
  Deck deck{};

  try
  {
  Result result{playBlackjack(deck)};

  switch(result)
    {
      case Result::lose:
      {
        sleep_for(1s);
        std::cout << "You lost!\n";
        break;
      }
      case Result::win:
      {
        sleep_for(1s);
        std::cout << "You won!\n";
        break;
      }
      case Result::tie:
      {
        sleep_for(1s);
        std::cout << "The game ended in a draw!\n";
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
    std::cerr << e.what() << " Please, try again.\n";
  }

  return 0;
}