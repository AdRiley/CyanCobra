#include "GameMap.h"

class RoomGenerator
{
public:
    static void MakeSquareRoom(GameMap& gm, int x, int y, unsigned int size);
    static void MakeRow(GameMap& gm, int startX, int endX, int y, Tile t);
    static void MakeColumn(GameMap& gm, int startY, int endY, int x, Tile t);

};
