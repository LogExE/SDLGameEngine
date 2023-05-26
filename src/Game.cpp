#include "Game.hpp"

Game::Game()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    m_wnd = SDL_CreateWindow("mario", 500, 500, 1024, 768, SDL_WINDOW_SHOWN);
}

void Game::run()
{
    running = true;
    while (running)
    {
        SDL_Event ev;
        while (SDL_PollEvent(&ev))
        {
            if (ev.type == SDL_QUIT)
                running = false;
        }
        
    }
}
