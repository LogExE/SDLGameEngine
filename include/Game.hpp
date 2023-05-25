
#pragma once

#include <string>

#include "Graphics.hpp"

class Game
{
private:
    std::string m_window_title;
    //Graphics graphics;

public:
    Game();
    void run();
    void change_title(const std::string &new_title);
 
};