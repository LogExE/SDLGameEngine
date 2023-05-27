#pragma once

#include "GameObject.hpp"

#include <memory>

class Game;
class InputProvider;

class Player : public GameObject
{
private:
    bool m_grounded = false;
    bool m_big = false;
    bool m_invincible = false;
    int m_score = 0;
    std::shared_ptr<InputProvider> m_input;
public:
    Player(Game &game, std::shared_ptr<InputProvider> input);
    void set_input(std::shared_ptr<InputProvider> provider);

    void update(float dt);

    constexpr static float MAX_XSPEED = 0.2;
    constexpr static float MAX_YSPEED = 0.5;

    inline static const std::string ANIM_WALK = "walk",
                                    ANIM_JUMP = "jump";
};