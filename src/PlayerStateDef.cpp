#include "PlayerStateDef.hpp"

#include "Player.hpp"
#include "interfaces/InputProvider.hpp"
#include "PlayerStateJump.hpp"
#include "PlayerStateDead.hpp"

PlayerStateDef::PlayerStateDef(Player &plr) : PlayerState(plr)
{
}

PlayerStateDef::~PlayerStateDef()
{
}

void PlayerStateDef::update(float dt)
{
    //смена анимации
    if (abs(xsp) > 1e-6)
    {
        m_plr.set_animation(Player::ANIM_WALK);
        m_plr.get_current_animation().set_time_per_tick(8 / abs(xsp));
    }
    else
        m_plr.set_animation(Player::ANIM_IDLE);

    if (m_grounded && m_plr.m_input->check_input(Input::Jump))
    { //игрок прыгнул
        auto jump = std::make_unique<PlayerStateJump>(m_plr);
        jump->set_speeds(xsp, ysp);
        m_plr.change_state(std::move(jump));
    }
    base_move(dt);
}

void PlayerStateDef::base_move(float dt)
{
    //проверка ввода и наличия блоков сбоку
    if (m_plr.m_input->check_input(Input::Left) && !m_plr.brick_left_col())
    {
        if (xsp > 0)
            xsp -= X_DEC * dt;
        else
            xsp -= X_ACC * dt;
        m_plr.m_flipped = true;
    }
    else if (m_plr.m_input->check_input(Input::Right) && !m_plr.brick_right_col())
    {
        if (xsp < 0)
            xsp += X_DEC * dt;
        else
            xsp += X_ACC * dt;
        m_plr.m_flipped = false;
    }
    else //если игрок ничего не нажал - снижаем его скорость
    {
        if (std::abs(xsp) <= 2 * X_DEC)
            xsp = 0;
        else if (xsp > 0)
            xsp -= X_DEC * dt;
        else if (xsp < 0)
            xsp += X_DEC * dt;
    }

    if (m_grounded)
        ysp = 0;
    else //игрок падает
        ysp += Y_ACC * dt;

    set_speeds(xsp, ysp);
    //обновление позиции
    m_plr.x += xsp * dt;
    m_plr.y += ysp * dt;

    if (m_plr.brick_down_col())
        m_grounded = true;
    else
        m_grounded = false;
    //при нажатии кнопки X игрок переходит в состояние "умер"
    if (m_plr.m_input->check_input(Input::Action))
        m_plr.change_state(std::make_unique<PlayerStateDead>(m_plr));
}

void PlayerStateDef::set_speeds(float xsp, float ysp)
{
    this->xsp = std::max(std::min(xsp, MAX_XSPEED), -MAX_XSPEED);
    this->ysp = ysp = std::max(std::min(ysp, MAX_YSPEED), -MAX_YSPEED);
}
