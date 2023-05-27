
#pragma once

#include "interfaces/Drawable.hpp"

class Game;

class GameState : public Drawable
{
protected:
    Game &m_game;
public:
    GameState(Game &game);
    virtual ~GameState();

    virtual void begin(float deltaTime) = 0;

    virtual void draw(SDL_Renderer *rnd) = 0;
};