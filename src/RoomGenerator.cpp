#include "RoomGenerator.h"

/*static*/ void RoomGenerator::MakeSquareRoom(GameMap& gm, int x, int y, unsigned int size)
{
    MakeRow(gm, x - 1, x + size, y - 1, Tile::Wall);
    for (int j = y; j < y + static_cast<int>(size); ++j)
        MakeRow(gm, x, x + size - 1, j, Tile::Floor);
    MakeRow(gm, x - 1, x + size, y + size, Tile::Wall);

    MakeColumn(gm, y, y + size - 1, x - 1, Tile::Wall);
    MakeColumn(gm, y, y + size - 1, x + size, Tile::Wall);
}

/*static*/ void RoomGenerator::MakeRow(GameMap& gm, int startX, int endX, int y, Tile t)
{
    for (int i = startX; i <= endX; ++i)
        gm.SetTile(i, y, t);
}

/*static*/ void RoomGenerator::MakeColumn(GameMap& gm, int startY, int endY, int x, Tile t)
{
    for (int j = startY; j <= endY; ++j)
        gm.SetTile(x, j, t);
}
