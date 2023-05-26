
#pragma once

#include "SDL2/SDL.h"

#include <memory>

#include "core/Window.hpp"
#include "core/impl/GraphicsSDL.hpp"

class WindowSDL : public Window
{
private:
    SDL_Window *m_wnd;
public:
    WindowSDL();
    ~WindowSDL();

    void change_title(const std::string &title);
};