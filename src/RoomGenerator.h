#include "GameMap.h"

class RoomGenerator
{
public:
    static bool MakeSquareRoom(GameMap& gm, int x, int y, unsigned int size);
private:
    static void AddSquareRoomToMap(GameMap& gm, int x, int y, unsigned int size);
    static bool CornersAreWallOrEmpty(const GameMap& gm, int x, int y, unsigned int size);
    static bool TileIsWallOrEmpty(const GameMap& gm, int x, int y);
    static void MakeRow(GameMap& gm, int startX, int endX, int y, Tile t);
    static void MakeColumn(GameMap& gm, int startY, int endY, int x, Tile t);
    static bool RangeIsEmpty(GameMap& gm, int startX, int startY, int endX, int endY);
};
