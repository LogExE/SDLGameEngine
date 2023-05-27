
#pragma once

#include "interfaces/PlayerState.hpp"

class Player;

class PlayerStateDead : public PlayerState
{
public:
    PlayerStateDead(Player &plr);

    constexpr static float DEAD_UP_TIME = 2000;
    constexpr static float DEAD_TIME = DEAD_UP_TIME + 1000;
};
