
#include "core/impl/GraphicsSDL.hpp"

GraphicsSDL::GraphicsSDL(SDL_Window *wnd)
{
    m_rendr = SDL_CreateRenderer(wnd, -1, SDL_RENDERER_ACCELERATED);
}

GraphicsSDL::~GraphicsSDL()
{
    SDL_DestroyRenderer(m_rendr);
}

void GraphicsSDL::set_vsync(bool vsync)
{
    Graphics::set_vsync(vsync);
    SDL_RenderSetVSync(m_rendr, m_vsync);
}

void GraphicsSDL::set_draw_color(Color color)
{
    Graphics::set_draw_color(color);
    SDL_SetRenderDrawColor(m_rendr, m_draw_col.r, m_draw_col.g, m_draw_col.b, m_draw_col.alpha);
}

void GraphicsSDL::draw_line(Line line)
{
    SDL_RenderDrawLineF(m_rendr, line.begin.x, line.begin.y, line.end.x, line.end.y);
}

void GraphicsSDL::draw_text(const std::string &msg, Vector2 pos)
{
}

void GraphicsSDL::present()
{
    SDL_RenderPresent(m_rendr);
}

void GraphicsSDL::clear(Color cl_color)
{
    Color tmp = m_draw_col;
    set_draw_color(cl_color);
    SDL_RenderClear(m_rendr);
    set_draw_color(tmp);
}
