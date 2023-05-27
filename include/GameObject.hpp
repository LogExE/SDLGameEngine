
#pragma once

#include <map>
#include <string>

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
    Animation& get_current_animation();
public:
    GameObject();
    virtual ~GameObject();

    void add_animation(const std::string &name, Animation anim);
    void set_animation(const std::string &name);
    void set_pos(float x, float y);
    virtual void update(float dt);
    void draw(SDL_Renderer *rnd);

    inline const static std::string ANIM_IDLE = "idle";
};