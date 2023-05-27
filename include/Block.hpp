
#pragma once

#include "GameObject.hpp"

class Block : public GameObject
{
private:
    
public:
    Block(GameStatePlaying &game_state);

    virtual void on_collide(GameObject &obj);

    const static int SIZE = 16;
};
