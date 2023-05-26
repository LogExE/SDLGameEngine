#include "Animation.hpp"

Animation::Animation(SDL_Texture *txtr, int size)
{
    m_txtr = txtr;
    m_size = size;
    int w, h;
    SDL_QueryTexture(m_txtr, nullptr, nullptr, &w, &h);
    m_frm_h = h;
    m_frm_w = w / size;
}

void Animation::set_time_per_tick(float time)
{
    m_timeptick = time;
}

float Animation::get_time_per_tick()
{
    return m_timeptick;
}

void Animation::advance()
{
    m_cur_frame = (m_cur_frame + 1) % m_size;
}

SDL_Texture *Animation::get_texture()
{
    return m_txtr;
}

SDL_Rect Animation::get_frame()
{
    SDL_Rect frm;
    frm.x = m_frm_w * m_cur_frame;
    frm.y = 0;
    frm.w = m_frm_w;
    frm.h = m_frm_h;
    return frm;
}
