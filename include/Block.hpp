
#pragma once

#include "GameObject.hpp"

class Block : public GameObject
{
public:
    Block(GameStatePlaying &game_state);
    virtual void hit();

    virtual void draw(SDL_Renderer *rnd);

    const static int SIZE = 16;
};
