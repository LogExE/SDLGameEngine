#include "Block.hpp"

Block::Block(GameStatePlaying &game_state) : GameObject(game_state)
{
    m_col_w = SIZE;
    m_col_h = SIZE;
}

void Block::on_collide(GameObject &obj)
{
}