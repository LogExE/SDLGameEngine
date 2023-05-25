
#include "WindowSDL.hpp"

WindowSDL::WindowSDL()
{
    m_wnd = SDL_CreateWindow(DEFAULT_TITLE.c_str(), 0, 0, 800, 600, SDL_WINDOW_SHOWN);
    m_graphics = std::make_unique<GraphicsSDL>(m_wnd);
}

WindowSDL::~WindowSDL()
{
    SDL_DestroyWindow(m_wnd);
}

void WindowSDL::change_title(const std::string &title)
{
}
