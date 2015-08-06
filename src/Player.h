#ifndef PLAYER_H
#define PLAYER_H

#include "Point.h"

class Player
{
private:
    Point m_Location;
public:
    Player(Point location);
    Point GetLocation() const;
    void SetLocation(Point location);
};

#endif
