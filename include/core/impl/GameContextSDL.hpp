
#pragma once

#include <SDL2/SDL.h>

#include "core/GameContext.hpp"
#include "core/impl/WindowSDL.hpp"

class GameContextSDL : public GameContext
{
public:
    GameContextSDL();
    ~GameContextSDL();

    void process_events();
};