
#pragma once

#include "Block.hpp"

struct SDL_Renderer;

enum class BrickType
{
    Usual,
    Mushroomy,
    Coiny
};

enum class BrickStyle
{
    None,
    Question,
    Hidden
};

class Brick : public Block
{
private:
    int m_remaining;
    BrickType m_type;
    BrickStyle m_style;
    bool m_hit = false;

public:
    Brick(GameStatePlaying &game_state, BrickType type = BrickType::Usual, BrickStyle style = BrickStyle::None, int remaining = 0);

    inline const static std::string ANIM_QUESTION = "question";
    inline const static std::string ANIM_HIT = "hit";
    constexpr static float QUESTION_FLASH_TIME = 300;

    void hit();

    void draw(SDL_Renderer *rnd);
};