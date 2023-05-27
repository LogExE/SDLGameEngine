#include "GroundBlock.hpp"

#include "Game.hpp"
#include "GameStatePlaying.hpp"

GroundBlock::GroundBlock(GameStatePlaying &game_state) : Block(game_state)
{
    add_animation(ANIM_IDLE, Animation(game_state.get_game().get_texture("ground_tile.png"), 1));
}