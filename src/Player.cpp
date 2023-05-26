#include "Player.hpp"

Player::Player(Game &game)
{
    add_animation(ANIM_IDLE, Animation(game.get_texture("mario_idle.png"), 1));
    add_animation(ANIM_WALK, Animation(game.get_texture("mario_walk.png"), 3).set_time_per_tick(300));
    add_animation(ANIM_JUMP, Animation(game.get_texture("mario_jump.png"), 1));
    //set_animation(ANIM_WALK);
}

void Player::update(float dt)
{
    GameObject::update(dt);
    x += 0.01 * dt * MAX_XSPEED;
}
