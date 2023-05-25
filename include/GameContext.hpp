
#pragma once

#include <memory>

#include "Window.hpp"

//TODO: Audio, Networking and input....
class GameContext
{
protected:
    std::unique_ptr<Window> m_wnd;
public:
    GameContext() {}
    virtual ~GameContext() = 0;

    Window &get_window()
    {
        return *m_wnd;
    }
};