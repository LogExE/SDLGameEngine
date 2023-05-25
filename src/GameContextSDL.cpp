
#include "GameContextSDL.hpp"

GameContextSDL::GameContextSDL()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    m_wnd = std::make_unique<WindowSDL>();
}

GameContextSDL::~GameContextSDL()
{
    SDL_Delay(1000);
    SDL_Quit();
}
