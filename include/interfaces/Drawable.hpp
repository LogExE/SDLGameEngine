
#pragma once

#include <memory>

class Graphics;

class Drawable
{
public:
    Drawable() {}
    virtual ~Drawable() = 0;

    virtual void draw(Graphics &graphics) = 0;
};