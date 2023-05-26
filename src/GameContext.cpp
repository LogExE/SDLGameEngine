
#include "core/GameContext.hpp"

GameContext::GameContext()
{
    SDL_Init(SDL_INIT_EVERYTHING);
}

GameContext::~GameContext()
{
    SDL_Quit();
}

void GameContext::process_events()
{
    SDL_Event ev;
    while (SDL_PollEvent(&ev))
    {
        if (ev.type == SDL_QUIT)
            m_running = false;
    }
}
