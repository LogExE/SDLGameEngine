
#pragma once

#include "Drawable.hpp"

class Game;

class GameState : public Drawable
{
private:
    Game &m_game;
public:
    GameState(Game &game) : m_game(game) {}
    virtual ~GameState() {};

    virtual void next() = 0;
    virtual void prev() = 0;

    virtual void draw(Graphics &graphics) = 0;
};