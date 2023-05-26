
#pragma once

#include <memory>

#include "Window.hpp"

//TODO: Audio, Networking and input....
class GameContext
{
protected:
    Window m_wnd;
    bool m_running = true;
public:
    GameContext();
    ~GameContext();

    Window &get_window()
    {
        return m_wnd;
    }
    bool is_running()
    {
        return m_running;
    }

    void process_events();
};