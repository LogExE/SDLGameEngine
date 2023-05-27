#include "GameStateMain.hpp"

#include <memory>

#include <SDL2/SDL.h>

#include "Game.hpp"
#include "GameStatePlaying.hpp"
#include "interfaces/InputProvider.hpp"


GameStateMain::GameStateMain(Game &game) : GameState(game)
{
    test_texture = m_game.get_texture("test.png");
}

void GameStateMain::begin(float deltaTime)
{
    if (m_game.get_keyboard()->check_input(Input::Jump))
        m_game.set_state(std::make_unique<GameStatePlaying>(m_game, "test"));
}

void GameStateMain::draw(SDL_Renderer *rnd)
{
    SDL_SetRenderDrawColor(rnd, 255, 255, 255, 255);
    SDL_RenderClear(rnd);
    SDL_RenderCopy(rnd, test_texture, nullptr, nullptr);
    SDL_RenderPresent(rnd);
}
