
#pragma once

#include <SDL2/SDL.h>

#include <map>
#include <string>

#include "interfaces/Drawable.hpp"
#include "Animation.hpp"

class Sprite : public Drawable
{
private:
    std::map<std::string, Animation> anims;
    int m_ticks;
public:
    Sprite();

    void set_animation(const std::string &name);
    void add_animation(const std::string &name, Animation anim);
    void set_speed(int speed);
    void draw(SDL_Renderer *rnd);
};