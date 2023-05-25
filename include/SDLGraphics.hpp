
#pragma once

#include <SDL2/SDL.h>

#include "Graphics.hpp"

class SDLGraphics : Graphics
{
private:
    SDL_Renderer *m_rendr;
public:
    SDLGraphics(SDL_Window *wnd);
    ~SDLGraphics();

    void toggle_vsync();
    void set_draw_color(Color color);

    void draw_line(Line line);
    void draw_text(const std::string &msg, Vector2 pos);
    //virtual void draw_sprite() = 0;

    void present();
    void clear(Color cl_color = Color::white);
};