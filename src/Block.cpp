#include "Block.hpp"

Block::Block(GameStatePlaying &game_state) : GameObject(game_state)
{
    m_col_w = SIZE;
    m_col_h = SIZE;
}

void Block::draw(SDL_Renderer *rnd)
{
    GameObject::draw(rnd);
}

void Block::hit()
{
}