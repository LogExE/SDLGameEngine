#include "PlayerStateJump.hpp"

#include "Player.hpp"
#include "interfaces/InputProvider.hpp"

PlayerStateJump::PlayerStateJump(Player &plr) : PlayerStateDef(plr)
{
    m_plr.set_animation(Player::ANIM_JUMP);
}

void PlayerStateJump::update(float dt)
{
    m_jumptime += dt;
    if (m_jumptime <= JMP_TIME && m_plr.m_input->check_input(Input::Jump))
        ysp = -JMP_SPEED;

    base_move(dt);

    if (m_grounded)
    {
        auto def_state = std::make_unique<PlayerStateDef>(m_plr);
        def_state->set_speeds(xsp, ysp);
        m_plr.change_state(std::move(def_state));
    }
}
