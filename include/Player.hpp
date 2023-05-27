#pragma once

#include "GameObject.hpp"

class Game;
class InputProvider;

class Player : public GameObject
{
private:
    bool m_grounded = false;
    bool m_big = false;
    bool m_invincible = false;
    int m_score = 0;
public:
    Player(Game &game);
    void set_input(std::shared_ptr<InputProvider> provider);

    void update(float dt);

    constexpr static float MAX_XSPEED = 5;
    constexpr static float MAX_YSPEED = 10;

    inline static const std::string ANIM_WALK = "walk",
                                    ANIM_JUMP = "jump";
};