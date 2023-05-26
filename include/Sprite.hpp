
#pragma once

#include <SDL2/SDL.h>

#include <map>
#include <string>

#include "interfaces/Drawable.hpp"
#include "Animation.hpp"

class Sprite
{
private:
    std::map<std::string, Animation> anims;

public:
    Sprite();

    void set_animation(const std::string &name);
    void add_animation(const std::string &name, Animation anim);
    void draw(SDL_Renderer *rnd);
};