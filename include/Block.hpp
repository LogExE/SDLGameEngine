
#pragma once

#include "GameObject.hpp"

class Block : public GameObject
{
public:
    Block(GameStatePlaying &game_state);
    //поведение блока при получении сигнала извне
    virtual void hit();

    virtual void draw(SDL_Renderer *rnd);

    // характерный размер блока
    const static int SIZE = 16;
};
