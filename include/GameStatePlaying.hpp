
#pragma once

#include <vector>
#include <string>
#include <memory>
#include <SDL2/SDL_net.h>

#include "interfaces/GameState.hpp"
#include "interfaces/InputProvider.hpp"
#include "GameObject.hpp"
#include "Block.hpp"

class ArrayInputProvider;

class GameStatePlaying : public GameState
{
private:
    //список обычный объектов
    std::vector<std::unique_ptr<GameObject>> objs;
    //список блоков
    std::vector<std::vector<std::unique_ptr<Block>>> blocks;

    //сетевой компонент ввода для второго игрока
    std::shared_ptr<ArrayInputProvider> m_netprov;
    //пакеты для общения по сети
    UDPpacket *m_packet_send, *m_packet_recv;
    
public:
    GameStatePlaying(Game &game, const std::string &lvl);
    ~GameStatePlaying();

    void begin(float deltaTime);

    void draw(SDL_Renderer *rnd);

    //есть ли блок на позиции 
    bool has_block(float x, float y);

    Game& get_game();

    inline const static std::string LEVEL_FOLDER = "level";
    //максимальные размеры игрового мира
    const static int MAX_LVL_W = 500;
    const static int MAX_LVL_H = 100;
};