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

TEST(GameMap, 2x2MapReturnsCorrectTiles)
{
    GameMap gMap{{Tile::Floor, Tile::Floor},
                 {Tile::Floor, Tile::Wall}};
    ASSERT_EQ(Tile::Floor, gMap.GetTile(0,0));
    ASSERT_EQ(Tile::Floor, gMap.GetTile(0,1));
    ASSERT_EQ(Tile::Floor, gMap.GetTile(1,0));
    ASSERT_EQ(Tile::Wall , gMap.GetTile(1,1));
}

TEST(GameMap, RequestingTileOffTheMapReturnsEmptyTile)
{
    GameMap gMap{{Tile::Floor, Tile::Floor},
                 {Tile::Floor, Tile::Wall}};
    ASSERT_EQ(Tile::Empty, gMap.GetTile(-1,-2));
    ASSERT_EQ(Tile::Empty, gMap.GetTile(2,0));

}
