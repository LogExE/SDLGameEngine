
#pragma once

#include <string>

#include "GameContext.hpp"

class Game
{
private:
    std::unique_ptr<GameContext> m_gctx;

public:
    Game(std::unique_ptr<GameContext> window);
    void run();
    
};