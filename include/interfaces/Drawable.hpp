
#pragma once

class SDL_Renderer;

class Drawable
{
public:
    Drawable();
    virtual ~Drawable();

    //метод для отрисовки объекта
    virtual void draw(SDL_Renderer *rnd) = 0;
};