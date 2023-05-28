#include "Brick.hpp"

#include "Game.hpp"
#include "GameStatePlaying.hpp"

Brick::Brick(GameStatePlaying &game_state, BrickType type, BrickStyle style, int remaining) : Block(game_state)
{
    m_remaining = remaining;
    m_type = type;
    m_style = style;

    Game &game = game_state.get_game();
    //регистрация анимаций
    add_animation(ANIM_IDLE, Animation(game.get_texture("brick.png"), 1));
    add_animation(ANIM_QUESTION, Animation(game.get_texture("brick_question.png"), 4).set_time_per_tick(QUESTION_FLASH_TIME));
    add_animation(ANIM_HIT, Animation(game.get_texture("brick_hit.png"), 1));
    //выбор анимации
    if (m_style == BrickStyle::Question)
        set_animation(ANIM_QUESTION);
}

void Brick::hit()
{
}

void Brick::draw(SDL_Renderer *rnd)
{
    if (m_style == BrickStyle::Hidden && !m_hit)
        return;
    else
        Block::draw(rnd);
}
