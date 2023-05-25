
#pragma once

#include <string>

#include "Window.hpp"

class Game
{
private:
    std::unique_ptr<Window> window;

public:
    Game();
    void run();
    
};