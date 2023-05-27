#include "KeyboardProvider.hpp"

#include <SDL2/SDL.h>

KeyboardProvider::KeyboardProvider()
{
    keys = SDL_GetKeyboardState(nullptr);
}

bool KeyboardProvider::check_input(Input inp)
{
    switch (inp)
    {
    case Input::Up:
        return keys[SDL_SCANCODE_W];
        break;
    case Input::Down:
        return keys[SDL_SCANCODE_S];
        break;
    case Input::Left:
        return keys[SDL_SCANCODE_A];
        break;
    case Input::Right:
        return keys[SDL_SCANCODE_D];
        break;
    case Input::Jump:
        return keys[SDL_SCANCODE_SPACE];
        break;
    case Input::Action:
        return keys[SDL_SCANCODE_X];
        break;
    default:
        42;
        // probably unachievable
    }
}