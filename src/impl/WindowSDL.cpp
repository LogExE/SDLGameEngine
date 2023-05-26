
#include "core/impl/WindowSDL.hpp"

WindowSDL::WindowSDL()
{
    m_wnd = SDL_CreateWindow(DEFAULT_TITLE.c_str(), 400, 400, 800, 600, SDL_WINDOW_SHOWN);
    m_graphics = std::make_unique<GraphicsSDL>(m_wnd);
}

WindowSDL::~WindowSDL()
{
    SDL_DestroyWindow(m_wnd);
}

void WindowSDL::change_title(const std::string &title)
{
    SDL_SetWindowTitle(m_wnd, title.c_str());
}
