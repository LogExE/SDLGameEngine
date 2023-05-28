
#pragma once

#include "interfaces/InputProvider.hpp"

class EmptyInputProvider : public InputProvider
{
public:
    EmptyInputProvider() {}

    //любой ввод всегда в состоянии "не нажат"
    bool check_input(Input inp) { return false; }
};
