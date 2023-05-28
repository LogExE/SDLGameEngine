#pragma once

#include <memory>

#include "GameObject.hpp"

class InputProvider;
class PlayerState;

class Player : public GameObject
{
private:
    std::shared_ptr<InputProvider> m_input;
    int m_score = 0;
    int m_lives = START_LIVES;
    float spawn_x, spawn_y;

public:
    Player(GameStatePlaying &game_state, float x, float y);
    void set_input(std::shared_ptr<InputProvider> provider);

    std::unique_ptr<PlayerState> m_state;
    void change_state(std::unique_ptr<PlayerState> state);
    void reset_state();

    bool brick_left_col();
    bool brick_right_col();
    bool brick_down_col();
    bool brick_up_col();

    bool is_player();

    void update(float dt);
    void decrease_lifes();

    inline static const std::string ANIM_WALK = "walk",
                                    ANIM_JUMP = "jump",
                                    ANIM_DEAD = "dead";
    const static int START_LIVES = 3;
    constexpr static float JMP_TIME = 500;
    constexpr static float COL_W = 16;
    constexpr static float COL_H = 13;
    friend class PlayerStateDef;
    friend class PlayerStateJump;
    friend class PlayerStateDead;
};