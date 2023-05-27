
#pragma once

#include <vector>
#include <string>
#include <memory>

#include "interfaces/GameState.hpp"

class GameObject;
class InputProvider;

class GameStatePlaying : public GameState
{
private:
    std::vector<std::unique_ptr<GameObject>> objs;
    int lives = START_LIVES;
    std::shared_ptr<InputProvider> m_keyboard;
public:
    GameStatePlaying(Game &game, const std::string &lvl);

    void begin(float deltaTime);

    void draw(SDL_Renderer *rnd);

    inline const static std::string LEVEL_FOLDER = "level";
    const static int START_LIVES = 3;
};