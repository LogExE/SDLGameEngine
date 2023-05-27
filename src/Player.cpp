#include "Player.hpp"

#include "Game.hpp"
#include "interfaces/InputProvider.hpp"

Player::Player(Game &game, std::shared_ptr<InputProvider> input)
{
    m_input = input;
    add_animation(ANIM_IDLE, Animation(game.get_texture("mario_idle.png"), 1));
    add_animation(ANIM_WALK, Animation(game.get_texture("mario_walk.png"), 3).set_time_per_tick(300));
    add_animation(ANIM_JUMP, Animation(game.get_texture("mario_jump.png"), 1));
    //set_animation(ANIM_WALK);
}

void Player::update(float dt)
{
    GameObject::update(dt);
    
    if (m_input->check_input(Input::Left))
        x -= MAX_XSPEED * dt;
    if (m_input->check_input(Input::Right))
        x += MAX_XSPEED * dt;
}
