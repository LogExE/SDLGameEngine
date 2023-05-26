#include "Game.hpp"

Game::Game()
{
}

void Game::run()
{
    Window &window = m_gctx.get_window();
    Graphics &graphics = window.get_graphics();
    graphics.set_vsync(true);
    window.change_title("haha");
    while (m_gctx.is_running())
    {
        m_gctx.process_events();
        graphics.clear();
        graphics.draw_line({{0, 0}, {500, 500}});
        graphics.present();
    }
}
