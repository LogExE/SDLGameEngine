
#pragma once

#include "interfaces/Drawable.hpp"

class Game;

class GameState : public Drawable
{
protected:
    //сохраняем экземпляр игры в качестве поля класса
    Game &m_game;
public:
    GameState(Game &game);
    virtual ~GameState();

    //метод для запуска поведения, соотв-щего состоянию игры
    virtual void begin(float deltaTime) = 0;
    //отрисовка состояния
    virtual void draw(SDL_Renderer *rnd) = 0;
};