#include "Player.hpp"

#include <algorithm>

#include "GameStatePlaying.hpp"
#include "Game.hpp"
#include "Block.hpp"
#include "interfaces/InputProvider.hpp"

Player::Player(GameStatePlaying &game_state, std::shared_ptr<InputProvider> input) : GameObject(game_state)
{
    m_input = input;
    Game &game = game_state.get_game();
    add_animation(ANIM_IDLE, Animation(game.get_texture("mario_idle.png"), 1));
    add_animation(ANIM_WALK, Animation(game.get_texture("mario_walk.png"), 3).set_time_per_tick(300));
    add_animation(ANIM_JUMP, Animation(game.get_texture("mario_jump.png"), 1));
    m_col_w = 16;
    m_col_h = 12;
    //set_animation(ANIM_WALK);
}

void Player::update(float dt)
{
    GameObject::update(dt);

    //TODO: remake, works bad on small fps
    if (m_input->check_input(Input::Left))
    {
        if (xsp > 0)
            xsp -= X_DEC * dt;
        else
            xsp -= X_ACC * dt;
    }
    else if (m_input->check_input(Input::Right))
    {
        if (xsp < 0)
            xsp += X_DEC * dt;
        else
            xsp += X_ACC * dt;
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

    if (!m_grounded)
        ysp += Y_ACC * dt;
    else
        ysp = 0;
    ysp = std::max(std::min(ysp, MAX_YSPEED), -MAX_YSPEED);

    x += xsp * dt;
    y += ysp * dt;

    handle_collisions();
}

void Player::handle_collisions()
{
    if (m_game_state.has_block(x, y + m_col_h) || m_game_state.has_block(x + m_col_w, y + m_col_h))
        m_grounded = true;
    else m_grounded = false;
}
