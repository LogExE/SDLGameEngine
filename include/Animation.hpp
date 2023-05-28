
#pragma once

#include <SDL2/SDL.h>

class Animation
{
private:
    SDL_Texture *m_txtr;
    int m_frm_w, m_frm_h;
    int m_size;
    int m_cur_frame = 0;
    int m_timeptick = -1;

public:
    Animation(SDL_Texture *txtr, int size);

    Animation &set_time_per_tick(float time);
    float get_time_per_tick();

    void advance();
    SDL_Texture *get_texture();
    SDL_Rect get_frame();
};