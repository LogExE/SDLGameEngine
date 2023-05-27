#include "GroundBlock.hpp"

#include "Game.hpp"

GroundBlock::GroundBlock(Game &game)
{
    add_animation(ANIM_IDLE, Animation(game.get_texture("ground_tile.png"), 1));
}