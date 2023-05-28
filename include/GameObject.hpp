
#pragma once

#include <map>
#include <string>

#include "interfaces/Drawable.hpp"
#include "Animation.hpp"

class GameStatePlaying;

class GameObject : public Drawable
{
protected:
    //позиция объекта в игровом мире
    float x = 0, y = 0;
    //физические размеры объекта
    float m_col_w = 0, m_col_h = 0;
    //текущая анимация
    std::string m_cur_anim = ANIM_IDLE;
    float m_anim_tick = 0;
    bool m_flipped = false;
    //если m_done == true, то объект нужно убрать из игрового мира
    bool m_done = false;
    //набор анимаций
    std::map<std::string, Animation> m_anims;
    //состояние игры
    GameStatePlaying &m_game_state;

public:
    GameObject(GameStatePlaying &game);
    virtual ~GameObject();

    //методы работы с анимацией
    Animation &get_current_animation();
    void add_animation(const std::string &name, Animation anim);
    void set_animation(const std::string &name);
    //установка новой позиции
    void set_pos(float x, float y);
    //обновление объекта с учетом прошедшего времени
    virtual void update(float dt);
    virtual void draw(SDL_Renderer *rnd);

    bool collides_with(GameObject &other);
    bool is_done();
    //является ли объект игроком
    virtual bool is_player();

    //получение прямоугольника для обработки столкновений
    SDL_FRect get_collider();

    inline const static std::string ANIM_IDLE = "idle";
};