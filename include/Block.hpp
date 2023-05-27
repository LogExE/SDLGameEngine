
#pragma once

#include "GameObject.hpp"

class Block : public GameObject
{
private:
    
public:
    Block();

    virtual void on_collide(GameObject &obj) {}

    const static int SIZE = 16;
};
