
#pragma once

class SDL_Renderer;

class Drawable
{
public:
    Drawable();
    virtual ~Drawable();

    virtual void draw(SDL_Renderer *rnd) = 0;
};