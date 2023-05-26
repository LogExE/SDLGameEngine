#pragma once

#include "GameObject.hpp"

class Player : public GameObject
{
private:
    bool grounded = false;
public:
    Player(Game &game);

    void update(float dt);

    constexpr static float MAX_XSPEED = 5;
    constexpr static float MAX_YSPEED = 10;

    inline static const std::string ANIM_IDLE = "idle",
                                    ANIM_WALK = "walk",
                                    ANIM_JUMP = "jump";
};