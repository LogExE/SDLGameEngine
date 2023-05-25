
#pragma once

#include <string>
#include <tuple>

#include "primitives/Vector2.hpp"
#include "primitives/Color.hpp"
#include "primitives/Line.hpp"

class Graphics
{
protected:
    bool m_vsync;
    Color m_draw_col;
public:
    Graphics() : m_draw_col(Color::white), m_vsync(false) {}
    virtual ~Graphics() = 0;

    virtual void toggle_vsync()
    {
        m_vsync ^= 1;
    }
    bool get_vsync()
    {
        return m_vsync;
    }
    virtual void set_draw_color(Color color)
    {
        m_draw_col = color;
    }

    virtual void draw_line(Line line) = 0;
    virtual void draw_text(const std::string &msg, Vector2 pos) = 0;
    //virtual void draw_sprite() = 0;

    virtual void present() = 0;
    virtual void clear(Color cl_color = Color::white) = 0;
};