#include "gmock/gmock.h"
#include "GameMap.h"

using namespace ::testing;

class AGameMap: public Test
{
public:
    GameMap gMap;

    AGameMap() :
        gMap{{Tile::Floor, Tile::Floor},
             {Tile::Wall,  Tile::Floor},
             {Tile::Floor, Tile::Wall }}
    {}
};

TEST_F(AGameMap, WhenEmptyReturnsEmptyTile)
{
     GameMap gMap{{}};
     ASSERT_EQ(Tile::Empty, gMap.GetTile(0,0));
}

TEST_F(AGameMap, WithASingleTileReturnsThatTile)
{
    GameMap gMap{{Tile::Floor}};
    ASSERT_EQ(Tile::Floor, gMap.GetTile(0,0));
}

TEST_F(AGameMap, ReturnsCorrectTiles)
{
    ASSERT_EQ(Tile::Floor, gMap.GetTile(0,0));
    ASSERT_EQ(Tile::Floor, gMap.GetTile(1,0));
    ASSERT_EQ(Tile::Wall , gMap.GetTile(0,1));
    ASSERT_EQ(Tile::Floor, gMap.GetTile(1,1));
    ASSERT_EQ(Tile::Floor, gMap.GetTile(0,2));
    ASSERT_EQ(Tile::Wall , gMap.GetTile(1,2));
}

TEST_F(AGameMap, ReturnsEmptyTileForRequestsOffTheMap)
{
    ASSERT_EQ(Tile::Empty, gMap.GetTile(-1, 0));
    ASSERT_EQ(Tile::Empty, gMap.GetTile( 0,-1));
    ASSERT_EQ(Tile::Empty, gMap.GetTile( 1, 3));
    ASSERT_EQ(Tile::Empty, gMap.GetTile( 2, 2));
}
