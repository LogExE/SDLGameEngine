
#pragma once

#include <SDL2/SDL.h>

class Animation
{
private:
    SDL_Texture* m_txtr;
    int m_frm_w, m_frm_h;
    int m_size;
    int m_cur_frame = 0;
    bool m_flipped;
public:
    Animation(SDL_Texture *txtr, int size);

    void advance();
    SDL_Texture* get_texture();
    SDL_Rect get_frame();
};