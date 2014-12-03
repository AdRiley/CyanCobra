#include "gmock/gmock.h"
#include "GameMap.h"
#include "RoomGenerator.h"

using namespace ::testing;

class ARoomGenerator : public Test
{
public:
    void AssertRangeIsTile(Tile t, const GameMap& gm, int startX, int startY, int endX, int endY)
    {
        for (int i = startX; i <= endX; ++i)
            for (int j = startY; j <= endY; ++j)
                ASSERT_THAT(t, Eq(gm.GetTile(i, j)));
    }
};

TEST_F(ARoomGenerator, GeneratesA1X1Room)
{
    GameMap gm{2, 2};
    RoomGenerator::MakeSquareRoom(gm, 1, 1, 1);
    ASSERT_THAT(Tile::Floor, Eq(gm.GetTile(1, 1)));
    AssertRangeIsTile(Tile::Wall, gm, 0, 0, 0, 2);
    ASSERT_THAT(Tile::Wall, Eq(gm.GetTile(1, 0)));
    ASSERT_THAT(Tile::Wall, Eq(gm.GetTile(1, 2)));
    AssertRangeIsTile(Tile::Wall, gm, 2, 0, 2, 2);
}

TEST_F(ARoomGenerator, GeneratesA2x2Room)
{
    GameMap gm{3, 3};
    RoomGenerator::MakeSquareRoom(gm, 1, 1, 2);
    AssertRangeIsTile(Tile::Floor, gm, 1, 1, 2, 2);
    AssertRangeIsTile(Tile::Wall, gm, 0, 0, 0, 3);
    AssertRangeIsTile(Tile::Wall, gm, 3, 0, 3, 3);
    AssertRangeIsTile(Tile::Wall, gm, 0, 1, 0, 2);
    AssertRangeIsTile(Tile::Wall, gm, 3, 1, 3, 2);
}

TEST_F(ARoomGenerator, DoesntPlaceASquareRoomIfThereIsAWallInTheWay)
{
    GameMap gm{3, 3};
    gm.SetTile(2, 2, Tile::Wall);
    ASSERT_FALSE(RoomGenerator::MakeSquareRoom(gm, 1, 1, 2));
    ASSERT_THAT(Tile::Wall, Eq(gm.GetTile(2,2)));
    gm.SetTile(2, 2, Tile::Empty);
    AssertRangeIsTile(Tile::Empty, gm, 0, 0, 3, 3);
}


