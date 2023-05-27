#include "GameObject.hpp"

#include <SDL2/SDL_rect.h>

GameObject::GameObject(GameStatePlaying &game_state) : m_game_state(game_state)
{

}

GameObject::~GameObject()
{
}

Animation &GameObject::get_current_animation()
{
    return m_anims.find(m_cur_anim)->second;
}

void GameObject::add_animation(const std::string &name, Animation anim)
{
    m_anims.emplace(name, anim);
}

void GameObject::set_animation(const std::string &name)
{
    m_cur_anim = name;
}

void GameObject::set_pos(float x, float y)
{
    this->x = x;
    this->y = y;
}

void GameObject::update(float dt)
{
    Animation &anim = get_current_animation();
    float tpp = anim.get_time_per_tick();
    m_anim_tick += dt;
    if (m_anim_tick > tpp)
    {
        anim.advance();
        m_anim_tick -= tpp;
    }
}

void GameObject::draw(SDL_Renderer *rnd)
{
    Animation anim = get_current_animation();
    SDL_Rect frame = anim.get_frame();
    SDL_FRect dest;
    dest.x = x;
    dest.y = y;
    dest.w = frame.w;
    dest.h = frame.h;
    SDL_RenderCopyExF(rnd, anim.get_texture(), &frame, &dest, 0, nullptr, m_flipped ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

bool GameObject::collides_with(GameObject &other)
{
    SDL_FRect ours = get_collider(), theirs = other.get_collider();
    return SDL_IntersectFRect(&ours, &theirs, nullptr);
}

bool GameObject::is_done()
{
    return m_done;
}

SDL_FRect GameObject::get_collider()
{
    SDL_FRect col;
    col.x = x;
    col.y = y;
    col.w = m_col_w;
    col.h = m_col_h;
    return col;
}
