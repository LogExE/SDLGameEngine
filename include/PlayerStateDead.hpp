
#pragma once

#include "interfaces/PlayerState.hpp"

class Player;

class PlayerStateDead : public PlayerState
{
private:
    float m_timer = 0;

public:
    PlayerStateDead(Player &plr);

    void update(float dt);

    constexpr static float DEAD_UP = 0.5;
    constexpr static float DELAY = 500;
    constexpr static float DEAD_UP_TIME = DELAY + 200;
    constexpr static float DEAD_TIME = DEAD_UP_TIME + 2000;
};
