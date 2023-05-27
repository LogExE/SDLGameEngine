#include "GameStateMain.hpp"

#include <memory>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "Game.hpp"
#include "GameStatePlaying.hpp"
#include "interfaces/InputProvider.hpp"


GameStateMain::GameStateMain(Game &game) : GameState(game)
{
    test_texture = m_game.get_text("Test!", Game::DEF_FONT, Game::DEF_FONTSIZE, SDL_Color{0, 0, 0, 255});
}

GameStateMain::~GameStateMain()
{
    SDL_DestroyTexture(test_texture);
}

void GameStateMain::begin(float deltaTime)
{
    if (m_game.get_keyboard()->check_input(Input::Jump))
        m_game.set_state(std::make_unique<GameStatePlaying>(m_game, "<placeholder>"));
}

void GameStateMain::draw(SDL_Renderer *rnd)
{
    SDL_SetRenderDrawColor(rnd, 255, 255, 255, 255);
    SDL_RenderClear(rnd);
    SDL_Rect dest{64, 60, 256 - 128, 240 - 120};
    SDL_RenderCopy(rnd, test_texture, nullptr, &dest);
    SDL_RenderPresent(rnd);
}
