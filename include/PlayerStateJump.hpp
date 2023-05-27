
#pragma once

#include "PlayerStateDef.hpp"

class PlayerStateJump : public PlayerStateDef
{
private:
    float m_jumptime = 0;
public:
    PlayerStateJump(Player &plr);

    void update(float dt);

    constexpr static float JMP_TIME = 500;
    constexpr static float JMP_SPEED = 0.1;
};