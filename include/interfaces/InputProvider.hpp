
#pragma once

#include <map>
#include <SDL2/SDL_scancode.h>

enum class Input
{
    Up,
    Down,
    Left,
    Right,
    Jump,
    Action
};

class InputProvider
{
public:
    InputProvider();
    virtual ~InputProvider();

    //получить состояние ввода
    //своего рода метод execute паттерна Command
    virtual bool check_input(Input inp) = 0;
};