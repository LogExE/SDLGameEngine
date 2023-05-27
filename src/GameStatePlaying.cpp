#include "GameStatePlaying.hpp"

#include "GameObject.hpp"
#include "Player.hpp"
#include "Block.hpp"
#include "GroundBlock.hpp"
#include "Game.hpp"

GameStatePlaying::GameStatePlaying(Game &game, const std::string &lvl) : GameState(game)
{
    blocks.resize(MAX_LVL_H);
    for (int i = 0; i < MAX_LVL_H; ++i)
        blocks[i].resize(MAX_LVL_W);
    for (int i = 0; i < 10; ++i)
    {
        auto new_block = std::make_unique<GroundBlock>(*this);
        new_block->set_pos(i * Block::SIZE, 100);
        blocks[100 / Block::SIZE][i] = std::move(new_block);
    }
    objs.push_back(std::make_unique<Player>(*this, m_game.get_keyboard()));
}

void GameStatePlaying::begin(float deltaTime)
{
    for (auto &obj : objs)
        obj->update(deltaTime);

    for (auto &blks : blocks)
        for (auto &blk : blks)
            if (blk)
                blk->update(deltaTime);
}

void GameStatePlaying::draw(SDL_Renderer *rnd)
{
    SDL_SetRenderDrawColor(rnd, 92, 148, 252, 255);
    SDL_RenderClear(rnd);

    for (auto &obj : objs)
        obj->draw(rnd);
    for (auto &blks : blocks)
        for (auto &blk : blks)
            if (blk)
                blk->draw(rnd);

    SDL_RenderPresent(rnd);
}

bool GameStatePlaying::has_block(float x, float y)
{
    return blocks[round(y) / Block::SIZE][round(x) / Block::SIZE] != nullptr;
}

Game &GameStatePlaying::get_game()
{
    return m_game;
}
