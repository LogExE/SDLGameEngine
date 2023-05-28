#include "Player.hpp"

#include <algorithm>

#include "GameStatePlaying.hpp"
#include "Game.hpp"
#include "Block.hpp"
#include "interfaces/InputProvider.hpp"
#include "EmptyInputProvider.hpp"
#include "interfaces/GameState.hpp"
#include "PlayerStateDef.hpp"

Player::Player(GameStatePlaying &game_state, float x, float y) : GameObject(game_state)
{
    m_input = std::make_shared<EmptyInputProvider>();
    m_state = std::make_unique<PlayerStateDef>(*this);
    Game &game = game_state.get_game();
    add_animation(ANIM_IDLE, Animation(game.get_texture("mario_idle.png"), 1));
    add_animation(ANIM_WALK, Animation(game.get_texture("mario_walk.png"), 3).set_time_per_tick(300));
    add_animation(ANIM_JUMP, Animation(game.get_texture("mario_jump.png"), 1));
    add_animation(ANIM_DEAD, Animation(game.get_texture("mario_dead.png"), 1));
    m_col_w = COL_W;
    m_col_h = COL_H;
    this->x = x;
    this->y = y;
    spawn_x = x;
    spawn_y = y;
}

void Player::set_input(std::shared_ptr<InputProvider> provider)
{
    m_input = provider;
}

void Player::change_state(std::unique_ptr<PlayerState> state)
{
    m_state = std::move(state);
}

void Player::reset_state()
{
    set_pos(spawn_x, spawn_y);
    change_state(std::make_unique<PlayerStateDef>(*this));
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

bool Player::is_player()
{
    return true;
}

void Player::update(float dt)
{
    GameObject::update(dt);
    m_state->update(dt);
}

void Player::decrease_lifes()
{
    --m_lives;
    if (m_lives == 0)
        m_done = true;
}
