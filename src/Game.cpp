#include "Game.hpp"

Game::Game(std::unique_ptr<GameContext> gctx)
{
    m_gctx = std::move(gctx);
}

void Game::run()
{
    Window &window = m_gctx->get_window();
    window.change_title("haha");
    Graphics &graphics = window.get_graphics();
    graphics.clear();
    graphics.draw_line({{0, 0}, {500, 500}});
    graphics.present();
}
