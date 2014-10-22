#include "gmock/gmock.h"
#include "GameMap.h"

using namespace ::testing;

TEST(GameMap, EmptyMapReturnsEmptyLocation)
{
    GameMap gMap;
    ASSERT_EQ(Tile::Empty, gMap.GetTile(0,0));
}
