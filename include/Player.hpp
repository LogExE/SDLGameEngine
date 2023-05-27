#pragma once

#include "GameObject.hpp"

#include <memory>

class InputProvider;

class Player : public GameObject
{
private:
    bool m_grounded = false;
    bool m_big = false;
    bool m_invincible = false;
    int m_score = 0;
    std::shared_ptr<InputProvider> m_input;
    float xsp, ysp;
    int lives = START_LIVES;

public:
    Player(GameStatePlaying &game_state);
    void set_input(std::shared_ptr<InputProvider> provider);

    void update(float dt);

    constexpr static float X_ACC = 0.0002;
    constexpr static float X_DEC = 0.01;
    constexpr static float Y_ACC = 0.02;
    constexpr static float MAX_XSPEED = 0.1;
    constexpr static float MAX_YSPEED = 0.3;
    // TODO: make running/walking

    inline static const std::string ANIM_WALK = "walk",
                                    ANIM_JUMP = "jump";
    const static int START_LIVES = 3;
};