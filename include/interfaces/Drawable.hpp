
#pragma once

#include <memory>

#include <SDL2/SDL.h>

class Drawable
{
public:
    Drawable() {}
    virtual ~Drawable() {};

    virtual void draw(SDL_Renderer *rnd) = 0;
};