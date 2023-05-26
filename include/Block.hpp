
#pragma once

class Block
{
public:
    Block();
    virtual ~Block() = 0;

    const static int WIDTH = 16;
    const static int HEIGHT = 16;
};