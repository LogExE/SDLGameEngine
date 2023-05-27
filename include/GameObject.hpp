
#pragma once

#include <map>
#include <string>

#include "interfaces/Drawable.hpp"
#include "Animation.hpp"

class GameStatePlaying;

class GameObject : public Drawable
{
protected:
    float x = 0, y = 0;
    float m_col_w = 0, m_col_h = 0;
    std::string m_cur_anim = ANIM_IDLE;
    float m_anim_tick = 0;
    bool m_flipped = false;
    bool m_done = false;
    std::map<std::string, Animation> m_anims;
    GameStatePlaying &m_game_state;
    
public:
    GameObject(GameStatePlaying &game);
    virtual ~GameObject();

    Animation& get_current_animation();
    void add_animation(const std::string &name, Animation anim);
    void set_animation(const std::string &name);
    void set_pos(float x, float y);
    virtual void update(float dt);
    virtual void draw(SDL_Renderer *rnd);

    bool collides_with(GameObject &other);
    bool is_done();
    virtual bool is_player();

    SDL_FRect get_collider();

    inline const static std::string ANIM_IDLE = "idle";
};