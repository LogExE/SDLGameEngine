
#include <SDL2/SDL.h>

#include <memory>

#include "Game.hpp"
#include "GameContextSDL.hpp"

int main(int argc, char **argv)
{
    Game game(std::make_unique<GameContextSDL>());
    game.run();
    
    return 0;
}