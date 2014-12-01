#include "GameMap.h"
#include <stdexcept>

GameMap::GameMap(std::initializer_list<std::initializer_list<Tile>> iListTiles) :
    m_MinX{0},
    m_MaxX{-1},
    m_MinY{0},
    m_MaxY{-1}
{
    SetMap(iListTiles);
}

GameMap::GameMap(unsigned int x, unsigned int y) :
    m_MinX{0},
    m_MaxX{x},
    m_MinY{0},
    m_MaxY{y}
{
    for (int i = 0; i <= y; ++i)
    {
        m_Map.resize(m_Map.size()+1);
        for (int j = 0; j <= x; ++j)
            m_Map[i].push_back(Tile::Empty);
    }
}

void GameMap::SetMap(std::initializer_list<std::initializer_list<Tile>> iListTiles)
{
    m_Map.clear();
    int r = 0;
    for (auto sl : iListTiles)
    {
        m_Map.resize(m_Map.size()+1);
        for (auto i :sl)
            m_Map[r].push_back(i);
        ++r;
    }
    m_MaxY = m_Map.size()-1;
    if (m_Map.size() > 0)
        m_MaxX = m_Map[0].size()-1;
}

void GameMap::SetTile(int x, int y, Tile t)
{
    if (XYInBounds(x, y))
        m_Map[y][x] = t;
    else
        throw std::out_of_range{"Co-ordinates outside map range"};
}

Tile GameMap::GetTile(int x, int y) const
{
    if (XYInBounds(x, y))
        return m_Map[y][x];
    else
        return Tile::Empty;
}

bool GameMap::XYInBounds(int x, int y) const
{
    return x >= m_MinX && x <= m_MaxX && y >= m_MinY && y <= m_MaxY;
}

int GameMap::GetMinX() const {return m_MinX;}
int GameMap::GetMaxX() const {return m_MaxX;}
int GameMap::GetMinY() const {return m_MinY;}
int GameMap::GetMaxY() const {return m_MaxY;}
