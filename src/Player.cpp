#include "Player.hpp"

#include <algorithm>

#include "GameStatePlaying.hpp"
#include "Game.hpp"
#include "Block.hpp"
#include "interfaces/InputProvider.hpp"
#include "EmptyInputProvider.hpp"

Player::Player(GameStatePlaying &game_state) : GameObject(game_state)
{
    m_input = std::make_shared<EmptyInputProvider>();
    Game &game = game_state.get_game();
    add_animation(ANIM_IDLE, Animation(game.get_texture("mario_idle.png"), 1));
    add_animation(ANIM_WALK, Animation(game.get_texture("mario_walk.png"), 3).set_time_per_tick(300));
    add_animation(ANIM_JUMP, Animation(game.get_texture("mario_jump.png"), 1));
    m_col_w = 16;
    m_col_h = 12;
    // set_animation(ANIM_WALK);
}

void Player::set_input(std::shared_ptr<InputProvider> provider)
{
    m_input = provider;
}

bool Player::brick_left_col()
{
    return m_game_state.has_block(x, y + m_col_h / 2);
}

bool Player::brick_right_col()
{
    return m_game_state.has_block(x + m_col_w, y + m_col_h / 2);
}

bool Player::brick_down_col()
{
    return m_game_state.has_block(x, y + m_col_h) || m_game_state.has_block(x + m_col_w, y + m_col_h);
}

bool Player::brick_up_col()
{
    return m_game_state.has_block(x, y) || m_game_state.has_block(x + m_col_w, y);
}

void Player::update(float dt)
{
    GameObject::update(dt);

    if (m_jumping)
        set_animation(ANIM_JUMP);
    else if (abs(xsp) > 1e-6)
        set_animation(ANIM_WALK);
    else set_animation(ANIM_IDLE);


    // TODO: remake, works bad on small fps
    if (m_input->check_input(Input::Left) && !brick_left_col())
    {
        if (xsp > 0)
            xsp -= X_DEC * dt;
        else
            xsp -= X_ACC * dt;
        m_flipped = true;
    }
    else if (m_input->check_input(Input::Right) && !brick_right_col())
    {
        if (xsp < 0)
            xsp += X_DEC * dt;
        else
            xsp += X_ACC * dt;
        m_flipped = false;
    }
    else
    {
        if (std::abs(xsp) <= 2 * X_DEC)
            xsp = 0;
        else if (xsp > 0)
            xsp -= X_DEC * dt;
        else if (xsp < 0)
            xsp += X_DEC * dt;
    }
    xsp = std::max(std::min(xsp, MAX_XSPEED), -MAX_XSPEED);

    if (m_grounded && !m_jumping)
    {
        if (!m_jumping)
            ysp = 0;
        if (m_input->check_input(Input::Jump))
            m_jumping = true;
    }
    else
    {
        if (m_jumping)
        {
            m_jumptime += dt;
            ysp = -JMP_SPEED;
            if (m_jumptime >= JMP_TIME || !m_input->check_input(Input::Jump))
            {
                m_jumping = false;
                m_jumptime = 0;
            }
        }
        else
            ysp += Y_ACC * dt;
    }

    if (brick_down_col())
        m_grounded = true;
    else
        m_grounded = false;

    ysp = std::max(std::min(ysp, MAX_YSPEED), -MAX_YSPEED);

    x += xsp * dt;
    y += ysp * dt;
}