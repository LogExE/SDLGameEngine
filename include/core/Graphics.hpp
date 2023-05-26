
#pragma once

#include <string>
#include <tuple>

#include <SDL2/SDL.h>

#include "primitives/Vector2.hpp"
#include "primitives/Color.hpp"
#include "primitives/Line.hpp"

class Graphics
{
private:
    SDL_Renderer *m_rendr;
    bool m_vsync;
    Color m_draw_col;
public:
    Graphics(SDL_Window *wnd);
    ~Graphics();

    void toggle_vsync();
    void set_vsync(bool vsync);
    bool get_vsync();
    void set_draw_color(Color color);

    

    void draw_line(Line line);
    void draw_text(const std::string &msg, Vector2 pos);
    //virtual void draw_sprite() = 0;

    void present();
    void clear(Color cl_color = Color::white);
};