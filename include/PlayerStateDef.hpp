
#pragma once

#include "interfaces/PlayerState.hpp"

class PlayerStateDef : public PlayerState
{
protected:
    bool m_grounded = false;
    bool m_big = false;
    bool m_invincible = false;

    float xsp = 0, ysp = 0;

public:
    PlayerStateDef(Player &plr);
    virtual ~PlayerStateDef();

    virtual void update(float dt);
    void base_move(float dt);

    void set_speeds(float xsp, float ysp);

    constexpr static float X_ACC = 0.0002;
    constexpr static float X_DEC = 0.01;
    constexpr static float Y_ACC = 0.005;
    constexpr static float MAX_XSPEED = 0.1;
    constexpr static float MAX_YSPEED = 0.2;

    
};