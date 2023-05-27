
#pragma once

#include "interfaces/InputProvider.hpp"

class KeyboardProvider : public InputProvider
{
private:
    const Uint8 *keys;
public:
    KeyboardProvider();
    bool check_input(Input inp);
};