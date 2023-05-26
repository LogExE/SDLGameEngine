
#include "core/Graphics.hpp"

Graphics::Graphics(SDL_Window *wnd) : m_draw_col(Color::black), m_vsync(false)
{
    m_rendr = SDL_CreateRenderer(wnd, -1, SDL_RENDERER_ACCELERATED);
}

Graphics::~Graphics()
{
    SDL_DestroyRenderer(m_rendr);
}

void Graphics::toggle_vsync()
{
    set_vsync(m_vsync ^= 1);
}

void Graphics::set_vsync(bool vsync)
{
    m_vsync = vsync;
    SDL_RenderSetVSync(m_rendr, m_vsync);
}

bool Graphics::get_vsync()
{
    return m_vsync;
}

void Graphics::set_draw_color(Color color)
{
    m_draw_col = color;
    SDL_SetRenderDrawColor(m_rendr, m_draw_col.r, m_draw_col.g, m_draw_col.b, m_draw_col.alpha);
}

void Graphics::draw_line(Line line)
{
    SDL_RenderDrawLineF(m_rendr, line.begin.x, line.begin.y, line.end.x, line.end.y);
}

void Graphics::draw_text(const std::string &msg, Vector2 pos)
{
}

void Graphics::present()
{
    SDL_RenderPresent(m_rendr);
}

void Graphics::clear(Color cl_color)
{
    Color tmp = m_draw_col;
    set_draw_color(cl_color);
    SDL_RenderClear(m_rendr);
    set_draw_color(tmp);
}
