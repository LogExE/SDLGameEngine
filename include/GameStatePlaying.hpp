
#pragma once

#include <vector>

#include "GameObject.hpp"
#include "interfaces/GameState.hpp"

class GameStatePlaying : public GameState
{
private:
    std::vector<GameObject> objs;
    int lives = START_LIVES;
public:
    GameStatePlaying(Game &game, const std::string &lvl);

    void begin();

    void draw();

    inline const static std::string LEVEL_FOLDER = "level";
    const static int START_LIVES = 3;
};