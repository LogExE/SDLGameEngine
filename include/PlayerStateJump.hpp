
#pragma once

#include "PlayerStateDef.hpp"

class PlayerStateJump : public PlayerStateDef
{
private:
    //текущее время прыжка
    float m_jumptime = 0;
public:
    PlayerStateJump(Player &plr);

    void update(float dt);

    //максимальное время прыжка
    constexpr static float JMP_TIME = 500;
    //скорость прыжка
    constexpr static float JMP_SPEED = 0.1;
};