
#pragma once

#include "GameObject.hpp"

class Block : public GameObject
{
public:
    Block();
    virtual ~Block() = 0;

    const static int WIDTH = 16;
    const static int HEIGHT = 16;

    
};