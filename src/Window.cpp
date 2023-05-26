
#include "core/Window.hpp"

Window::Window() :
    m_wnd(SDL_CreateWindow(DEFAULT_TITLE.c_str(), 400, 400, 800, 600, SDL_WINDOW_SHOWN)),
    m_graphics(m_wnd)
{
}

Window::~Window()
{
    SDL_DestroyWindow(m_wnd);
}

void Window::change_title(const std::string &title)
{
    m_title = title;
    SDL_SetWindowTitle(m_wnd, title.c_str());
}

std::string Window::get_title()
{
    return m_title;
}

Graphics& Window::get_graphics()
{
    return m_graphics;
}