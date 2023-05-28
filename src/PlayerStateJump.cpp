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
    //если время прыжка не истекло и игрок еще хочет прыгнуть
    if (m_jumptime <= JMP_TIME && m_plr.m_input->check_input(Input::Jump))
        ysp = -JMP_SPEED;

    //вызов общего поведения игрока, определенного в PlayerStateDef
    base_move(dt);
    //переход в состояние по умолачнию по приземлении
    if (m_grounded)
    {
        auto def_state = std::make_unique<PlayerStateDef>(m_plr);
        //не забываем передать скорости новому состоянию
        //иначе игрок будет останавливаться
        def_state->set_speeds(xsp, ysp);
        m_plr.change_state(std::move(def_state));
    }
}
