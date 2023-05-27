
#pragma once

#include <string>
#include <map>
#include <memory>

struct SDL_Texture;
struct SDL_Window;
struct SDL_Renderer;

class GameState;
class InputProvider;

class Game
{
private:
    std::unique_ptr<GameState> m_cur_state;
    SDL_Window *m_wnd;
    SDL_Renderer *m_rnd;
    bool running = false;
    std::map<std::string, SDL_Texture*> m_txtrs;
    std::shared_ptr<InputProvider> m_keyboard;

public:
    Game();
    ~Game();
    void run();
    
    void set_state(std::unique_ptr<GameState> state);

    std::shared_ptr<InputProvider> get_keyboard();

    SDL_Texture* get_texture(const std::string &name);
    inline const static std::string ASSETS_FOLDER = "assets";
};