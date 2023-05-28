
#pragma once

#include <SDL2/SDL_net.h>

#include "interfaces/GameState.hpp"

struct SDL_Texture;

class GameStateMain : public GameState
{
private:
    SDL_Texture *m_text;
public:
    GameStateMain(Game &game);
    ~GameStateMain();

    void begin(float deltaTime);
    void draw(SDL_Renderer *rnd);
};