#include "Game.hpp"

#include "GameStateMain.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Game::Game()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    m_wnd = SDL_CreateWindow("mario", 500, 500, 1024, 768, SDL_WINDOW_SHOWN);
    m_rnd = SDL_CreateRenderer(m_wnd, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderSetLogicalSize(m_rnd, 256, 240);

    m_cur_state = std::make_unique<GameStateMain>(*this);
}

Game::~Game()
{
    SDL_DestroyRenderer(m_rnd);
    SDL_DestroyWindow(m_wnd);
    IMG_Quit();
    SDL_Quit();
}

void Game::run()
{
    running = true;
    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    double deltaTime = 0;

    while (running)
    {
        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();
        deltaTime = (double)((NOW - LAST)*1000 / (double)SDL_GetPerformanceFrequency() );
        SDL_Event ev;
        while (SDL_PollEvent(&ev))
        {
            if (ev.type == SDL_QUIT)
                running = false;
        }
        m_cur_state->begin(deltaTime);
        m_cur_state->draw(m_rnd);
    }
}

void Game::set_state(std::unique_ptr<GameState> state)
{
    SDL_Log("Switching state and clearing textures!");
    m_txtrs.clear();
    m_cur_state = std::move(state);
}

SDL_Texture *Game::get_texture(const std::string &name)
{
    if (m_txtrs.find(name) == m_txtrs.end())
    {
        m_txtrs[name] = IMG_LoadTexture(m_rnd, (ASSETS_FOLDER + "/" + name).c_str());
        if (!m_txtrs[name])
            SDL_Log("Failed to load %s", name.c_str());
    }
    return m_txtrs[name];
}
