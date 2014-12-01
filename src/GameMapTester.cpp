#include "gmock/gmock.h"
#include "GameMap.h"
#include <stdexcept>

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

TEST_F(AGameMap, ReturnsItsMinX)
{
    ASSERT_THAT(0, Eq(gMap.GetMinX()));
}

TEST_F(AGameMap, ReturnsItsMaxX)
{
    ASSERT_THAT(1, Eq(gMap.GetMaxX()));
}

TEST_F(AGameMap, ReturnsItsMinY)
{
    ASSERT_THAT(0, Eq(gMap.GetMinY()));
}

TEST_F(AGameMap, ReturnsItsMaxY)
{
    ASSERT_THAT(2, Eq(gMap.GetMaxY()));
}

TEST_F(AGameMap, CanBeSetToADifferentMap)
{
    gMap.SetMap({{Tile::Floor}});
    ASSERT_THAT(0, Eq(gMap.GetMinX()));
    ASSERT_THAT(0, Eq(gMap.GetMinY()));
    ASSERT_THAT(0, Eq(gMap.GetMaxX()));
    ASSERT_THAT(0, Eq(gMap.GetMaxY()));
    ASSERT_THAT(Tile::Floor, Eq(gMap.GetTile(0,0)));
}

TEST_F(AGameMap, CanSetASingleTile)
{
    gMap.SetTile(0, 0, Tile::OpenDoor);
    ASSERT_THAT(Tile::OpenDoor, Eq(gMap.GetTile(0, 0)));
}

TEST_F(AGameMap, ThrowsIfTryingToSetATileOffTheMap)
{
    ASSERT_THROW(gMap.SetTile(5, 5, Tile::Floor), std::out_of_range);
}

TEST_F(AGameMap, CanBeConstructedAsAnEmptyMap)
{
    GameMap gMap{1, 2};
    ASSERT_EQ(Tile::Empty, gMap.GetTile(0,0));
    ASSERT_EQ(Tile::Empty, gMap.GetTile(1,0));
    ASSERT_EQ(Tile::Empty, gMap.GetTile(0,1));
    ASSERT_EQ(Tile::Empty, gMap.GetTile(1,1));
    ASSERT_EQ(Tile::Empty, gMap.GetTile(0,2));
    ASSERT_EQ(Tile::Empty, gMap.GetTile(1,2));
    ASSERT_THAT(0, Eq(gMap.GetMinX()));
    ASSERT_THAT(1, Eq(gMap.GetMaxX()));
    ASSERT_THAT(0, Eq(gMap.GetMinY()));
    ASSERT_THAT(2, Eq(gMap.GetMaxY()));
}


