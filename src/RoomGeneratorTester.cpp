#include "test.h"
#include "GameMap.h"
#include "RoomGenerator.h"


class ARoomGenerator
{
public:
    GameMap gm;
    ARoomGenerator() : gm {3,3}
    {}

    void RequireRangeIsTile(Tile t, const GameMap& gm, int startX, int startY, int endX, int endY)
    {
        for (int i = startX; i <= endX; ++i)
            for (int j = startY; j <= endY; ++j)
                REQUIRE(gm.GetTile({i, j}) == t);
    }
};

TEST_CASE_METHOD(ARoomGenerator, "Generates A 1X1 Room")
{
    RoomGenerator::MakeSquareRoom(gm, 1, 1, 1);
    REQUIRE(gm.GetTile({1, 1}) == Tile::Floor);
    RequireRangeIsTile(Tile::Wall, gm, 0, 0, 0, 2);
    REQUIRE(gm.GetTile({1, 0}) == Tile::Wall);
    REQUIRE(gm.GetTile({1, 2}) == Tile::Wall);
    RequireRangeIsTile(Tile::Wall, gm, 2, 0, 2, 2);
}

TEST_CASE_METHOD(ARoomGenerator, "Generates A 2x2 Room")
{
    RoomGenerator::MakeSquareRoom(gm, 1, 1, 2);
    RequireRangeIsTile(Tile::Floor, gm, 1, 1, 2, 2);
    RequireRangeIsTile(Tile::Wall, gm, 0, 0, 0, 3);
    RequireRangeIsTile(Tile::Wall, gm, 3, 0, 3, 3);
    RequireRangeIsTile(Tile::Wall, gm, 0, 1, 0, 2);
    RequireRangeIsTile(Tile::Wall, gm, 3, 1, 3, 2);
}

TEST_CASE_METHOD(ARoomGenerator, "Doesnt Place A Square Room If There Is A Wall In The Way")
{ 
    gm.SetTile({2, 2}, Tile::Wall);
    REQUIRE(RoomGenerator::MakeSquareRoom(gm, 1, 1, 2) == false);
    REQUIRE(gm.GetTile({2,2}) == Tile::Wall);
    gm.SetTile({2, 2}, Tile::Empty);
    RequireRangeIsTile(Tile::Empty, gm, 0, 0, 3, 3);
}

TEST_CASE_METHOD(ARoomGenerator, "Doesnt Place A Square Room If There Is A Open Door In An External Corner")
{
    gm.SetTile({3, 3}, Tile::OpenDoor);
    REQUIRE(RoomGenerator::MakeSquareRoom(gm, 1, 1, 2) == false);
    REQUIRE(gm.GetTile({3,3}) == Tile::OpenDoor);
    gm.SetTile({3, 3}, Tile::Empty);
    RequireRangeIsTile(Tile::Empty, gm, 0, 0, 3, 3);
}

TEST_CASE_METHOD(ARoomGenerator, "Doesnt Place A Square Room If There Is A Closed Door In An External Corner")
{
    gm.SetTile({0, 3}, Tile::ClosedDoor);
    REQUIRE(RoomGenerator::MakeSquareRoom(gm, 1, 1, 2) == false);
    REQUIRE(gm.GetTile({0,3}) == Tile::ClosedDoor);
    gm.SetTile({0, 3}, Tile::Empty);
    RequireRangeIsTile(Tile::Empty, gm, 0, 0, 3, 3);
}

TEST_CASE_METHOD(ARoomGenerator, "If There Is A Door In A Wall Location The Door Remains")
{
    gm.SetTile({0, 1}, Tile::ClosedDoor);
    REQUIRE(RoomGenerator::MakeSquareRoom(gm, 1, 1, 2));
    REQUIRE(gm.GetTile({0,1}) == Tile::ClosedDoor);
}

