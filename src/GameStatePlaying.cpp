#include "GameStatePlaying.hpp"

GameStatePlaying::GameStatePlaying(Game &game, const std::string &lvl) : GameState(game)
{

}

void GameStatePlaying::begin()
{
        plr.update(deltaTime); 
        gr.update(deltaTime);

        SDL_RenderClear(m_rnd);

        plr.draw(m_rnd);
        gr.draw(m_rnd);

        SDL_RenderPresent(m_rnd);
}
