
#pragma once

#include "interfaces/GameState.hpp"

#include <SDL2/SDL_net.h>

struct SDL_Texture;

class GameStateMain : public GameState
{
private:
    SDL_Texture *m_text;
    UDPpacket *m_packet;
    int knocked = 0;
public:
    GameStateMain(Game &game);
    ~GameStateMain();

    void begin(float deltaTime);
    void draw(SDL_Renderer *rnd);
};