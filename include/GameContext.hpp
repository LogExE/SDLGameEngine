
#pragma once

#include <memory>

#include "Window.hpp"

//TODO: Audio, Networking and input....
class GameContext
{
protected:
    std::unique_ptr<Window> m_wnd;
    bool m_running = true;
public:
    GameContext() {}
    virtual ~GameContext() = 0;

    Window &get_window()
    {
        return *m_wnd;
    }
    bool is_running()
    {
        return m_running;
    }

    virtual void process_events() = 0;
    
};