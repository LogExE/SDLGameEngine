
#pragma once

#include <SDL2/SDL.h>

class Animation
{
private:
    //текстура со всеми кадрами анимации
    SDL_Texture *m_txtr;
    //параметры кадра
    int m_frm_w, m_frm_h;
    //число кадров
    int m_size;
    //текущий кадр
    int m_cur_frame = 0;
    //столько длится один кадр
    int m_timeptick = -1;

public:
    Animation(SDL_Texture *txtr, int size);

    //установка и получение длительности кадра
    Animation &set_time_per_tick(float time);
    float get_time_per_tick();

    //обновление анимации
    void advance();
    //для извлечения текстуры и кадра
    SDL_Texture *get_texture();
    SDL_Rect get_frame();
};