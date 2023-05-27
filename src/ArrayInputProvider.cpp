#include "ArrayInputProvider.hpp"

ArrayInputProvider::ArrayInputProvider()
{
}

void ArrayInputProvider::set_array(int array)
{
    m_array = array;
}

bool ArrayInputProvider::check_input(Input inp)
{
    switch (inp)
    {
    case Input::Up:
        return m_array & 1;
        break;
    case Input::Down:
        return (m_array >> 1) & 1;
        break;
    case Input::Left:
        return (m_array >> 2) & 1;
        break;
    case Input::Right:
        return (m_array >> 3) & 1;
        break;
    case Input::Jump:
        return (m_array >> 4) & 1;
        break;
    case Input::Action:
        return (m_array >> 5) & 1;
        break;
    }
}
