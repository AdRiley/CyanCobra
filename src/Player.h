#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
    int m_X;
    int m_Y;
public:
    Player(int x, int y);
    int GetX() const;
    int GetY() const;
    void SetPosition(int x, int y);
};

#endif
