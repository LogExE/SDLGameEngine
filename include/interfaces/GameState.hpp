
#pragma once

class Game;

class GameState
{
private:
    Game &m_game;
public:
    GameState(Game &game) : m_game(game) {}
    virtual ~GameState() = 0;

    virtual void next() = 0;
    virtual void prev() = 0;
};