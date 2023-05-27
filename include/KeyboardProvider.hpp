
#pragma once

#include "interfaces/InputProvider.hpp"

class KeyboardProvider : public InputProvider
{
public:
    KeyboardProvider();

    void check_input()
};