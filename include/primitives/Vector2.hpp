
#pragma once

#include <cmath>

class Vector2
{
public:
    float x, y;

    Vector2()
    {
        x = y = 0;
    }
    Vector2(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    float length() 
    {
        return sqrt(x * x + y * y);
    }
    Vector2& operator+=(Vector2 other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }
    Vector2 operator+(Vector2 other)
    {
        return Vector2() += other;
    }
};