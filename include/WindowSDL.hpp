
#pragma once

#include "SDL2/SDL.h"

#include <memory>

#include "Window.hpp"
#include "GraphicsSDL.hpp"

class WindowSDL : public Window
{
private:
    SDL_Window *m_wnd;
public:
    WindowSDL();
    ~WindowSDL();

    void change_title(const std::string &title);
};