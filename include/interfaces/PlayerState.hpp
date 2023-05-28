
#pragma once

class Player;

class PlayerState
{
protected:
    //экземпляр объекта игрока
    Player &m_plr;
public:
    PlayerState(Player &plr);
    virtual ~PlayerState();

    //метод обновления состояния
    virtual void update(float dt) = 0;
};
