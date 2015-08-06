#include "Player.h"

Player::Player(Point location) :
    m_Location(location)
{}

Point Player::GetLocation() const
{
    return m_Location;
}

void Player::SetLocation(Point location)
{
    m_Location= location;
}
