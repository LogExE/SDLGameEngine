
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