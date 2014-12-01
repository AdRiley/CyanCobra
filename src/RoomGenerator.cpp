#include "RoomGenerator.h"

/*static*/ void RoomGenerator::MakeSquareRoom(GameMap& gm, int x, int y, unsigned int size)
{
    gm.SetTile(x, y, Tile::Floor);
    gm.SetTile(x-1, y-1, Tile::Wall);
    gm.SetTile(x-1, y, Tile::Wall);
    gm.SetTile(x-1, y+1, Tile::Wall);
    gm.SetTile(x, y-1, Tile::Wall);
    gm.SetTile(x, y+1, Tile::Wall);
    gm.SetTile(x+1, y-1, Tile::Wall);
    gm.SetTile(x+1, y, Tile::Wall);
    gm.SetTile(x+1, y+1, Tile::Wall);
}
