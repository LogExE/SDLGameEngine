
#pragma once

#include "Block.hpp"

enum BrickType
{
    Usual,
    Mushroomy,
    Coiny
};

class Brick
{
private:
    int m_remaining = 0;
public:
    Brick(BrickType type, int remaining = 0);
    ~Brick();
};