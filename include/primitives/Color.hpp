
#pragma once

class Color
{
public:
    int r, g, b, alpha;

    Color(int r, int g, int b, int alpha = Color::MAX_ALPHA)
    {
        this->r = r;
        this->g = g;
        this->b = b;
        this->alpha = alpha;
    }

    const static int MAX_ALPHA = 255;
    const static Color black, white, red, green, blue;
};

const Color Color::black = Color(0, 0, 0);
const Color Color::white = Color(255, 255, 255);
const Color Color::red = Color(255, 0, 0);
const Color Color::green = Color(0, 255, 0);
const Color Color::blue = Color(0, 0, 255);