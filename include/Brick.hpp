
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
    bool hit = false;

public:
    Brick(GameStatePlaying &game_state, BrickType type = BrickType::Usual, BrickStyle style = BrickStyle::None, int remaining = 0);

    inline const static std::string ANIM_QUESTION = "question";
    inline const static std::string ANIM_HIT = "hit";

    void collide_with(GameObject &obj);

    void draw(SDL_Renderer *rnd);
};