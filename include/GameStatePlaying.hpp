
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
    std::vector<std::unique_ptr<GameObject>> objs;
    std::vector<std::vector<std::unique_ptr<Block>>> blocks;

    std::shared_ptr<ArrayInputProvider> m_netprov;
    UDPpacket *m_packet_send, *m_packet_recv;
    
public:
    GameStatePlaying(Game &game, const std::string &lvl);
    ~GameStatePlaying();

    void begin(float deltaTime);

    void draw(SDL_Renderer *rnd);

    bool has_block(float x, float y);

    Game& get_game();

    inline const static std::string LEVEL_FOLDER = "level";
    const static int MAX_LVL_W = 500;
    const static int MAX_LVL_H = 100;
};