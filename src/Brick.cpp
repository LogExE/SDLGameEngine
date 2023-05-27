#include "Brick.hpp"

#include "Game.hpp"
#include "GameStatePlaying.hpp"

Brick::Brick(GameStatePlaying &game_state, BrickType type, BrickStyle style, int remaining) : Block(game_state)
{
    m_remaining = remaining;
    m_type = type;
    m_style = style;

    Game &game = game_state.get_game();
    add_animation(ANIM_IDLE, Animation(game.get_texture("brick.png"), 1));
    add_animation(ANIM_QUESTION, Animation(game.get_texture("question.png"), 3));
    add_animation(ANIM_HIT, Animation(game.get_texture("brick_hit.png"), 1));
    if (m_style == BrickStyle::Question)
        set_animation(ANIM_QUESTION);
}

void Brick::collide_with(GameObject &obj)
{
    
}

void Brick::draw(SDL_Renderer *rnd)
{
    if (m_style == BrickStyle::Hidden && !hit)
        return;
    else Block::draw(rnd);
}
