#include "RoomGenerator.h"

/*static*/ bool RoomGenerator::MakeSquareRoom(GameMap& gm, int x, int y, unsigned int size)
{
    if (RangeIsEmpty(gm, x, y, x + size - 1, y + size -1) && CornersAreWallOrEmpty(gm, x, y, size))
    {
        AddSquareRoomToMap(gm, x, y, size);
        return true;
    }
    else
    {
        return false;
    }
}

/*static*/ bool RoomGenerator::CornersAreWallOrEmpty(const GameMap &gm, int x, int y, unsigned int size)
{
    return TileIsWallOrEmpty(gm, x-1,y-1) &&
           TileIsWallOrEmpty(gm, x+size,y-1) &&
           TileIsWallOrEmpty(gm, x-1,y+size) &&
           TileIsWallOrEmpty(gm, x+size,y+size);
}

/*static*/ bool RoomGenerator::TileIsWallOrEmpty(const GameMap &gm, int x, int y)
{
    auto t = gm.GetTile(x, y);
    return t == Tile::Wall || t == Tile::Empty;
}

/*static*/ bool RoomGenerator::RangeIsEmpty(GameMap& gm, int startX, int startY, int endX, int endY)
{
    for (int i = startX; i <= endX; ++i)
        for (int j = startY; j <= endY; ++j)
            if (gm.GetTile(i, j) != Tile::Empty)
                return false;

    return true;
}

/*static*/ void RoomGenerator::AddSquareRoomToMap(GameMap& gm, int x, int y, unsigned int size)
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
    {
        if (gm.GetTile(i, y) == Tile::Empty)
            gm.SetTile(i, y, t);
    }
}

/*static*/ void RoomGenerator::MakeColumn(GameMap& gm, int startY, int endY, int x, Tile t)
{
    for (int j = startY; j <= endY; ++j)
    {
        if (gm.GetTile(x, j) == Tile::Empty)
            gm.SetTile(x, j, t);
    }
}
