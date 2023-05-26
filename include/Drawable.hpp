
#pragma once

#include <memory>

#include "Graphics.hpp"

class Drawable
{
public:
    Drawable() {}
    virtual ~Drawable() = 0;

    virtual void draw(std::unique_ptr<Graphics> graphics) = 0;
};