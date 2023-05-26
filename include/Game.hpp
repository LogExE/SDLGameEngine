
#pragma once

#include <string>

#include "core/GameContext.hpp"
#include "interfaces/GameState.hpp"

class Game
{
private:
    GameContext m_gctx;
    std::unique_ptr<GameState> m_cur_state;

public:
    Game();
    void run();
    
    void setState(std::unique_ptr<GameState> state)
    {
        m_cur_state = std::move(state);
    }
};