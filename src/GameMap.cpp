#include "GameMap.h"

GameMap::GameMap() : m_Map(Tile::Empty)
{
}

GameMap::GameMap(Tile t) : m_Map(t)
{
}

Tile GameMap::GetTile(int x, int y)
{
    return m_Map;
}
