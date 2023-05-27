
#pragma once

#include "interfaces/GameState.hpp"

struct SDL_Texture;

class GameStateMain : public GameState
{
private:
    SDL_Texture *test_texture;
public:
    GameStateMain(Game &game);
    ~GameStateMain();

    void begin(float deltaTime);
    void draw(SDL_Renderer *rnd);
};