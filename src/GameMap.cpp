#include "GameMap.h"
#include <stdexcept>

GameMap::GameMap(std::initializer_list<std::initializer_list<Tile>> iListTiles) :
    m_MinX{0},
    m_MaxX{0},
    m_MinY{0},
    m_MaxY{0}
{
    SetMap(iListTiles);
}

void GameMap::SetMap(std::initializer_list<std::initializer_list<Tile>> iListTiles)
{
    m_Map.clear();
    m_MaxX = 0;
    m_MaxY = 0;
    
    int row = 0;
    for (auto rowList : iListTiles)
    {
        int column = 0;
        for (auto tile : rowList)
        {
            m_Map[Point(column, row)] = tile;
            ++column;
        }
        m_MaxX = std::max(m_MaxX, column-1);
        ++row;
    }
    m_MaxY = row-1;
}

void GameMap::SetTile(Point point, Tile tile)
{
    m_Map[point] = tile;
}

Tile GameMap::GetTile(Point point) const
{
    auto tile = m_Map.find(point);
    if (tile != m_Map.end())
        return tile->second;
    else
        return Tile::Empty;
}

int GameMap::GetMinX() const {return m_MinX;}
int GameMap::GetMaxX() const {return m_MaxX;}
int GameMap::GetMinY() const {return m_MinY;}
int GameMap::GetMaxY() const {return m_MaxY;}
