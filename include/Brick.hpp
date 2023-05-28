
#pragma once

#include "Block.hpp"

struct SDL_Renderer;

//виды блока
enum class BrickType
{
    Usual,
    Mushroomy,
    Coiny
};

//стиль отображения блока
enum class BrickStyle
{
    None,
    Question,
    Hidden
};

class Brick : public Block
{
private:
    //сколько ударов еще может получить блок
    int m_remaining;
    //свойства блока
    BrickType m_type;
    BrickStyle m_style;
    //ударили ли блок?
    bool m_hit = false;

public:
    Brick(GameStatePlaying &game_state, BrickType type = BrickType::Usual, BrickStyle style = BrickStyle::None, int remaining = 0);

    inline const static std::string ANIM_QUESTION = "question";
    inline const static std::string ANIM_HIT = "hit";
    //скорость анимации для значка "?"
    constexpr static float QUESTION_FLASH_TIME = 300;

    void hit();

    void draw(SDL_Renderer *rnd);
};