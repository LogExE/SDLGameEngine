
#pragma once

#include "interfaces/InputProvider.hpp"

class EmptyInputProvider : public InputProvider
{
public:
    EmptyInputProvider() {}

    bool check_input(Input inp) { return false; }
};
