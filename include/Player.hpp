#pragma once

#include "GameObject.hpp"

#include <memory>

class InputProvider;

class Player : public GameObject
{
private:
    std::shared_ptr<InputProvider> m_input;
    bool m_grounded = false;
    bool m_big = false;
    bool m_invincible = false;
    
    int m_score = 0;
    int m_lives = START_LIVES;

    bool m_jumping = false;
    float m_jumptime = 0;

    float xsp, ysp;

public:
    Player(GameStatePlaying &game_state);
    void set_input(std::shared_ptr<InputProvider> provider);

    bool brick_left_col();
    bool brick_right_col();
    bool brick_down_col();
    bool brick_up_col();

    void update(float dt);

    constexpr static float X_ACC = 0.0002;
    constexpr static float X_DEC = 0.01;
    constexpr static float Y_ACC = 0.005;
    constexpr static float MAX_XSPEED = 0.1;
    constexpr static float MAX_YSPEED = 0.2;
    constexpr static float JMP_SPEED = 0.1;

    inline static const std::string ANIM_WALK = "walk",
                                    ANIM_JUMP = "jump";
    const static int START_LIVES = 3;
    constexpr static float JMP_TIME = 500;
};