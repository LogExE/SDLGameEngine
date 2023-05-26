
#pragma once

#include "interfaces/GameState.hpp"

class GameStateMain : public GameState
{
private:
    
public:
    GameStateMain(Game &game);

    void draw(Graphics &graphics);
    void next();
    void prev();
};