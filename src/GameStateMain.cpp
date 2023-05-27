#include "GameStateMain.hpp"

#include <memory>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "Game.hpp"
#include "GameStatePlaying.hpp"
#include "interfaces/InputProvider.hpp"

GameStateMain::GameStateMain(Game &game) : GameState(game)
{
    m_text = m_game.get_text("A game!", Game::DEF_FONT, Game::DEF_FONTSIZE, SDL_Color{0, 0, 0, 255});
}

GameStateMain::~GameStateMain()
{
    SDL_DestroyTexture(m_text);
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
    SDL_Rect dest{128 - 50, 80, 50, 30};
    SDL_RenderCopy(rnd, m_text, nullptr, &dest);
    SDL_RenderPresent(rnd);
}
