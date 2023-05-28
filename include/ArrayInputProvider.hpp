
#pragma once

#include "interfaces/InputProvider.hpp"

class ArrayInputProvider : public InputProvider
{
private:
    int m_array = 0;
public:
    ArrayInputProvider();
    void set_array(int array);

    bool check_input(Input inp);
};