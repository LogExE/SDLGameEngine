#include "GameContextSDL.hpp"

GameContextSDL::GameContextSDL()
{
    SDL_Init(SDL_INIT_EVERYTHING);
}

GameContextSDL::~GameContextSDL()
{
    SDL_Quit();
}
