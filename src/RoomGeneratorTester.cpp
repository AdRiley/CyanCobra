#include "gmock/gmock.h"
#include "GameMap.h"
#include "RoomGenerator.h"

using namespace ::testing;

TEST(ARoomGenerator, GeneratesA1X1Room)
{
    GameMap gm{2, 2};
    RoomGenerator::MakeSquareRoom(gm, 1, 1, 1);
    ASSERT_THAT(Tile::Floor, Eq(gm.GetTile(1, 1)));
    ASSERT_THAT(Tile::Wall, Eq(gm.GetTile(0, 0)));
    ASSERT_THAT(Tile::Wall, Eq(gm.GetTile(0, 1)));
    ASSERT_THAT(Tile::Wall, Eq(gm.GetTile(0, 2)));
    ASSERT_THAT(Tile::Wall, Eq(gm.GetTile(1, 0)));
    ASSERT_THAT(Tile::Wall, Eq(gm.GetTile(1, 2)));
    ASSERT_THAT(Tile::Wall, Eq(gm.GetTile(2, 0)));
    ASSERT_THAT(Tile::Wall, Eq(gm.GetTile(2, 1)));
    ASSERT_THAT(Tile::Wall, Eq(gm.GetTile(2, 2)));
}

