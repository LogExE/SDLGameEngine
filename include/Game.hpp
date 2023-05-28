
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
    //указатель на состояние игры
    std::unique_ptr<GameState> m_cur_state;
    //окно игры и связанный с ним "отрисовщик"
    SDL_Window *m_wnd;
    SDL_Renderer *m_rnd;
    //флаг: нужно ли продолжать исполнение?
    //(не вышел ли пользователь)
    bool running = false;
    //хранилище текстур. можно получить произвольную по названию
    std::map<std::string, SDL_Texture*> m_txtrs;
    //стандартный компонент ввода
    std::shared_ptr<InputProvider> m_keyboard;
    //шрифт приложения
    TTF_Font *m_def_font;

    //сетевые параметры
    std::string m_ip;
    int m_port;
    //сокет типа UDP для отправки и принятия пакетов
    UDPsocket m_sock;
    //номер канала, по которому идет связь
    int m_chan;

public:
    Game();
    ~Game();
    void run();
    
    void set_state(std::unique_ptr<GameState> state);
    //метод выгрузки имеющихся текстур из памяти
    void clear_textures();

    std::shared_ptr<InputProvider> get_keyboard();

    void set_net_params(const std::string &ip, int port);
    UDPsocket& get_socket();
    int get_chan();

    //методы для загрузки текстур и получения текстовых сообщений
    SDL_Texture* get_texture(const std::string &name);
    SDL_Texture* get_text(const std::string &msg, const std::string &font, int size, SDL_Color color);
    //константы: папка с текстурами, параметры шрифта
    inline const static std::string ASSETS_FOLDER = "assets";
    inline const static std::string DEF_FONT = "Anonymous.ttf";
    const static int DEF_FONTSIZE = 28;
};