#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <map>
#include "Point.h"

enum class Tile
{
    Empty,
    Floor,
    Wall,
    Player,
    ClosedDoor,
    OpenDoor
};

class GameMap
{
private:
    std::map<Point, Tile> m_Map;
    int m_MinX;
    int m_MaxX;
    int m_MinY;
    int m_MaxY;
public:
    GameMap(std::initializer_list<std::initializer_list<Tile>> iListTiles);
    GameMap(unsigned int x, unsigned int y);
    void SetMap(std::initializer_list<std::initializer_list<Tile>> iListTiles);
    void SetTile(Point p, Tile t);
    Tile GetTile(Point p) const;
    int GetMinX() const;
    int GetMaxX() const;
    int GetMinY() const;
    int GetMaxY() const;
};

#endif
