#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <vector>

enum class Tile
{
    Empty,
    Floor,
    Wall
};

class GameMap
{
private:
    std::vector<std::vector<Tile>> m_Map;
    int m_MinX;
    int m_MaxX;
    int m_MinY;
    int m_MaxY;
public:
    GameMap(std::initializer_list<std::initializer_list<Tile>> iListTiles);
    Tile GetTile(int x, int y) const;
    int GetMinX() const;
    int GetMaxX() const;
    int GetMinY() const;
    int GetMaxY() const;
};

#endif
