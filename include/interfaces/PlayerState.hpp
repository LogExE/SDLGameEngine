
#pragma once

class Player;

class PlayerState
{
protected:
    Player &m_plr;
public:
    PlayerState(Player &plr);
    virtual ~PlayerState();

    virtual void update(float dt) = 0;
};
