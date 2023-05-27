
#pragma once

#include "interfaces/GameState.hpp"

class GameStateMain : public GameState
{
private:
    
public:
    GameStateMain(Game &game);

    void begin(float deltaTime);
    void draw(SDL_Renderer *rnd);
};