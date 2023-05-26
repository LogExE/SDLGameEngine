
#pragma once

#include "Drawable.hpp"
class Game;

class GameState : public Drawable
{
protected:
    Game &m_game;
public:
    GameState(Game &game) : m_game(game) {}
    virtual ~GameState() {};

    virtual void begin() = 0;

    virtual void draw(SDL_Renderer *rnd) = 0;
};