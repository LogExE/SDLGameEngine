
#pragma once

#include <string>
#include <map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "interfaces/GameState.hpp"
#include "GameStateMain.hpp"
#include "Player.hpp"
#include "GroundBlock.hpp"

class Game
{
private:
    std::unique_ptr<GameState> m_cur_state;
    SDL_Window *m_wnd;
    SDL_Renderer *m_rnd;
    bool running = false;
    std::map<std::string, SDL_Texture*> m_txtrs;

public:
    Game();
    ~Game();
    void run();
    
    void set_state(std::unique_ptr<GameState> state)
    {
        m_cur_state = std::move(state);
    }

    SDL_Texture* get_texture(const std::string &name);
    inline const static std::string ASSETS_FOLDER = "assets";
};