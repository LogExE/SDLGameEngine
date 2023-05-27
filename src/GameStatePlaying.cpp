#include "GameStatePlaying.hpp"

#include "GameObject.hpp"
#include "Player.hpp"
#include "interfaces/PlayerState.hpp"
#include "Block.hpp"
#include "Brick.hpp"
#include "GroundBlock.hpp"
#include "Game.hpp"
#include "ArrayInputProvider.hpp"

GameStatePlaying::GameStatePlaying(Game &game, const std::string &lvl) : GameState(game)
{
    blocks.resize(MAX_LVL_H);
    for (int i = 0; i < MAX_LVL_H; ++i)
        blocks[i].resize(MAX_LVL_W);
    for (int i = 0; i < 20; ++i)
    {
        auto new_block = std::make_unique<GroundBlock>(*this);
        new_block->set_pos(i * Block::SIZE, 100);
        blocks[100 / Block::SIZE][i] = std::move(new_block);
    }
    for (int i = 0; i < 5; ++i)
    {
        auto new_block = std::make_unique<Brick>(*this, BrickType::Usual, BrickStyle::None);
        new_block->set_pos(i * Block::SIZE, 50);
        blocks[50 / Block::SIZE][i] = std::move(new_block);
    }
    for (int i = 5; i < 10; ++i)
    {
        auto new_block = std::make_unique<Brick>(*this, BrickType::Coiny, BrickStyle::Question);
        new_block->set_pos(i * Block::SIZE, 50);
        blocks[50 / Block::SIZE][i] = std::move(new_block);
    }
    auto plr = std::make_unique<Player>(*this, 10, 10);
    plr->set_input(m_game.get_keyboard());
    objs.push_back(std::move(plr));
    auto plr2 = std::make_unique<Player>(*this, 20, 10);
    m_netprov = std::make_shared<ArrayInputProvider>();
    plr2->set_input(m_netprov);
    objs.push_back(std::move(plr2));

    m_packet_recv = SDLNet_AllocPacket(1);
    m_packet_send = SDLNet_AllocPacket(1);
}

GameStatePlaying::~GameStatePlaying()
{
    SDLNet_FreePacket(m_packet_recv);
    SDLNet_FreePacket(m_packet_send);
}

void GameStatePlaying::begin(float deltaTime)
{
    std::vector<std::unique_ptr<GameObject>> objs_copy;
    for (auto &obj : objs)
        obj->update(deltaTime);

    for (auto &blks : blocks)
        for (auto &blk : blks)
            if (blk)
                blk->update(deltaTime);

    auto enckeys = m_game.get_keyboard();
    Uint8 data = 0;
    for (auto inp : {Input::Left, Input::Down, Input::Left, Input::Right, Input::Jump, Input::Action})
    {
        data += enckeys->check_input(inp);
        data <<= 1;
    }
    data >>= 1;
    m_packet_send->data = &data;
    SDLNet_UDP_Send(m_game.get_socket(), m_game.get_chan(), m_packet_send);
    if (SDLNet_UDP_Recv(m_game.get_socket(), m_packet_recv) != 0)
        m_netprov->set_array(*m_packet_recv->data);
}

void GameStatePlaying::draw(SDL_Renderer *rnd)
{
    SDL_SetRenderDrawColor(rnd, 92, 148, 252, 255);
    SDL_RenderClear(rnd);

    for (auto &obj : objs)
        obj->draw(rnd);
    for (auto &blks : blocks)
        for (auto &blk : blks)
            if (blk)
                blk->draw(rnd);

    SDL_RenderPresent(rnd);
}

bool GameStatePlaying::has_block(float x, float y)
{
    return x >= 0 && y >= 0 && blocks[round(y) / Block::SIZE][round(x) / Block::SIZE] != nullptr;
}

Game &GameStatePlaying::get_game()
{
    return m_game;
}
