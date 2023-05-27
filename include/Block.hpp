
#pragma once

#include "GameObject.hpp"

class Block : public GameObject
{
private:
    
public:
    Block(GameStatePlaying &game_state);

    virtual void draw(SDL_Renderer *rnd);

    virtual void hit();

    const static int SIZE = 16;
};
