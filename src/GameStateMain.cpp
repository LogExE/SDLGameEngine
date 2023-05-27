#include "GameStateMain.hpp"

#include <memory>

#include <SDL2/SDL.h>

#include "Game.hpp"
#include "GameStatePlaying.hpp"
#include "GameObject.hpp"


GameStateMain::GameStateMain(Game &game) : GameState(game)
{
}

void GameStateMain::begin(float deltaTime)
{
    m_game.set_state(std::make_unique<GameStatePlaying>(m_game, "test"));
}

void GameStateMain::draw(SDL_Renderer *rnd)
{
    SDL_SetRenderDrawColor(rnd, 255, 255, 255, 255);
    SDL_RenderClear(rnd);
    SDL_RenderPresent(rnd);
}
