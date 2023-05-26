
#include "GameContextSDL.hpp"

GameContextSDL::GameContextSDL()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    m_wnd = std::make_unique<WindowSDL>();
}

GameContextSDL::~GameContextSDL()
{
    SDL_Quit();
}

void GameContextSDL::process_events()
{
    SDL_Event ev;
    while (SDL_PollEvent(&ev))
    {
        if (ev.type == SDL_QUIT)
            m_running = false;
    }
}
