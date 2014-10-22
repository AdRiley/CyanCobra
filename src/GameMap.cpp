#include "GameMap.h"

GameMap::GameMap() : m_Map({{Tile::Empty}})
{
}

GameMap::GameMap(Tile t) : m_Map({{t}})
{
}

GameMap::GameMap(std::initializer_list<std::initializer_list<Tile>> iListTiles)
{
    int r = 0;
    for (auto sl : iListTiles)
    {
        m_Map.resize(m_Map.size()+1);
        for (auto i :sl)
            m_Map[r].push_back(i);
        ++r;
    }
}

Tile GameMap::GetTile(int x, int y)
{
    return m_Map[x][y];
}
