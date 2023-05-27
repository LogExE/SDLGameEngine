#include "GameStatePlaying.hpp"

#include "GameObject.hpp"
#include "Player.hpp"
#include "GroundBlock.hpp"

GameStatePlaying::GameStatePlaying(Game &game, const std::string &lvl) : GameState(game)
{
    objs.push_back(std::make_unique<Player>(game));
    objs.push_back(std::make_unique<GroundBlock>(game));
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
