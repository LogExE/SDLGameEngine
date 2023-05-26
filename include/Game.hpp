
#pragma once

#include <string>

#include "GameContext.hpp"
#include "GameState.hpp"

class Game
{
private:
    std::unique_ptr<GameContext> m_gctx;
    std::unique_ptr<GameState> m_cur_state;

public:
    Game(std::unique_ptr<GameContext> gctx);
    void run();
    
    void setState(std::unique_ptr<GameState> state)
    {
        m_cur_state = std::move(state);
    }
};