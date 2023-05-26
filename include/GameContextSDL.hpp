
#pragma once

#include <SDL2/SDL.h>

#include "GameContext.hpp"
#include "WindowSDL.hpp"

class GameContextSDL : public GameContext
{
public:
    GameContextSDL();
    ~GameContextSDL();

    void process_events();
};