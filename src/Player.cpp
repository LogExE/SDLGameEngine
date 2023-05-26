#include "Player.hpp"

Player::Player(Game &game)
{
    add_animation(ANIM_IDLE, Animation(game.get_texture("mario_idle.png"), 1));
    add_animation(ANIM_WALK, Animation(game.get_texture("mario_walk.png"), 3));
    add_animation(ANIM_JUMP, Animation(game.get_texture("mario_jump.png"), 1));
}

void Player::update(float dt)
{
    //x += dt * MAX_XSPEED;
}
