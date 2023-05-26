
#pragma once

#include "Game.hpp"
#include "interfaces/Drawable.hpp"
#include "Animation.hpp"

class GameObject : public Drawable
{
protected:
    float x = 0, y = 0;
    std::map<std::string, Animation> m_anims;
    std::string m_cur_anim = ANIM_IDLE;
    float m_anim_tick = 0;
    bool m_flipped = false;
    Animation& get_current_animation()
    {
        return m_anims.find(m_cur_anim)->second;
    }
public:
    GameObject() {}
    virtual ~GameObject() {};

    void add_animation(const std::string &name, Animation anim)
    {
        m_anims.emplace(name, anim);
    }
    void set_animation(const std::string &name)
    {
        m_cur_anim = name;
    }
    void set_pos(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
    virtual void update(float dt) 
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
    void draw(SDL_Renderer *rnd)
    {
        Animation anim = get_current_animation();
        SDL_Rect frame = anim.get_frame();
        SDL_FRect dest;
        dest.x = x;
        dest.y = y;
        dest.w = frame.w;
        dest.h = frame.h;
        SDL_RenderCopyExF(rnd, anim.get_texture(), &frame, &dest, 0, nullptr, m_flipped ? SDL_FLIP_VERTICAL : SDL_FLIP_NONE);
    }

    inline const static std::string ANIM_IDLE = "idle";
};