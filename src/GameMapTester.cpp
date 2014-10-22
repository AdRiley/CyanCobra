#include "gmock/gmock.h"
#include "GameMap.h"

using namespace ::testing;

TEST(GameMap, EmptyMapReturnsEmptyTile)
{
    GameMap gMap;
    ASSERT_EQ(Tile::Empty, gMap.GetTile(0,0));
}

TEST(GameMap, MapWithSingleTileReturnsThatTile)
{
    GameMap gMap{Tile::Floor};
    ASSERT_EQ(Tile::Floor, gMap.GetTile(0,0));
}
