#include "PlayerStateDead.hpp"

#include "Player.hpp"
#include "PlayerStateDef.hpp"

PlayerStateDead::PlayerStateDead(Player &plr) : PlayerState(plr)
{
    m_plr.set_animation(Player::ANIM_DEAD);
}

void PlayerStateDead::update(float dt)
{
    m_timer += dt;
    if (m_timer <= DELAY)
        return;
    if (m_timer <= DEAD_UP_TIME)
        m_plr.y -= DEAD_UP;
    else if (m_timer <= DEAD_TIME)
        m_plr.y += DEAD_UP;
    else
    {
        m_plr.decrease_lifes();
        m_plr.reset_state();
    }
}
