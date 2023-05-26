
#pragma once

#include "interfaces/Drawable.hpp"
#include "interfaces/Sprite.hpp"

class GameObject : public Drawable
{
protected:
    float x, y;
public:
    GameObject();
    virtual ~GameObject() = 0;

    virtual void set_pos(float x, float y);
    virtual void update() = 0;
};