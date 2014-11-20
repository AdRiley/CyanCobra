#include "Player.h"

Player::Player(int x, int y) :
    m_X(x),
    m_Y(y)
{}

int Player::GetX() const
{
    return m_X;
}

int Player::GetY() const
{
    return m_Y;
}

void Player::SetPosition(int x, int y)
{
    m_X = x;
    m_Y = y;
}
