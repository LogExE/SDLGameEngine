
#pragma once

#include <string>

#include "Graphics.hpp"
#include <memory>

class Window
{
private:
    std::string m_title;
    SDL_Window *m_wnd;
    Graphics m_graphics;
public:
    inline const static std::string DEFAULT_TITLE = "";
    Window();
    ~Window();

    void change_title(const std::string &title);

    std::string get_title();
    Graphics& get_graphics();
};