
#pragma once

#include <string>

#include <SDL2/SDL.h>

#include "interfaces/GameState.hpp"

class Game
{
private:
    std::unique_ptr<GameState> m_cur_state;
    SDL_Window *m_wnd;
    SDL_Window *m_rnd;
    bool running = false;

public:
    Game();
    void run();
    
    void setState(std::unique_ptr<GameState> state)
    {
        m_cur_state = std::move(state);
    }
};