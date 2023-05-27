#include "Game.hpp"

#include "GameStateMain.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "KeyboardProvider.hpp"

Game::Game()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    SDLNet_Init();
    m_wnd = SDL_CreateWindow("mario", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, SDL_WINDOW_SHOWN);
    m_rnd = SDL_CreateRenderer(m_wnd, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderSetLogicalSize(m_rnd, 256, 240);

    m_def_font = TTF_OpenFont(DEF_FONT.c_str(), DEF_FONTSIZE);

    m_keyboard = std::make_shared<KeyboardProvider>();

    m_cur_state = std::make_unique<GameStateMain>(*this);
}

Game::~Game()
{
    clear_textures();
    SDL_DestroyRenderer(m_rnd);
    SDL_DestroyWindow(m_wnd);

    SDLNet_Quit();
    TTF_Quit();
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
        deltaTime = (double)((NOW - LAST) * 1000 / (double)SDL_GetPerformanceFrequency());
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
    m_cur_state = std::move(state);
}

void Game::clear_textures()
{
    for (auto kv : m_txtrs)
        SDL_DestroyTexture(kv.second);
    m_txtrs.clear();
}

std::shared_ptr<InputProvider> Game::get_keyboard()
{
    return m_keyboard;
}

void Game::set_net_params(bool host, const std::string &ip, int port)
{
    m_host = host;
    m_ip = ip;
    m_port = port;
    IPaddress addr;
    SDLNet_ResolveHost(&addr, m_ip.c_str(), port);
    m_sock = SDLNet_UDP_Open(port);
    m_chan = SDLNet_UDP_Bind(m_sock, -1, &addr);
}

UDPsocket &Game::get_socket()
{
    return m_sock;
}

int Game::get_chan()
{
    return m_chan;
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

SDL_Texture *Game::get_text(const std::string &msg, const std::string &font, int size, SDL_Color color)
{
    if (font != DEF_FONT || size != DEF_FONTSIZE)
        return nullptr;
    SDL_Surface *surf = TTF_RenderText_Blended(m_def_font, msg.c_str(), color);
    SDL_Texture *ret = SDL_CreateTextureFromSurface(m_rnd, surf);
    SDL_FreeSurface(surf);
    return ret;
}
