
#pragma once

#include <SDL2/SDL.h>

#include "core/Graphics.hpp"

class GraphicsSDL : public Graphics
{
private:
    SDL_Renderer *m_rendr;
public:
    GraphicsSDL(SDL_Window *wnd);
    ~GraphicsSDL();

    void set_vsync(bool vsync);
    void set_draw_color(Color color);

    void draw_line(Line line);
    void draw_text(const std::string &msg, Vector2 pos);
    //virtual void draw_sprite() = 0;

    void present();
    void clear(Color cl_color = Color::white);
};