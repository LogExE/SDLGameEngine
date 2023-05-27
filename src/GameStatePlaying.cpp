#include "GameStatePlaying.hpp"

#include "GameObject.hpp"
#include "Player.hpp"
#include "GroundBlock.hpp"
#include "Game.hpp"

GameStatePlaying::GameStatePlaying(Game &game, const std::string &lvl) : GameState(game)
{
    for (int i = 0; i < 10; ++i)
    {
        auto new_block = std::make_unique<GroundBlock>(m_game);
        new_block->set_pos(i * 16, 100);
        objs.push_back(std::move(new_block));
    }
    objs.push_back(std::make_unique<Player>(m_game, m_game.get_keyboard()));
}

void GameStatePlaying::begin(float deltaTime)
{
    for (auto &obj : objs)
        obj->update(deltaTime); 
}

void GameStatePlaying::draw(SDL_Renderer *rnd)
{
    SDL_SetRenderDrawColor(rnd, 255, 255, 255, 255);
    SDL_RenderClear(rnd);

    for (auto &obj : objs)
        obj->draw(rnd); 

    SDL_RenderPresent(rnd);
}
