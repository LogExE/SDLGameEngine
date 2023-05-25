
#pragma once

#include "Vector2.hpp"

class Line
{
public:
    Vector2 begin, end;
    Line(Vector2 p1, Vector2 p2) 
    {
        begin = p1;
        end = p2;
    }
    
    float angle()
    {
        throw 42;
    }
};
