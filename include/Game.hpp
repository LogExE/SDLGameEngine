
#pragma once

#include <string>
#include <map>
#include <memory>

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_net.h>

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
    std::shared_ptr<InputProvider> m_netprov;
    TTF_Font *m_def_font;

    bool m_host;
    std::string m_ip;
    int m_port;
    UDPsocket m_sock;
    int m_chan;

public:
    Game();
    ~Game();
    void run();
    
    void set_state(std::unique_ptr<GameState> state);
    void clear_textures();

    std::shared_ptr<InputProvider> get_keyboard();
    std::shared_ptr<InputProvider> get_net_controls();

    void set_net_params(bool host, const std::string &ip, int port);
    UDPsocket& get_socket();
    int get_chan();

    SDL_Texture* get_texture(const std::string &name);
    SDL_Texture* get_text(const std::string &msg, const std::string &font, int size, SDL_Color color);
    inline const static std::string ASSETS_FOLDER = "assets";
    inline const static std::string DEF_FONT = "Anonymous.ttf";
    const static int DEF_FONTSIZE = 28;
};