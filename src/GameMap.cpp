#include "GameMap.h"

GameMap::GameMap(std::initializer_list<std::initializer_list<Tile>> iListTiles) :
    m_MinX{0},
    m_MaxX{-1},
    m_MinY{0},
    m_MaxY{-1}
{
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

Tile GameMap::GetTile(int x, int y)
{
    if (x >= m_MinX && x <= m_MaxX && y >= m_MinY && y <= m_MaxY)
        return m_Map[y][x];
    else
        return Tile::Empty;
}
